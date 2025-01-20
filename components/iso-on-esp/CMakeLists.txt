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

include(FetchContent)

FetchContent_Declare(
   AgIsoStack
   GIT_REPOSITORY https://github.com/j-c-cook/AgIsoStack-plus-plus.git
   GIT_TAG        9c95260402afe7fbb1b5000ded2f66c82d10a1bb
)
FetchContent_MakeAvailable(AgIsoStack)

target_link_libraries(${COMPONENT_LIB} INTERFACE isobus::Isobus isobus::HardwareIntegration isobus::Utility)
