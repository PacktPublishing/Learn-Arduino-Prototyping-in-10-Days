//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
int smokePin = 2;          // Digital Pin number 2 for 
                           // connecting the smoke sensor.
int buzzerPin = 8;         // Digital Pin number 8 for  
                           // connecting the buzzer.

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
  pinMode(smokePin, INPUT);  // Configure Digital Pin 2
                             // in input mode,
                             // for reading signals 
                             // from the smoke sensor.
  pinMode(buzzerPin, OUTPUT);// Configure Digital Pin 8
                             // for output mode,
                             // for sending signals
                             // to the buzzer.
  delay(5000);               // Wait for 5 seconds
                             // before sending any signals
                             // to the sensor.
                             // Although it is not required 
                             // by the smoke sensor’s
                             // datasheet;
                             // However, it is a good 
                             // practice to let the 
                             // sensor device stabilize
                             // for a few seconds before
                             // sending any signals to it.
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
void loop()
{
  // Read the input at Arduino Uno’s Digital Pin 8.
  // As soon as smoke is detected:-
  // (1) The onboard LED on the MQ2 gas sensor will glow, and
  // (2) a LOW signal will be received on Digital Pin 8
  if (digitalRead(smokePin) == LOW)
  {
    // Ring the buzzer 5 times at 30 second intervals.
    tone(buzzerPin, 500, 250);
    delay(500);
    tone(buzzerPin, 500, 250);
    delay(500);
    tone(buzzerPin, 500, 250);
    delay(500);
    tone(buzzerPin, 500, 250);
    delay(500);
    tone(buzzerPin, 500, 250);
    delay(500);
  }
  // Wait for 2 seconds and check again
  delay(2000);
}