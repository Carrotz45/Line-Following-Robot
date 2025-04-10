int sens1p = 2;
int sens2p = 3;

void setup() {
  pinMode(sens1p, INPUT);
  pinMode(sens2p, INPUT);

  Serial.begin(9600);
}

void loop() {
  int sens1 = digitalRead(sens1p);
  int sens2 = digitalRead(sens2p);
  
  if (sens1 == 0 || sens2 == 0){
    Serial.println("detected");
  }
  delay(400);
}
