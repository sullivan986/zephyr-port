#ifndef _MOTOR_AX12_H_
#define _MOTOR_AX12_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <zephyr/device.h>

    struct ax12_config
    {
        const struct device *dev;
        uint32_t id;
    };

    struct ax12_data
    {
        uint16_t finger_id;
        uint16_t finger_id1;
        uint16_t finger_id2;
        uint16_t finger_id3;
    };

#ifdef __cplusplus
}
#endif

#endif