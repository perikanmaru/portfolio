int LEDPIN=9;

void setup() {
  // put your setup code here, to run once:
pinMode(LEDPIN,OUTPUT);
pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adval=0;
  int pwm=0;
  adval=analogRead(A0);
  pwm=adval/4;
    analogWrite(LEDPIN, pwm);
}
