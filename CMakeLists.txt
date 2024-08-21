cmake_minimum_required(VERSION 3.15)

include(proj.conf)

find_package(bouffalo_sdk REQUIRED HINTS $ENV{BL_SDK_BASE})

sdk_add_include_directories(.)
sdk_add_include_directories(drivers)

target_sources(app PRIVATE drivers/led_driver.c)
target_sources(app PRIVATE drivers/ble_driver.c)
target_sources(app PRIVATE drivers/pwm_driver.c)
target_sources(app PRIVATE drivers/stepper_motor.c)
target_sources(app PRIVATE drivers/timer_driver.c)

sdk_set_main_file(main.c)

project(gpio_output_with_input)