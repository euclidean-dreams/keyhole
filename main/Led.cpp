#include "Led.h"

namespace keyhole {

CRGB leds[LED_COUNT] = {0};

void initializeLeds() {
    FastLED.addLeds<WS2812B, 15, GRB>(leds, 0, LED_SLICE_SIZE);
    FastLED.addLeds<WS2812B, 2, GRB>(leds, LED_SLICE_SIZE, LED_SLICE_SIZE);
    FastLED.addLeds<WS2812B, 4, GRB>(leds, 2 * LED_SLICE_SIZE, LED_SLICE_SIZE);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, LED_MAX_MILIAMPS);
}

void renderLoop(void *parameter) {
    while (true) {
        ulTaskNotifyTake(true, portMAX_DELAY);
        auto header = getReceiveBuffer();
        auto brightness = *header;
        auto ledData = header + SPI_HEADER_SIZE;
        std::memcpy(&leds, ledData, LED_COUNT * 3);
        FastLED.setBrightness(brightness);
        FastLED.show();
    }
}

}
