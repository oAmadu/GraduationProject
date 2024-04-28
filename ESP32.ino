const int thumbPin = 32;
const int indexPin = 33;
const int middlePin = 27;
const int ringPin = 14;
const int pinkyPin = 12;

const char* thumbName = "Thumb";
const char* indexName = "Index";
const char* middleName = "Middle";
const char* ringName = "Ring";
const char* pinkyName = "Pinky";

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);  // Use Serial1 for communication with Arduino
}

void loop() {
  int thumbValue = analogRead(thumbPin);
  int indexValue = analogRead(indexPin);
  int middleValue = analogRead(middlePin);
  int ringValue = analogRead(ringPin);
  int pinkyValue = analogRead(pinkyPin);
  
  // Print flex sensor data in the format ##,##,##,##,##
  char buffer[50];
  sprintf(buffer, "%02d,%02d,%02d,%02d,%02d",
          thumbValue, indexValue, middleValue, ringValue, pinkyValue);
  Serial1.println(buffer);
  Serial.println(buffer);
  
  delay(1000); // Delay between readings
}
