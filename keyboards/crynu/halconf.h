#ifndef CRYNU_HALCONF
#define CRYNU_HALCONF
// #define HAL_USE_PWM TRUE

// #define HAL_USE_SERIAL TRUE

#define SERIAL_USB_BUFFERS_SIZE 256

#undef HAL_USE_I2C
#define HAL_USE_I2C TRUE
#define HAL_USE_SPI TRUE

#define SPI_USE_WAIT TRUE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD

#include_next <halconf.h>

#endif