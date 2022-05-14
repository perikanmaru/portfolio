int s = 0;
int LEDPIN = 2;
int SWITCHPIN = 12;
void setup()
{
  pinMode(LEDPIN, OUTPUT);
  pinMode(SWITCHPIN, INPUT);
}

void loop()
{
  if (digitalRead(SWITCHPIN) == LOW) {
    s = s + 1;
    if (s > 2)
      s = 0;
    delay(20);
    while (digitalRead(SWITCHPIN) == LOW) {}
  }
  if (s == 0) {
    digitalWrite(LEDPIN, LOW);
  }
  if (s == 1) {
    digitalWrite(LEDPIN, HIGH);
  }
  if (s == 2) {
    digitalWrite(LEDPIN, HIGH);
    delay(100);
    digitalWrite(LEDPIN, LOW);
    delay(100);
  }
}
