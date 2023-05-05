const int indexFlexPin = A0;  // Analog input pin for the flex sensor on the index finger 
const int middleFlexPin = A1;  // Analog input pin for the flex sensor on the middle finger 
const int ringFlexPin = A2;  // Analog input pin for the flex sensor on the ring finger 
const int pinkyFlexPin = A3;  // Analog input pin for the flex sensor on the pinky finger 
const int soundPin = 9;  // Digital output pin for the sound 
 
void setup() { 
  pinMode(soundPin, OUTPUT); 
} 
 
void loop() { 
  int indexFlexValue = analogRead(indexFlexPin);  // Read the flex sensor value on the index finger 
  int middleFlexValue = analogRead(middleFlexPin);  // Read the flex sensor value on the middle finger 
  int ringFlexValue = analogRead(ringFlexPin);  // Read the flex sensor value on the ring finger 
  int pinkyFlexValue = analogRead(pinkyFlexPin);  // Read the flex sensor value on the pinky finger 
  if (indexFlexValue < 500 && middleFlexValue > 500 && ringFlexValue > 500 && pinkyFlexValue > 500) {  // Check if the hand shape is a "B" 
    tone(soundPin, 440, 500);  // Output a tone with a frequency of 440 Hz for 500 milliseconds (half a second) 
    delay(500);  // Pause for 500 milliseconds (half a second) before checking the flex sensors again 
  } else { 
    noTone(soundPin);  // Stop the tone if the hand shape is not a "B" 
  } 
}
