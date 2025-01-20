cmake_minimum_required(VERSION 3.16)

if(NOT ESP_PLATFORM)
    message(WARNING "ESP_PLATFORM variable missing!
    The Espressif build documentation states that ESP_PLATFORM is set to 1 during the build process.
    This variable will be manually set now, but it could be indicative of build environment issues on your machine.")
    set(ESP_PLATFORM 1)
endif()

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(AgIsoStack-on-ESP)
