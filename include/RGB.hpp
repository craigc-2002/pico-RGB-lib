/* pico-RGB-lib - RGB.hpp
 * Craig Cochrane, 2023
 *
 * Library to interface Raspberry Pi Pico with an RGB LED
 * 
 * Uses PWM to control the brightness of each individual LED to set the colour and brightness
 */

#ifndef _RGB_H_
#define _RGB_H_

#include <cstdint>

class RGB
{
    public:
        enum colours {RED, GREEN, BLUE, YELLOW, MAGENTA, CYAN, WHITE};
        
        RGB(int r_pin, int g_pin, int b_pin);

        void on(void);
        void off(void);

        void set(uint8_t r, uint8_t g, uint8_t b);
        void set(colours colour);

        void red(int r);
        void green(int g);
        void blue(int b);

    private:
        int output_conversion(int colour);
        
    private:
        int output_pins[3];
        int _r, _g, _b;

        int _max_count {255};
};

#endif
