#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    NO_ERROR = 0,
    POWER_BAD,
    LOST_CONNECTION,
    ERROR1,
    ERROR2,
    ERROR3,
    ERROR4,
    ERROR5,
} ERRORS_E;

int main()
{
    uint8_t status = 0xE3;
    uint8_t* status_ptr = &status;

    bool on = (*status_ptr & 0x01);
    uint8_t error = (*status_ptr & 0x0E) >> 1;
    uint8_t lon = (*status_ptr & 0x30) >> 4;
    uint8_t lat = (*status_ptr & 0xC0) >> 6;

    if (!on) {
        printf("Sensor is off\n");
        return EXIT_FAILURE;
    }

    switch (error) {
    case NO_ERROR:
        printf("Lon: %d | Lat: %d\n", lon, lat);
        break;
    case POWER_BAD:
        printf("Power bad\n");
        break;
    case LOST_CONNECTION:
        printf("Lost connection\n");
        break;
    }

    return EXIT_SUCCESS;
}
