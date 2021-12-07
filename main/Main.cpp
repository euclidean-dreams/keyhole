#include "Spi.h"
#include "Led.h"
#include "TaskHandles.h"

void entrypoint() {
    using namespace keyhole;
    initializeSpi();
    initializeLeds();

    xTaskCreate(&listenLoop, "listenLoop", 2048, nullptr, 5, getListenLoopHandle());
    xTaskCreate(&renderLoop, "renderLoop", 2048, nullptr, 5, getRenderLoopHandle());
}

extern "C" {
void app_main(void) {
    entrypoint();
}
}
