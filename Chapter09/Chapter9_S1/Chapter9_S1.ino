// This sketch has been modified based on the original sketch
// written by Ken Shirriff
//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
#include <IRremote.h>
int RECV_PIN = 11;    // Specify the pin to read the
          // input from the IR Receiver OUT pin
IRrecv irrecv(RECV_PIN);  // Define the object for the
// IR receiver
decode_results results; // Define an object to store results

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
 Serial.begin(9600);    // Start serial communications
 irrecv.enableIRIn();     // Start the receiver
 Serial.println("Receiver Started...");
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
void loop()
{
 if (irrecv.decode(&results))
 {
   Serial.println(results.value, HEX);
   irrecv.resume(); // Receive the next value
 }
}
