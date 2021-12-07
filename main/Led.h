#ifndef KEYHOLE_LED_H
#define KEYHOLE_LED_H

#include <esp_log.h>
#include <FastLED.h>
#include <cstring>
#include "Spi.h"
#include "Constants.h"

namespace keyhole {

void initializeLeds();

void renderLoop(void *parameter);

}

#endif //KEYHOLE_LED_H
