/* pico-RGB-lib - RGB.cpp
 * Craig Cochrane, 2023
 *
 * Library to interface Raspberry Pi Pico with an RGB LED
 * 
 * Uses PWM to control the brightness of each individual LED to set the colour and brightness
 */

#include "RGB.hpp"

#include "hardware/gpio.h"
#include "hardware/pwm.h"

RGB::RGB(int r_pin, int g_pin, int b_pin)
{
    output_pins[0] = r_pin;
    output_pins[1] = g_pin;
    output_pins[2] = b_pin;

    for (int i{0}; i<3; i++)
    {
        gpio_set_function(output_pins[i], GPIO_FUNC_PWM);
        int slice = pwm_gpio_to_slice_num(output_pins[i]);
        pwm_set_wrap(slice, _max_count);
        pwm_set_enabled(slice, true);
    }
}

void RGB::on(void)
{
    _on = true;
    set(_r, _g, _b);
}

void RGB::off(void)
{
    _on = false;
    pwm_set_gpio_level(output_pins[0], 256);
    pwm_set_gpio_level(output_pins[1], 256);
    pwm_set_gpio_level(output_pins[2], 256);
}

void RGB::toggle()
{
    _on ^= 1;

    if (_on)
    {
        this->on();
    }else{
        this->off();
    }
}

void RGB::set(uint8_t r, uint8_t g, uint8_t b)
{
    _on = true;
    red(r);
    green(g);
    blue(b);
}

void RGB::set(colours colour)
{
    _on = true;
    switch (colour){
        case RED: 
            this->set(255, 0, 0);
            break;
        case GREEN:
            this->set(0, 255, 0);
            break;
        case BLUE:
            this->set(0, 0, 255);
            break;
        case YELLOW:
            this->set(255, 255, 0);
            break;
        case MAGENTA:
            this->set(255, 0, 255);
            break;
        case CYAN:
            this->set(0, 255, 255);
            break;
        case WHITE:
            this->set(255, 255, 255);
            break;
    }
}

void RGB::red(int r)
{
    _r = r;
    int r_out = output_conversion(r);
    pwm_set_gpio_level(output_pins[0], r_out);
}

void RGB::green(int g)
{
    _g = g;
    int g_out = output_conversion(g);
    pwm_set_gpio_level(output_pins[1], g_out);
}

void RGB::blue(int b)
{
    _b = b;
    int b_out = output_conversion(b);
    pwm_set_gpio_level(output_pins[2], b_out);
}

int RGB::output_conversion(int colour)
{
    // LED is common annode, so turns on when output is low
    int colour_out = _max_count - colour;
    return colour_out;
}
