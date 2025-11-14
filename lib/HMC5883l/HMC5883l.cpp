#include <HMC5883l.h>

bool HMC5883l_initialization(){
    //Put the HMC5883 IC into the correct operating mode
    Wire.beginTransmission(address); //open communication with HMC5883
    Wire.write(0x02); //select mode register
    Wire.write(0x00); //continuous measurement mode
    Wire.endTransmission();
}

float HMC5883l_getHeading(){  
    int x,y,z; //triple axis data
    //Tell the HMC5883 where to begin reading data
    Wire.beginTransmission(address);
    Wire.write(0x03); //select register 3, X MSB register
    Wire.endTransmission();
    
    
    //Read data from each axis, 2 registers per axis
    Wire.requestFrom(address, 6);
    if(6<=Wire.available()){
        x = Wire.read()<<8; //X msb
        x |= Wire.read(); //X lsb
        z = Wire.read()<<8; //Z msb
        z |= Wire.read(); //Z lsb
        y = Wire.read()<<8; //Y msb
        y |= Wire.read(); //Y lsb
    }

    // Applica gli offset di calibrazione
    float xCalib = x - XOFFSET;
    float yCalib = y - YOFFSET;

    // Calcola l'heading in radianti
    float heading = atan2(yCalib, xCalib);

    // Converti l'heading da radianti a gradi
    heading = heading * 180.0 / M_PI;

    // Aggiungi la declinazione magnetica
    heading += DECLINATION;

    // Assicurati che l'heading sia tra 0 e 360 gradi
    if (heading < 0) {
        heading += 360.0;
    } else if (heading > 360) {
        heading -= 360.0;
    }

    heading = (heading * M_PI) / 180;

    return heading;
}
