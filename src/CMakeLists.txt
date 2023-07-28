cmake_minimum_required(VERSION 3.13)

file(GLOB FILES *.cpp *.hpp)
add_library(pico-RGB-lib ${FILES})
target_link_libraries(pico-RGB-lib hardware_gpio hardware_pwm)
target_include_directories(pico-RGB-lib PUBLIC ../include)
