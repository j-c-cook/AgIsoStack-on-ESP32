idf_component_register(REQUIRES driver)

set(CAN_DRIVER "TWAI")

add_subdirectory(AgIsoStack-plus-plus)

target_link_libraries(${COMPONENT_LIB} INTERFACE isobus::Isobus isobus::HardwareIntegration isobus::Utility)
