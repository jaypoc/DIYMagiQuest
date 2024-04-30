#define LED D5

void setupLED() {
    pinMode(LED, OUTPUT);
}

void ledOn(){
    digitalWrite(LED, HIGH);
}

void ledOff(){
    digitalWrite(LED, LOW);
}


void animateOn(){
  ledOn();
  delay(100);
  ledOff();
  delay(100);
  ledOn();
  delay(100);
  ledOff();
  delay(100);
  ledOn();
  delay(100);
  ledOff();
  delay(100);
  ledOn();
}

