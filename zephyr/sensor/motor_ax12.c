#include "motor_ax12.h"
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>

static void ax12_trans(const struct device *dev, void *data)
{
}

static int ax12_attr_set(const struct device *dev, enum sensor_channel chan, enum sensor_attribute attr,
                         const struct sensor_value *val)
{
    return 0;
}

static int ax12_attr_get(const struct device *dev, enum sensor_channel chan, enum sensor_attribute attr,
                         struct sensor_value *val)
{
    return 0;
}

static int ax12_init(const struct device *dev)
{
    const struct ax12_config *cfg = dev->config;
    // struct ax12_data *drv_data = dev->data;
    uint8_t c;
    // int ret;

    if (!device_is_ready(cfg->dev))
    {
        // LOG_ERR("%s: ax12 device not ready", dev->name);
        return 0;
    }

    // clear uart fifo
    while (uart_fifo_read(dev, &c, 1) > 0)
    {
        continue;
    }

    printk("test,test,test");
    return 0;
}

static const struct sensor_driver_api ax12_driver_api = {
    .attr_set = ax12_attr_set, .attr_get = ax12_attr_get,
    //.sample_fetch = ax12_sample_fetch,
    //.channel_get = ax12_channel_get,
};

#define AX12_INIT(n)                                                                                                   \
    static struct ax12_data ax12_data_##n;                                                                             \
    static const struct ax12_config ax12_config_##n = {                                                                \
        .dev = DEVICE_DT_GET(DT_INST_BUS(n)),                                                                          \
        .id = DT_INST_REG_ADDR(n),                                                                                     \
    };                                                                                                                 \
    DEVICE_DT_INST_DEFINE(n, ax12_init, NULL, &ax12_data_##n, &ax12_config_##n, POST_KERNEL,                           \
                          CONFIG_SENSOR_INIT_PRIORITY, &ax12_driver_api);

DT_INST_FOREACH_STATUS_OKAY(AX12_INIT)
