#ifndef CRYNU2_CONFIG
#define CRYNU2_CONFIG

#define I2C_DRIVER I2CD0

#define I2C1_SCL_PIN GP4
#define I2C1_SDA_PIN GP5


#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP16

#define CIRQUE_PINNACLE_SPI_CS_PIN GP17


#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

#define DYNAMIC_MACRO_SIZE 128
// #define DYNAMIC_MACRO_USER_CALL

#endif