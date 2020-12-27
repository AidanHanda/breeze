#include "breeze/ContentManager/contentmanager.hpp"
#include <exception>
#include <memory>
#include <iostream>

std::unique_ptr<ContentDownloader> configure_content_downloader() {
  std::cout << "Please enter the url: ";
  const std::string content_url = []() -> std::string{
                                                   std::string inp;
                                                   std::cin >> inp;
                                                   return inp;
                                  }();
  std::cout << "\n";

  auto cd = std::make_unique<ContentDownloader>(content_url);

  std::cout << "Audio only? (*n/y): ";
  char resp;
  std::cin >> resp;
  if (resp == 'y') {
    cd->set_audio_only(true);
  }

  return cd;
}

int main(int argc, char* args[]) {
  std::unique_ptr<ContentDownloader> cd;
  if (argc == 1) {
    cd = configure_content_downloader();
  } else {
    std::cout << "This tool does not support arguments yet!"; //TODO(aidanhanda): Add support for arguments
    throw std::exception();
  }
  cd->download();
  return 0;
}
