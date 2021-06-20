
const int flexPin1 = 15; //analog pin on esp32
const int flexPin2 = 4; //analog pin on esp32
int value1=0; //storing the flex sensor value
int value2=0; //storing the flex sensor value


int TouchValue;//storing the touch sensor value 
int TouchPalm; //storing the touch sensor value


void setup() {

  Serial.begin(9600); 


}

void loop() {

//middle
  value1 = analogRead(flexPin1); //Read and save analog value from flexsensor
  value1 = map(value1,0, 4095, 0, 10);

//ring
  value2 = analogRead(flexPin2); //Read and save analog value from flexsensor
  value2 = map(value2,0, 4095, 0, 10);

  Serial.println();
  Serial.print(value1);
  Serial.print(",");
  Serial.print(value2);



  TouchValue = touchRead(33); //reading touch sensor from ESP32
  if (TouchValue <= 20){ //if its 'on'
    Serial.print(",");
    Serial.print("1");
  }
  else { //if its 'off'
    Serial.print(",");
    Serial.print("0");
  }


  TouchPalm = touchRead(32); //reading touch sensor from ESP32 
  if (TouchPalm <= 25){ //if its 'on'
    Serial.print(",");
    Serial.print("1");
  }
  else { //if its 'off'
    Serial.print(",");
    Serial.print("0");
  }


delay(100);
  
  }
  
