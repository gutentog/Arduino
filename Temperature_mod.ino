const int sensorPin = A0;
const float baselineTemp = 24.20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open a serial port
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorVal);

  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0)*5.0; // converts sernosor value to voltage
  Serial.print("Volts: ");
  Serial.println(voltage);

  Serial.print("Degrees C: ");  
  float Temperature = (voltage -.5) * 100;  // convert the voltage to temperature in degrees 
  Serial.println(Temperature);

  if (Temperature < baselineTemp+2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if (Temperature >= baselineTemp+2 &&
  Temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }else if (Temperature >= baselineTemp+4 &&
  Temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
     }else if (Temperature >= baselineTemp+6) {
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
     
  }
  delay(5000);
}
