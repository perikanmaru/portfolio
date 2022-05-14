int LEDPIN = 2;
int SWITCHPIN = 12;
int i = 0;
int sw_LED = LOW;
int sw_pin = 0;

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  pinMode(SWITCHPIN, INPUT);
}

void fanction(SWITCHPIN) {
  int sw = 0;
  int tmp = 0;
  sw = digitalRead(SWITCHPIN);
  tmp = sw;

  if (sw == LOW && tmp == LOW) {
    ;
  } else if (sw == LOW && tmp == HIGH) {
    ;
  } else if (sw == HIGH && tmp == LOW) {
    if (sw_LED == LOW)
      sw_LED = HIGH;
    else
      sw_LED = LOW;
  } else if (sw == HIGH && tmp == HIGH) {
    ;
  }
  return sw_LED;
}
void loop() {
  if (fancion == HIGH) {
    do {
      ;
    } while (fanction == LOW);
  } else {
    do {
      digitalWrite(LEDPIN, HIGH);
      delay(200);
      digitalWrite(LEDPIN, LOW);
      delay(200);
    } while (fanction = !LOW);
  }
