#ifndef MCUCONF_CRYNU_H
#define MCUCONF_CRYNU_H

#include_next <mcuconf.h>

#define RP2040_MCUCONF
#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE


#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

#endif