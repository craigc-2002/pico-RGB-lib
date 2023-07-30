add_executable(RGBFade
    RGBFade.cpp
)

target_link_libraries(RGBFade pico-RGB-lib pico_stdlib)

pico_add_extra_outputs(RGBFade)
