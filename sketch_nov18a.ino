#define ledPin 6
#define sensorPin A0

void setup() {
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);  
  digitalWrite(ledPin, LOW); 
}

void loop() {
  int outputValue = readSensor();  
  

  Serial.print("Valor do Sensor: ");
  Serial.print(analogRead(sensorPin));  
  Serial.print(" -> Brilho do LED: ");
  Serial.println(outputValue);  
  
  delay(500); 
}


int readSensor() {
  int sensorValue = analogRead(sensorPin); 
  
  
  int outputValue = map(sensorValue, 0, 1023, 255, 0);
  
  analogWrite(ledPin, outputValue);  
  
  return outputValue;  
}