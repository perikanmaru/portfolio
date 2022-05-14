#include<Servo.h>

Servo myservo;
void setup() {
  myservo.attach(9);
  myservo.write(0);
}

void loop() {
  int k = 0;
  int m = 0;
  for (k = 0; k < 180; k++) {
    myservo.write(k);
    delay(10);
  }
  for (m = 180; m > 0; m--) {
    myservo.write(m);
    delay(10);
  }
  k=0;
  m=0;
}
