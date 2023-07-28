add_executable(HelloRGB
    HelloRGB.cpp
)

target_link_libraries(HelloRGB pico-RGB-lib pico_stdlib)

pico_add_extra_outputs(HelloRGB)
