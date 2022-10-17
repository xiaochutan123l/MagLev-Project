/*
The basic version of the pull-up magnet levitation. 
*/

#include <TM1637.h>

// Hall component.
const int readPin = A1;
int adjustPin = A2;
int readValue = 0.0;            
float adjustValue  = 240;         
float filtValue = 0.0;

// LedDisplay component.
int CLK = 2;
int DIO = 3;
TM1637 tm(CLK,DIO);

// L298N component.
int IN1Pin = 4;
int IN2Pin = 5;
int EA1Pin = 6;
bool flag = true;

// PID components.
float error = 0.0;
float prevError = 0.0;
float power = 0.0;
float kp = 20.0;
float kd = 5.0;
float derivative = 0.0;
float dt = 0.1;
float output = 0.0;

void setup() { 
  pinMode(readPin, INPUT);
  pinMode(adjustPin, INPUT);    
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN1Pin, OUTPUT);
  digitalWrite(IN1Pin, flag);  
  digitalWrite(IN2Pin, !flag);
  digitalWrite(EA1Pin,HIGH);  

  // Set digit dispaly for debug and parameters adjusting.
  tm.init();
  //set brightness; 0-7
  tm.set(2);
}

void loop() {
  readValue = 0;
  for (int i = 0; i < 20; i++){
    readValue += analogRead(readPin);
    }
  filtValue = readValue / 20;
  error = filtValue - adjustValue;

  derivative = (error - prevError) / dt;
  power = (-kp * error) + (-kd * derivative);
  prevError = error;

  if (power > 255){
    power = 255;
    }
  else if (power < -255){
    power = -255;
    }
  // only provides push force to floater.
  if (power <= 0){
    flag = false;
    digitalWrite(IN1Pin, flag);  
    digitalWrite(IN2Pin, !flag);
    analogWrite(EA1Pin, -power);
  }
} 

void displayNumber(int num){   
  tm.display(3, num % 10);   
  tm.display(2, num / 10 % 10);   
  tm.display(1, num / 100 % 10);   
  tm.display(0, num / 1000 % 10);
}
