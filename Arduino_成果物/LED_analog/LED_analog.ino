int LEDPIN = 9;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int pwm = 0;
  int k = 0;
  int m=0;
  for (k = 0; k < 255; k++) {
    analogWrite(LEDPIN, pwm);
    pwm++;
    delay(10);
    if (k == 254) {
      for (m=254;m>=0;m--) {
        analogWrite(LEDPIN, pwm);
        pwm = pwm - 1;
        delay(10);
      }
      k=0;
      pwm=0;
      delay(1000);
    }
  }
}
