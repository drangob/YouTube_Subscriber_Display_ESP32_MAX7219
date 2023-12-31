#include "youtube_stats.h"

bool YouTubeStats::fetch() {
    bool success = true;
    HTTPClient http;
    http.begin("https://www.googleapis.com/youtube/v3/channels?part=statistics&id=" + String(YT_CHANNEL_ID) + "&key=" + String(GOOGLE_API_KEY));
    int httpCode = http.GET();
    if (httpCode == 200) {
        String payload = http.getString();
        StaticJsonDocument<1024> doc;
        DeserializationError jsonError = deserializeJson(doc, payload);
        if (jsonError) {
            error = "deserializeJson() failed: " + String(jsonError.c_str());
            success = false;
        } else {
            subscriberCount = atoi(doc["items"][0]["statistics"]["subscriberCount"]);
            viewCount = atoi(doc["items"][0]["statistics"]["viewCount"]);
            videoCount = atoi(doc["items"][0]["statistics"]["videoCount"]);
        }
    } else {
        error = "HTTP code '" + String(httpCode) + "' recieved.";
        success = false;
    }
    http.end();
    return success;
}

String YouTubeStats::getError() {
    return error;
}

uint YouTubeStats::getSubscriberCount() {
    return subscriberCount;
}

uint YouTubeStats::getViewCount() {
    return viewCount;
}

uint YouTubeStats::getVideoCount() {
    return videoCount;
}