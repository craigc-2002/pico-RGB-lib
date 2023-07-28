cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(RGB
    VERSION 0.1
    DESCRIPTION "Library to interface the Rasberry Pi Pico with an RGB LED"
    LANGUAGES CXX C ASM
)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

add_subdirectory(./src)
add_subdirectory(./examples)

