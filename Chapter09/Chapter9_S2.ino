//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
#include <IRremote.h>
IRsend My_Sender;

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
  Serial.begin(9600);
}
 
//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
void loop()
{
  char cmd = Serial.read();
  
  // Enter letter 'l' or 'L' to increase sound
  if ( cmd == 'l' || cmd == 'L' ) 
  {
    //My_Sender.sendNEC(0xE244, 16); // Slow response in TV
    My_Sender.sendNEC(0xE244E244, 32);   // Fast response in TV
    My_Sender.sendNEC(0xFFFFFFFF, 32);
    My_Sender.sendNEC(0xFFFFFFFF, 32);
  }

  // Enter letter 'a' or 'A' to decrease sound
  if (cmd == 'a' || cmd == 'A')
  {
    //My_Sender.sendNEC(0xE254, 16);   // Slow response in TV
    My_Sender.sendNEC(0xE254E254, 32); // Fast response in TV
    My_Sender.sendNEC(0xFFFFFFFF, 32);
    My_Sender.sendNEC(0xFFFFFFFF, 32);
  }
}