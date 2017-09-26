#include <OneWire.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;

File dataFile;

void setup() {

    Serial.begin(9600);
    RTC.begin();
    
if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

    Serial.print("Initializing SD card...");

    DateTime now = RTC.now();

    if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
    }
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.print("Start logging on: ");
    dataFile.print(now.year(),DEC);
    dataFile.print('/');
    dataFile.print(now.month(),DEC);
    dataFile.print('/');
    dataFile.print(now.day(),DEC);
    dataFile.println(" ");
    dataFile.close();

}

void loop () {


            value = analogRead(potentiometer);

            DateTime now = RTC.now();
            
            dataFile = SD.open("datalog.txt", FILE_WRITE);
            dataFile.print("(");
            dataFile.print(now.hour(), DEC);
            dataFile.print(':');
            dataFile.print(now.minute(), DEC);
            dataFile.print(':');
            dataFile.print(now.second(), DEC);
            dataFile.print(") ");
            dataFile.println(" ");
            dataFile.close();
    delay(300);
}
