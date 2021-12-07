#include "TaskHandles.h"

namespace keyhole {

TaskHandle_t listenLoopHandle = nullptr;
TaskHandle_t renderLoopHandle = nullptr;

TaskHandle_t *getListenLoopHandle() {
    return &listenLoopHandle;
}

TaskHandle_t *getRenderLoopHandle() {
    return &renderLoopHandle;
}

}
