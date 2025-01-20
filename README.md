# AgIsoStack++ on ESP Platform

Incorporate the [AgIsoStack++](https://github.com/Open-Agriculture/AgIsoStack-plus-plus) library into an ESP32 project using the Espressif IDF component style project structure.

## How it works

The `iso-on-esp` module is marked as a required component in `main`s [CMakeLists.txt](./main/CMakeLists.txt).

## Build

The local `build.sh` script can be used on both MacOS and GNU/Linux.

```
. ./build.sh
idf.py build
```

For any further environment setup inquries, see the Espressif IDF [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html#manual-installation) for setting up the build environment on either Windows, Linux or MacOS.
