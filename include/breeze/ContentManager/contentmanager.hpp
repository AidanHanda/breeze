#ifndef CONTENTMANAGER_CONTENTMANAGER_H
#define CONTENTMANAGER_CONTENTMANAGER_H

#include <string>
#include <filesystem>

class ContentDownloader {
private:
  const std::string content_url;
  bool audio_only;
  int start_time;
  int end_time;

public:
  ContentDownloader(const std::string &content_url);
  void set_start_time(int start_seconds);
  void set_end_time(int end_seconds);
  void set_time_bounds(int start_seconds, int end_seconds);
  void set_audio_only(bool is_audio_only);
  int get_start_time();
  int get_end_time();
  bool is_audio_only();
  std::filesystem::path download();
};

#endif /* CONTENTMANAGER_CONTENTMANAGER_H */
