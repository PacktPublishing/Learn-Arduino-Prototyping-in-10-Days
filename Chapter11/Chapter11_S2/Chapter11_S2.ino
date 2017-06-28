#include <SoftwareSerial.h>
// INSTRUCTIONS FOR WRITING ADDITIONAL BELOW CODE
// include Fire Detector library if required

#define SIM800_RXD 2
#define SIM800_TXD 4
SoftwareSerial GSM_SIM800(SIM800_TXD, SIM800_RXD);
// INSTRUCTIONS FOR WRITING ADDITIONAL BELOW CODE
// Define Fire Detector object of required

// The number 1234567890 shown below
// should be replaced with the number to be called
String phoneNumber = "1234567890";

void setup()
{
  GSM_SIM800.begin(9600);
  delay(3000);
  // INSTRUCTIONS FOR WRITING ADDITIONAL BELOW CODE
  // Refer to fire detector documentation
  // and initialize the Fire Detector if required
}

void loop()
{
  // INSTRUCTIONS FOR WRITING ADDITIONAL BELOW CODE
  // Write a new function named readFireDetector()
  // Hint: Usually the logic is very simple and easily available
  // from the Fire Detector�s documentation
  // Most often it would be reading the value of a digital
  // or analog pin using digitalRead() or analogRead() functions
  bool isFire = readFireDetector();
  
  // if a fire has been detected
  if (isFire)
  {
    // invoke function to send an SMS
    // REUSE the logic from this chapter
    // uncomment the below line after copying the function
    // from the GSM reference sketch
    //sendAlertSMS();
  }
}

bool readFireDetector()
{
  // Hint: Usually the logic is very simple and easily available
  // from the Fire Detector's documentation
  // Most often it would be reading the value of a digital
  // or analog pin using digitalRead() or analogRead() functions

  // Use the following sample lines during implementation
  // Assuming the fire detector output is connected to D5
  // ----------------------------------------------------------
  int fireDetectorOutputPin = 5;
  bool isFire = false;
  pinMode(fireDetectorOutputPin, INPUT);
  isFire = digitalRead(fireDetectorOutputPin);
  //return isFire;  // uncomment this line
  return false;     // comment this line
}
