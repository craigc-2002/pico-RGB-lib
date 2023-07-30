/* pico-RGB-lib - HelloRGB.cpp
 * Craig Cochrane, 2023
 *
 * Basic example demonstrating controlling an RGB LED with the library
 * The program loops through some basic colours and the LED can b eturned on and off using a button
 */

#include "RGB.hpp"
#include "pico/stdlib.h"

bool LED_on {true};
RGB led(5, 4, 3);

void led_toggle(uint pin, uint32_t event_mask)
{
    /* Callback function to toggle the LED on and off 
     * Will be set as an interrupt on a pin with a button connected */
    led.toggle();
    LED_on ^= 1;
}

int main()
{
    gpio_init(15);
    gpio_set_dir(15, GPIO_IN);
    gpio_set_irq_enabled_with_callback(15, GPIO_IRQ_EDGE_RISE, true, &led_toggle);
    while (true)
    {
        for (int i{0}; i < 7; i++)
        {
            if (LED_on)
            {
                RGB::colours colour = static_cast<RGB::colours>(i);
                led.set(colour);
            }else{
                led.off();
            }
            sleep_ms(1000);
        }
    }
}
    

