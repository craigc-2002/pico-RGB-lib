/* pico-RGB-lib - HelloRGB.cpp
 * Craig Cochrane, 2023
 *
 * Example demonstrating a slow fade through the RGB colours
 */

#include "RGB.hpp"
#include "pico/stdlib.h"

int main()
{
    RGB led(5, 4, 3);
    int r = 0;
    int g = 0;
    int b = 0;

    while (true)
    {
        for (r; r<255; r++)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (b; b<255; b++)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (g; g<255; g++)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (r; r>0; r--)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (g; g>0; g--)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (b; b>0; b--)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (g; g<255; g++)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (r; r<255; r++)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (b; b<255; b++)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (r; r>0; r--)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (g; g>0; g--)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }

        for (b; b>0; b--)
        {
            led.set(r, g, b);
            sleep_ms(20);
        }
    }
}
    

