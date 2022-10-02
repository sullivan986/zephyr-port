.. _ztm32_g030k8_mini_board:

ZTM32_G030K8 MiniDev
################

Overview
********

The ZTM32_G030K8 board features an ARM Cortex-M0+ based STM32G030K8T6 MCU
with a wide range of connectivity support and configurations. Supports all devices using ``stm32g030k8``.

Hardware
********
- High-performance Arm® Cortex®-M0+ 32-bit RISC core operating at up to 64 MHz frequency.
- 8KB on-chip SRAM
- 64 Kbytes of Flash memory with protection
- 17 GPIO pins
- 12 bit ADC channels
- 2 USART peripherals
- 2 SPI controllers
- 2 I2C controllers
- On-board LED

.. image:: image/board.jepg
     :width: 500px
     :align: center
     :alt: ztm32_g030k8

Supported Features
==================

The Zephyr ztm32_g030k8 board configuration supports the following hardware features:

+-----------+------------+-------------------------------------+
| Interface | Controller | Driver/Component                    |
+===========+============+=====================================+
| MPU       | on-chip    | arm memory protection unit          |
+-----------+------------+-------------------------------------+
| NVIC      | on-chip    | nested vector interrupt controller  |
+-----------+------------+-------------------------------------+
| UART      | on-chip    | serial port-polling;                |
|           |            | serial port-interrupt               |
+-----------+------------+-------------------------------------+
| PINMUX    | on-chip    | pinmux                              |
+-----------+------------+-------------------------------------+
| GPIO      | on-chip    | gpio                                |
+-----------+------------+-------------------------------------+
| I2C       | on-chip    | i2c                                 |
+-----------+------------+-------------------------------------+
| SPI       | on-chip    | spi                                 |
+-----------+------------+-------------------------------------+
| CLOCK     | on-chip    | reset and clock control             |
+-----------+------------+-------------------------------------+
| FLASH     | on-chip    | flash memory                        |
+-----------+------------+-------------------------------------+
| COUNTER   | on-chip    | rtc                                 |
+-----------+------------+-------------------------------------+
| WATCHDOG  | on-chip    | independent watchdog                |
+-----------+------------+-------------------------------------+
| PWM       | on-chip    | pwm                                 |
+-----------+------------+-------------------------------------+
| ADC       | on-chip    | adc                                 |
+-----------+------------+-------------------------------------+

Other hardware features are not yet supported in this Zephyr port.
For more details see `STM32G030K8 on www.st.com`_.

The default configuration can be found in the defconfig file:
``boards/arm/ztm32_g030k8/ztm32_g030k8_defconfig``

Connections and IOs
===================

Each of the GPIO pins can be configured by software as output (push-pull or open-drain), as
input (with or without pull-up or pull-down), or as peripheral alternate function. Most of the
GPIO pins are shared with digital or analog alternate functions. All GPIOs are high current
capable except for analog inputs.

Default Zephyr Peripheral Mapping:
----------------------------------

- UART_1 TX/RX : PB6/PB7
- UART_2 TX/RX : PA2/PA3 (ST-Link Virtual Port Com)
- I2C1 SCL/SDA : PA9/PA10
- I2C2 SCL/SDA : PA11/PA12
- SPI1 NSS/SCK/MISO/MOSI : PB0/PB3/PB4/PB5
- SPI2 NSS/SCK/MISO/MOSI : (todo)
- LED       : PC15
- PWM       : PA6
- ADC1 IN0  : PA0
- ADC1 IN1  : PA1

For mode details please refer to `STM32G030 datasheet`_.

Programming and Debugging
*************************
Use ``west flash`` and ``west debug`` according to the tutorial on the official website.

References
**********

.. target-notes::

.. _STM32G030K8 on www.st.com:
   http://www.st.com/en/microcontrollers/stm32g030K8.html

.. _STM32G030 datasheet:
   http://www.st.com/resource/en/datasheet/stm32g030K8.pdf
