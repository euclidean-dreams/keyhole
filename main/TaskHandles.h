#ifndef KEYHOLE_TASKHANDLES_H
#define KEYHOLE_TASKHANDLES_H

#include "freertos/FreeRTOS.h"
#include <freertos/task.h>

namespace keyhole {

TaskHandle_t *getListenLoopHandle();

TaskHandle_t *getRenderLoopHandle();

}
#endif //KEYHOLE_TASKHANDLES_H
