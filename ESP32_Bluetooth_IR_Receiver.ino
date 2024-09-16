#include "BluetoothSerial.h"  // Include BluetoothSerial library

BluetoothSerial SerialBT;     // Create a BluetoothSerial object

#define IR_PIN 14 // Digital pin for IR receiver
 
#define MAXPULSE 65000 // the maximum pulse we'll listen for - 65 milliseconds is a long time
 
#define RESOLUTION 20 // accurate timing
 
// we will store up to 100 pulse pairs (this is -a lot-)
uint16_t pulses[200][2];  // pair is high and low pulse 
uint8_t currentpulse = 0; // index for pulses we're storing
 
void setup(void) {
  pinMode(IR_PIN, INPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32"); // Set the device name

  Serial.println("Bluetooth Device is Ready to Pair");
  Serial.println("Ready to decode IR!");
}
 
void loop(void) {
  uint16_t highpulse, lowpulse;  // temporary storage timing
  highpulse = lowpulse = 0; // start out with no pulse length
  
  while (digitalRead(IR_PIN) == HIGH) {
    // pin is still HIGH
 
    // count off another few microseconds
    highpulse++;
    delayMicroseconds(RESOLUTION);
 
    // If the pulse is too long, we 'timed out' - either nothing
    // was received or the code is finished, so print what
    // we've grabbed so far, and then reset
    if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
      printpulses();
      currentpulse = 0;
      return;
    }
  }
  // we didn't time out so let's stash the reading
  pulses[currentpulse][0] = highpulse;
  
  // same as above
  while (digitalRead(IR_PIN) == LOW) {
    // pin is still LOW
    lowpulse++;
    delayMicroseconds(RESOLUTION);
    if ((lowpulse >= MAXPULSE) && (currentpulse != 0)) {
      printpulses();
      currentpulse = 0;
      return;
    }
  }
  pulses[currentpulse][1] = lowpulse;
 
  // we read one high-low pulse successfully, continue!
  currentpulse++;
}

void printpulses(void) {

  String dataToSend = "";

  // Append first value outside the loop to avoid trailing comma
  dataToSend += String(9360);

  for (uint8_t i = 1; i < currentpulse; i++) {
    dataToSend += ", ";
    dataToSend += String(pulses[i][0] * RESOLUTION);
    dataToSend += ", ";
    dataToSend += String(pulses[i][1] * RESOLUTION);
  }

  // Send the entire string at once
  Serial.println(dataToSend);
  SerialBT.println(dataToSend);
}