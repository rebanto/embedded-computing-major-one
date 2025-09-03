int rgbLed1[] = {11, 10, 9};
int rgbLed2[] = {6, 5, 3};
int rgbLed3[] = {A5, A4, A3};
int rgbLed4[] = {A2, A1, A0};
int cButton = 8, javaButton = 7, phpButton = 4, pythonButton = 2;

void setup() {
  for (int pin : rgbLed1) {
    pinMode(pin, OUTPUT);
  }

  for (int pin : rgbLed2) {
    pinMode(pin, OUTPUT);
  }

  for (int pin : rgbLed3) {
    pinMode(pin, OUTPUT);
  }

  for (int pin : rgbLed4) {
    pinMode(pin, OUTPUT);
  }

  pinMode(cButton, INPUT);
  pinMode(javaButton, INPUT);
  pinMode(phpButton, INPUT);
  pinMode(pythonButton, INPUT);

  setAllLedColor(255);
}

void loop() {
  while (digitalRead(cButton) == HIGH){
    setAllLedColor(0);
    relay(75, 0);
  }

  while (digitalRead(javaButton) == HIGH){
    setAllLedColor(0);
    relay(500, 1);
  }

  while (digitalRead(phpButton) == HIGH){
    setAllLedColor(0);
    relay(500, 2);
  }

  while (digitalRead(pythonButton) == HIGH){
    setAllLedColor(0);
    relay(500, 3);
  }

  setAllLedColor(255);
}

void setAllLedColor(int color) {
  for (int pin : rgbLed1) {
    analogWrite(pin, color);
  }

  for (int pin : rgbLed2) {
    analogWrite(pin, color);
  }

  for (int pin : rgbLed3) {
    analogWrite(pin, color);
  }

  for (int pin : rgbLed4) {
    analogWrite(pin, color);
  }
}

void relay(int delayTime, int speed) {
  int speeds[4][3] = {{255, 0, 0}, {252, 148, 3}, {3, 144, 252}, {3, 7, 252}};

  analogWrite(rgbLed1[0], speeds[speed][0]);
  analogWrite(rgbLed1[1], speeds[speed][1]);
  analogWrite(rgbLed1[2], speeds[speed][2]);
  delay(delayTime);
  analogWrite(rgbLed1[0], 0);
  analogWrite(rgbLed1[1], 0);
  analogWrite(rgbLed1[2], 0);

  analogWrite(rgbLed2[0], speeds[speed][0]);
  analogWrite(rgbLed2[1], speeds[speed][1]);
  analogWrite(rgbLed2[2], speeds[speed][2]);
  delay(delayTime);
  analogWrite(rgbLed2[0], 0);
  analogWrite(rgbLed2[1], 0);
  analogWrite(rgbLed2[2], 0);

  analogWrite(rgbLed3[0], speeds[speed][0]);
  analogWrite(rgbLed3[1], speeds[speed][1]);
  analogWrite(rgbLed3[2], speeds[speed][2]);
  delay(delayTime);
  analogWrite(rgbLed3[0], 0);
  analogWrite(rgbLed3[1], 0);
  analogWrite(rgbLed3[2], 0);

  analogWrite(rgbLed4[0], speeds[speed][0]);
  analogWrite(rgbLed4[1], speeds[speed][1]);
  analogWrite(rgbLed4[2], speeds[speed][2]);
  delay(delayTime);
  analogWrite(rgbLed4[0], 0);
  analogWrite(rgbLed4[1], 0);
  analogWrite(rgbLed4[2], 0);
}
