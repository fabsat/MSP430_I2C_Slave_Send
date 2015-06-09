// Customized by cya-ga-umai
#ifndef TI_USCI_I2C_SLAVE
#define TI_USCI_I2C_SLAVE

#define SDA_PIN BIT7                                  // msp430G2553 UCB0SDA pin
#define SCL_PIN BIT6                                  // msp430G2553 UCB0SCL pin

void TI_USCI_I2C_slaveinit(void (*SCallback)(unsigned char volatile *value),
                           void (*TCallback)(unsigned char volatile *value),
                           void (*RCallback)(unsigned char value), 
                           unsigned char slave_address);


#endif
