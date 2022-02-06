int switchState = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
switchState = digitalRead(2);
if (switchState == LOW) {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
else {
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

  delay (1000); // wait for a quarter second
  // toggle the LEDs
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay (1000);
}
} // go back to the beginning of the loop
