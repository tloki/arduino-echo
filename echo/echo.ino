// define this flag if you want serial physical connections to differ
//#define SOURCE_NOT_SAME_AS_DEST

// define if destination serial is software serial
//#define DEST_IS_SOFTWARE_SERIAL
#include <Arduino.h>

#define SOURCE_BAUD 9600
#define DEST_BAUD 9600      // no need to define if source == dest
#define SERIAL2 Serial1     // no need to define if source == dest
#define DEST_RX_PIN 11      // no need to define if destination is not software serial 
#define DEST_TX_PIN 12      // no need to define if destination is not software serial

///////////////////////////////////
/// do not edit below this line ///
///////////////////////////////////

#ifdef DEST_IS_SOFTWARE_SERIAL
SoftwareSerial dest_sw_serial(10, 11);
#endif

#define DEST_SER

void setup()
    {
    Serial.begin(SOURCE_BAUD);
    
    #ifdef SOURCE_NOT_SAME_AS_DEST
    #undef DEST_SER
    #ifdef DEST_IS_SOFTWARE_SERIAL
    #define DEST_SER dest_sw_serial;
    //dest_sw_serial.begin(DEST_BAUD);
    #else
    #define DEST_SER SERIAL2;
    #endif
    #else
    #undef DEST_SER
    #define DEST_SER Serial;
    #endif
    }

bool didRead = false;

void loop()
    {
    
    if(Serial.available() > 0)
        {
        while(Serial.available() > 0)
            {
            didRead = true;
            char a = Serial.read();
            Serial.print(a);
            delayMicroseconds(1500); // TODO: should be dynamic, using some MACRO map or some range questioning. 9600 1500 is ok. for 300 8000 is ok. depends on output baud? 
            }
        }
    if(didRead)
        {
        Serial.println(" ");
        didRead = false;
        }
    }
