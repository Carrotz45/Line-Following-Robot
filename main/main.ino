#include <Arduino.h>


int powerButtonPin = 2;
bool powerON = false;


int rightSens = 4; //right sens pin here
int leftSens = 5; //left sens pin here
int middleSens = 3;


//motor 1
int forwardPin1 = 7;
int backwardsPin1 = 8;
int pwmPin1 = 6;


//motor2
int forwardPin2 = 13;
int backwardsPin2 = 12;
int pwmPin2 = 11;

int redLED = 9;
int yellowLED = 10;

String RorL;

void setup() {
  pinMode(powerButtonPin, INPUT);

  pinMode(forwardPin1, OUTPUT);
  pinMode(backwardsPin1, OUTPUT);
  pinMode(pwmPin1, OUTPUT);


  pinMode(forwardPin2, OUTPUT);
  pinMode(backwardsPin2, OUTPUT);
  pinMode(pwmPin2, OUTPUT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

  Serial.begin(9600);
}


void loop(){
  buttonOnOff();

  digitalWrite(forwardPin1, LOW);
  digitalWrite(backwardsPin1, LOW);


  digitalWrite(forwardPin2, LOW);
  digitalWrite(backwardsPin2, LOW);

  digitalWrite(redLED, LOW);

  while (powerON == true){

    buttonOnOff();

    if (powerON == false){
      break;
    }

    else{
      motorControll(75);
    }
  }

}


void buttonOnOff(){
  int buttonState = digitalRead(powerButtonPin);

  if (buttonState == HIGH){
    if (powerON == false){
      powerON = true;
    }
    else{
      powerON = false;
    }
  }

  delay(200);
}




void lineDetect(int rPin, int lPin, int mPin){
  int right = digitalRead(rPin);
  int left = digitalRead(lPin);
  int middle = digitalRead(mPin);

  if (right == HIGH){
    RorL = String("R");
  }
  else if (left == HIGH){
    RorL = String("L");
  }
  else if (middle == HIGH && left == LOW && right == LOW){
    RorL = String("IL");
  }
  else{
    RorL = String("OUT");
  }

}


void motorControll(int speed){

  digitalWrite(forwardPin1, HIGH);
  digitalWrite(backwardsPin1, LOW);


  digitalWrite(forwardPin2, HIGH);
  digitalWrite(backwardsPin2, LOW);

  lineDetect(rightSens, leftSens, middleSens);


  if (RorL == String("R")){
    Serial.println("right");

    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    analogWrite(pwmPin1, speed*0.7);
    analogWrite(pwmPin2, speed*1.4);

    // delay(500);

    // analogWrite(pwmPin1,speed);
    // analogWrite(pwmPin2,speed);
  }
  else if (RorL == String("L")){
    Serial.println("left");

    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    analogWrite(pwmPin1, speed*1.4);
    analogWrite(pwmPin2, speed*0.5);

    // delay(500);

    // analogWrite(pwmPin1, speed);
    // analogWrite(pwmPin2, speed);
  }
  else if (RorL == String("IL")){
    Serial.println("in line");
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    analogWrite(pwmPin1,speed);
    analogWrite(pwmPin2,speed);
  }
  else if (RorL == String("OUT")){
    Serial.println("OUTSIDE OF BOUNDS");

    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);

    lineDetect(rightSens, leftSens, middleSens);

    delay(500);

    lineDetect(rightSens, leftSens, middleSens);
    
    if (RorL == String("OUT")){
      powerON = false;
    }
  }

}






