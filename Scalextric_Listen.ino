// ----- BEGIN BOARD SETUP ------ //
// SERVO CONNECTIONS
// RED == 5v
// BLACK == Gnd
// WHITE == Pin9
// ------ END BOARD SETUP ------ //

char btAr[4];
byte index = 0;
int r = 0;

int baudRate = 9600;
int inputValue;
int car = 3;
int car2= 5;
String myString;
long carValue1;
int carValue2;

void setup(){
  Serial.begin(baudRate);
  pinMode(car, OUTPUT);
  pinMode(car2, OUTPUT);  
}

void serialRX(){
  
  /*
  while(Serial.available() > 0 && index < 3){
    char aChar = Serial.read();
    btAr[index] = aChar;
    index++;
    btAr[index] = '\0';
  }
  Serial.println(btAr);
  */
    if (Serial.available()) {
      char ch1 = Serial.read();
      char ch2 = Serial.read();
      char ch3 = Serial.read();
  
      r = (ch1 - '0') * 100 + (ch2 - '0') * 10 + (ch3 - '0');
      Serial.println(r);
      analogWrite(car, r);
      analogWrite(car2, r);
    }
}

void loop(){
  serialRX();

  /*
  if (Serial.available()) {
    inputValue = Serial.read();
    Serial.println(inputValue); 
    //pinMode(car, OUTPUT);
    //String myString = String(inputValue);
    long carValue1 = myString.toInt();
    //Serial.println(carValue1);
    analogWrite(car, inputValue); 
    delay(1000);
  }
  */
}
