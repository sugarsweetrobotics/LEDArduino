// #include "Serial.h"

void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT);
  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);

  digitalWrite(13, LOW);
}

void loop() {
  if (Serial.available()) {
    int bb = Serial.read();
    if (bb == 0xF1) {
      while(!Serial.available());
      bb = Serial.read();
      if (bb != 0xF1) {
        digitalWrite(13, HIGH);
        return;
      } 
    } else {
      digitalWrite(13, HIGH);
      return;
    }
    
    while(!Serial.available());
    int r = Serial.read();
    
    while(!Serial.available());
    int g = Serial.read();
    
    while(!Serial.available());
    int b = Serial.read();
    
    analogWrite(11, r);
    analogWrite(10, g);
    analogWrite(9, b);
    
    digitalWrite(13, LOW);
  }
}
