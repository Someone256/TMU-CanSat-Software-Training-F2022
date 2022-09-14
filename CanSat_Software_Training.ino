#include <Servo.h>
//Led Pins
  int rLed = 3;
  int gLed = 6;
  int bLed = 5;
//Other Pins
    int servoPin = 9;
    int tempPin = A0;

  double outputTime = millis() + 500;
  Servo servo1;
  double temp;

void setup()
{
    
  pinMode(rLed,OUTPUT);
    pinMode(gLed,OUTPUT);
    pinMode(bLed,OUTPUT);
    
    pinMode(tempPin,INPUT);
  
    servo1.attach(servoPin);
  
    Serial.begin(9600);
    
}

void loop()
{
  temp = analogRead(tempPin)*(500.0/1023.0)-50;
    if(millis() > outputTime){
      Serial.print("Temperature(C): ");
      Serial.println(temp);
      outputTime = millis() + 500;
    }
    if(temp >= -40 && temp <= 125){
      servo1.write((temp+40)*(180.0/165.0));
    }
    
    if(temp >= -40 && temp <= -10){
      //Blue Light
        analogWrite(rLed,0);
        analogWrite(gLed,0);
        analogWrite(bLed,255);
    }else if(temp > -10 && temp <= 20){
      //Green Light
        analogWrite(rLed,0);
        analogWrite(gLed,255);
        analogWrite(bLed,0);
    }else if(temp > 20 && temp <= 50){
      //Yellow Light
        analogWrite(rLed,255);
        analogWrite(gLed,255);
        analogWrite(bLed,0); 
    }else if(temp > 50 && temp <= 80){
      //Purple Light
        analogWrite(rLed,255);
        analogWrite(gLed,0);
        analogWrite(bLed,255);
    }else if(temp > 80 && temp <= 110){
      //Red Light
        analogWrite(rLed,255);
        analogWrite(gLed,0);
        analogWrite(bLed,0); 
    }else if(temp > 110 && temp <= 125){
      //White Light
        analogWrite(rLed,255);
        analogWrite(gLed,255);
        analogWrite(bLed,255); 
    }else {
       //Temp Outside of Range
        analogWrite(rLed,0);
        analogWrite(gLed,0);
        analogWrite(bLed,0);
    }
}
