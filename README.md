# AgIsoStack++ on ESP Platform

Incorporate the [AgIsoStack++](https://github.com/Open-Agriculture/AgIsoStack-plus-plus) library into an ESP32 project using the Espressif IDF component style project structure.

## How it works

The `agisostack` [component](components/agisostack) is marked as a required component in `main`s [CMakeLists.txt](./main/CMakeLists.txt).

## Build

The local `build.sh` script can be used on both MacOS and GNU/Linux.

```
. ./build.sh
idf.py build
```

For any further environment setup inquries, see the Espressif IDF [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html#manual-installation) for setting up the build environment on either Windows, Linux or MacOS.

## Configuration Options

TWAI or MCP2515 are supported hardware interfaces by AgIsoStack++ that may be used with an ESP32. The selected hardware types are defined in the [agisostack/Kconfig](components/agisostack/Kconfig) file and can be selected in the configuration menu.

```
idf.py menuconfig
```

```
Component config --> AgIsoStack --> Select CAN Hardware Interface --> (x) TWAI ( ) MCP2515
```

The default hardware interface specified in this project is TWAI. The [main/main.cpp](main/main.cpp) file currently only handles the TWAI selection.
