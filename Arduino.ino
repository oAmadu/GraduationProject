
#include <Servo.h>

Servo thumbServo;
Servo indexServo;
Servo middleServo;
Servo ringServo;
Servo pinkyServo;

const int thumbPin = A0;
const int indexPin = A1;
const int middlePin = A2;
const int ringPin = A3;
const int pinkyPin = A4;

void setup() {
  thumbServo.attach(10);
  indexServo.attach(3);
  middleServo.attach(9);
  ringServo.attach(5);
  pinkyServo.attach(6);
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String sensorData = Serial.readStringUntil('\n');
    sensorData.trim(); // Remove leading/trailing whitespace
    
    Serial.println("Received sensor data: " + sensorData);
    
    // Extract flex sensor values from the received data
    int thumbValue = getValue(sensorData, ',', 0);
    int indexValue = getValue(sensorData, ',', 1);
    int middleValue = getValue(sensorData, ',', 2);
    int ringValue = getValue(sensorData, ',', 3);
    int pinkyValue = getValue(sensorData, ',', 4);

    
    // Scale down the values to the desired range
    thumbValue = map(thumbValue, 0, 2300, 0, 180);
    indexValue = map(indexValue, 0, 2300, 0, 180);
    middleValue = map(middleValue, 0, 2500, 0, 180);
    ringValue = map(ringValue, 0, 2300, 0, 180);
    pinkyValue = map(pinkyValue, 0, 2300, 0, 180);
    
    // Move the servos based on the flex sensor values
    thumbServo.write(thumbValue);
    indexServo.write(indexValue);
    middleServo.write(middleValue);
    ringServo.write(ringValue);
    pinkyServo.write(pinkyValue);
  }
}

int getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {
    0, -1
  };
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]).toInt() : 0;
}

void setServoAngles(int angle) {
  thumbServo.write(angle);
  indexServo.write(angle);
  middleServo.write(angle);
  ringServo.write(angle);
  pinkyServo.write(angle);
}
