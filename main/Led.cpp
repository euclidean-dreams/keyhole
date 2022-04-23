#include "Led.h"

namespace keyhole {

CRGB leds[LED_COUNT] = {0};

void initializeLeds() {
    FastLED.addLeds<WS2811, 13, GRB>(leds, 0 * LED_SLICE_SIZE, LED_SLICE_SIZE);
    FastLED.addLeds<WS2811, 12, GRB>(leds, 1 * LED_SLICE_SIZE, LED_SLICE_SIZE);
    FastLED.addLeds<WS2811, 14, GRB>(leds, 2 * LED_SLICE_SIZE, LED_SLICE_SIZE);
    FastLED.addLeds<WS2811, 27, GRB>(leds, 3 * LED_SLICE_SIZE, LED_SLICE_SIZE);
    FastLED.addLeds<WS2811, 26, GRB>(leds, 4 * LED_SLICE_SIZE, LED_SLICE_SIZE);
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
