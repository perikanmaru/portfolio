int LEDPIN = 13;
int ton=100;
int tu=300;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  int i=0;
  int k=0;
  int n=0;
  
  for(i=0;i<3;i++){
  digitalWrite(LEDPIN, HIGH);
  delay(ton);
  digitalWrite(LEDPIN,LOW);
  delay(ton);
  }
  
  delay(100);
  
  for(k=0;k<3;k++){
  digitalWrite(LEDPIN, HIGH);
  delay(tu);
  digitalWrite(LEDPIN,LOW);
  delay(tu);
  }
  delay(100);
  
  for(n=0;n<3;n++){
  digitalWrite(LEDPIN, HIGH);
  delay(ton);
  digitalWrite(LEDPIN,LOW);
  delay(ton);
  }

delay(1000);
  
}
