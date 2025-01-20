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

add_subdirectory(AgIsoStack-plus-plus)

target_link_libraries(${COMPONENT_LIB} INTERFACE isobus::Isobus isobus::HardwareIntegration isobus::Utility)
