#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT; //iniating the bluetooth within the ESP32


const int flexPin1 = 15; //analog pin on esp32
const int flexPin2 = 4; //analog pin on esp32
int value1=0; //storing the flex sensor value
int value2=0; //storing the flex sensor value


int TouchValue; //storing the touch sensor value 
int TouchPalm; //storing the touch sensor value 


void setup() {

  SerialBT.begin("ESP32_VRGLOVE"); //Bluetooth device name, you can change this to any name you want


}

void loop() {

//middle
  value1 = analogRead(flexPin1); //Read and save analog value from flexsensor
  value1 = map(value1,0, 4095, 0, 10);

//ring
  value2 = analogRead(flexPin2); //Read and save analog value from flexsensor
  value2 = map(value2,0, 4095, 0, 10);

  SerialBT.println();
  SerialBT.print(value1);
  SerialBT.print(",");
  SerialBT.print(value2);



  TouchValue = touchRead(33); //reading touch sensor from ESP32
  if (TouchValue <= 20){ //if its 'on'
    SerialBT.print(",");
    SerialBT.print("1");
  }
  else {  //if its 'off'
    SerialBT.print(",");
    SerialBT.print("0");
  }


  TouchPalm = touchRead(32);  //reading touch sensor from ESP32 
  if (TouchPalm <= 25){ //if its 'on'
    SerialBT.print(",");
    SerialBT.print("1");
  }
  else { //if its 'off's
    SerialBT.print(",");
    SerialBT.print("0");
  }


delay(100);
  
  }
  
