#include <Arduino.h>
#include <L293D.h>

int rightSens; //right sens pin here
int leftSens; //left sens pin here

//motor 1
int forwardPin1 = 7;
int backwardsPin1 = 8;
int pwmPin1 = 6;

//motor2
int forwardPin2 = 12;
int backwardsPin2 = 13;
int pwmPin2 = 11;

void setup() {  
  pinMode(forwardPin1, OUTPUT);
  pinMode(backwardsPin1, OUTPUT);
  pinMode(pwmPin1, OUTPUT);

  pinMode(forwardPin2, OUTPUT);
  pinMode(backwardsPin2, OUTPUT);
  pinMode(pwmPin2, OUTPUT);

  Serial.begin(9600);
}

void loop(){
  
  digitalWrite(forwardPin1, HIGH);
  digitalWrite(backwardsPin1, LOW);
  analogWrite(pwmPin1, 100);

  digitalWrite(forwardPin2, HIGH);
  digitalWrite(backwardsPin2, LOW);
  analogWrite(pwmPin2, 200);

}