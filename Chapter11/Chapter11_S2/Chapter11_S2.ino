#include <SoftwareSerial.h>
// INSTRUCTIONS FOR WRITING ADDITIONAL BELOW CODE
// include Fire Detector library if required

#define SIM800_RXD 2
#define SIM800_TXD 4
SoftwareSerial GSM_SIM800(SIM800_TXD, SIM800_RXD);
// INSTRUCTIONS FOR WRITING ADDITIONAL BELOW CODE
// Define Fire Detector object of required

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
  // from the Fire Detector’s documentation
  // Most often it would be reading the value of a digital
  // or analog pin using digitalRead() or analogRead() functions
  bool isFire = readFireDetector();
  
  // if a fire has been detected
  if (isFire)
  {
    // invoke function to send an SMS
    // REUSE the logic from this chapter
    sendAlertSMS();
  }
}