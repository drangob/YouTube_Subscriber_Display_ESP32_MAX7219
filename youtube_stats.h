#ifndef YOUTUBE_STATS_H
#define YOUTUBE_STATS_H

#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "api_secrets.h"

class YouTubeStats {
private:
  String error;
  uint subscriberCount;
  uint viewCount;
  uint videoCount;

public:
  bool fetch();
  String getError();
  uint getSubscriberCount();
  uint getViewCount();
  uint getVideoCount();
};

#endif