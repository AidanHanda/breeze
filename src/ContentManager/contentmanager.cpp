#include "breeze/ContentManager/contentmanager.hpp"
#include <exception>
#include <stdexcept>
#include <string>

ContentDownloader::ContentDownloader(const std::string &content_url)
    : content_url(content_url), audio_only(false), start_time(0), end_time(-1) {
}

void ContentDownloader::set_start_time(int start_seconds) {
  this->start_time = start_seconds;
}

void ContentDownloader::set_end_time(int end_seconds) {
  this->end_time = end_seconds;
}

void ContentDownloader::set_time_bounds(int start_seconds, int end_seconds) {
  set_start_time(start_seconds);
  set_end_time(end_seconds);
}

void ContentDownloader::set_audio_only(bool is_audio_only) {
  this->audio_only = is_audio_only;
}

int ContentDownloader::get_start_time() { return this->start_time; }

int ContentDownloader::get_end_time() { return this->end_time; }

bool ContentDownloader::is_audio_only() { return this->audio_only; }

std::filesystem::path ContentDownloader::download() {
  const std::string ytdl = "youtube-dl ";
  std::string command = ytdl;
  if (this->is_audio_only()) {
    command += "-x --audio-format mp3 ";
  } else {
    command += "--format mp4 ";
  }

  if (this->start_time != 0 || this->end_time >= 0) {
    command += "--exec 'ffmpeg -y -i {} ";
    if (this->start_time > 0) {
      command += "-ss " + std::to_string(start_time) + " ";
    }
    if (this->end_time >= 0) {
      if (this->end_time < start_time) {
        throw std::out_of_range("Cannot end earlier than start time!");
      }
      command += "-to " + std::to_string(end_time) + " ";
    }

    command += "-c copy trimmed-{} && rm {}' ";
  }

  command = command + this->content_url;

  std::system(command.c_str());
  return std::filesystem::path("/dev/null"); //TODO(aidanhanda): This is here to allow for this tool to be moved to a webservice
}
