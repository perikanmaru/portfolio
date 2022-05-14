void setup()
{
     pinMode(2, OUTPUT);
}

void loop()
{
    if (digitalRead(12) == LOW) {
        digitalWrite(2, LOW);





        
    } else {
        digitalWrite(2, HIGH);

        digitalWrite(2, HIGH);
        delay(200);
        digitalWrite(2, LOW);
        delay(200);
    }
}
