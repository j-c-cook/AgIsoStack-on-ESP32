#include <isobus/hardware_integration/can_hardware_plugin.hpp>
#include <isobus/hardware_integration/available_can_drivers.hpp>
#include <isobus/hardware_integration/can_hardware_interface.hpp>
#include <isobus/hardware_integration/socket_can_interface.hpp>
#include <isobus/isobus/can_general_parameter_group_numbers.hpp>
#include <isobus/isobus/can_network_configuration.hpp>
#include <isobus/isobus/can_network_manager.hpp>
#include <isobus/isobus/can_parameter_group_number_request_protocol.hpp>
#include <hal/twai_types.h>
#include <driver/twai.h>
#include <esp_log.h>
#include <memory>

const char * tag = "esp-agisostack-ex";

extern "C" void app_main()
{
    twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_21, GPIO_NUM_22, TWAI_MODE_NORMAL);
    twai_timing_config_t t_config = TWAI_TIMING_CONFIG_250KBITS();
    twai_filter_config_t f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

    std::shared_ptr<isobus::CANHardwarePlugin> canDriver = nullptr;
    canDriver = std::make_shared<isobus::TWAIPlugin>(&g_config, &t_config, &f_config);

    isobus::CANHardwareInterface::set_number_of_can_channels(1);
    isobus::CANHardwareInterface::assign_can_channel_frame_handler(0, canDriver);

    if ((!isobus::CANHardwareInterface::start()) || (!canDriver->get_is_valid())) {
        ESP_LOGE(tag, "Failed to start hardware interface. The CAN driver might be invalid.");
        return;
    } else {
        ESP_LOGI(tag, "Successful start of hardware interface!");
    }

    // See https://github.com/Open-Agriculture/AgIsoStack-plus-plus/tree/main/examples and adapt as you see fit.
}
