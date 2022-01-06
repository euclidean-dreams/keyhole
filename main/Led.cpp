#include "Led.h"

namespace keyhole {

CRGB leds[LED_COUNT] = {0};

void initializeLeds() {
    FastLED.addLeds<WS2812B, 13, GRB>(leds, 0, LED_COUNT);
    FastLED.setMaxPowerInVoltsAndMilliamps(1, LED_MAX_MILIAMPS);
}

void renderLoop(void *parameter) {
    bool switcher = true;
    while (true) {
        vTaskDelay(10);
        for (int i = 0; i < LED_COUNT; i++) {
            if (switcher) {
                if (i % 2 == 0) {
                    leds[i].setRGB(234, 0, 255);
                } else {
                    leds[i].setRGB(128, 255, 0);
                }
            } else {
                if (i % 2 == 0) {
                    leds[i].setRGB(128, 255, 0);
                } else {
                    leds[i].setRGB(234, 0, 255);
                }
            }
        }
        switcher = !switcher;
        FastLED.show();
    }
}

}
