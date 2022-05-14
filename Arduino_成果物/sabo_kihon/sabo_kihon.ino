#include<Servo.h>

Servo myservo;
void setup() {
  myservo.attach(9);
  myservo.write(0);
}

void loop() {
  int k = 180;
  int m = 0;
    myservo.write(k);
    delay(10);
    myservo.write(m);
    delay(10);
}
