#ifndef HMC5883L_H  // Controlla se QUATERNIONSLIB_H non è già stato definito
#define HMC5883L_H  // Definisce QUATERNIONSLIB_H

#include <Wire.h>

#define address 0x1E //0011110b, I2C 7bit address of HMC5883
#define XOFFSET 11.0
#define YOFFSET -78.5
#define DECLINATION 3.833

bool HMC5883l_initialization();

float HMC5883l_getHeading();

#endif