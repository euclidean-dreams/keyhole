#ifndef KEYHOLE_SPI_H
#define KEYHOLE_SPI_H

#include <esp_log.h>
#include <driver/spi_slave.h>
#include "Constants.h"
#include "TaskHandles.h"

namespace keyhole {

void initializeSpi();

void listenLoop(void *parameter);

char *getReceiveBuffer();

}

#endif //KEYHOLE_SPI_H
