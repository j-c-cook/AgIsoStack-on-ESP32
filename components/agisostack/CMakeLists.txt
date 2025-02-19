idf_component_register(REQUIRES driver)

# Include the sdkconfig.h to access the Kconfig variables
include_directories("${CMAKE_BINARY_DIR}/config")

if(CONFIG_INTERFACE1)
    set(CAN_DRIVER "TWAI")
elseif(CONFIG_INTERFACE2)
    set(CAN_DRIVER "MCP2515")
else()
    set(CAN_DRIVER "TWAI")
endif()
message(STATUS "Selected hardware interface: ${CAN_DRIVER}")

# NOTE: If you would rather use a git submodule, then replace the "FetchContent" lines with the following:
# add_subdirectory(path/to/AgIsoStack++)

include(FetchContent)

FetchContent_Declare(
   AgIsoStack
   GIT_REPOSITORY https://github.com/Open-Agriculture/AgIsoStack-plus-plus.git
   GIT_TAG        main
)
FetchContent_MakeAvailable(AgIsoStack)

target_link_libraries(${COMPONENT_LIB} INTERFACE isobus::Isobus isobus::HardwareIntegration isobus::Utility)
