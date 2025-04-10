int forwardPin1 = 7;
int backwardsPin1 = 8;

int forwardPin2 = 12;
int backwardsPin2 = 13;

void setup() {
  pinMode(forwardPin1, OUTPUT);
  pinMode(backwardsPin1, OUTPUT);

  pinMode(forwardPin2, OUTPUT);
  pinMode(backwardsPin2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {

  
  digitalWrite(forwardPin1, HIGH);
  digitalWrite(backwardsPin1, LOW);

  digitalWrite(forwardPin2, HIGH);
  digitalWrite(backwardsPin2, LOW);
}
