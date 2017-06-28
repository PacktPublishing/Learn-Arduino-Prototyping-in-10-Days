// Include the software serial library
// Alternately you can directly use the hardware serial
// via (Arduino�s digital pins D0 and D1)
#include <SoftwareSerial.h>

// Define the two pins that will be connected
// between the Arduino Uno and the GSM module

// D2 is connected to RXD pin of the GSM module
// So D2 will be simulated as the Tx pin on the Arduino
#define SIM800_RXD 2

// D4 is connected to TXD pin of the GSM module
// So D4 will be simulated as the Rx pin on the Arduino
#define SIM800_TXD 4

// Define the object for using the software serial
// these two pins are used to transmit the AT commands
// from the Arduino board to the modem in the GSM module
// SYNTAX: SoftwareSerial obj(Arduino_Rx, Arduino_Tx)
SoftwareSerial GSM_SIM800(SIM800_TXD, SIM800_RXD);

// The number 1234567890 shown below
// should be replaced with the number to be called
String phoneNumber = "1234567890";

//Initialize the sketch for using the GSM module
void setup()
{
  // initialize the hardware serial
  // for communication with the Serial Monitor window
  Serial.begin(9600);

  // initialize the software serial
  // for communication with the GSM modem
  GSM_SIM800.begin(9600);
  
  // Wait for 3 seconds for the SIM800 module to initialize 
  delay(3000);
}

// Define the main logic of the main program loop
void loop()
{
  // read a character from the Serial Monitor window
  char ch = Serial.read();
  
  // if the character a is entered
  if (ch == 'a')
  {
    // invoke function to send an SMS
    sendAlertSMS();
  }

  // if the character b is entered
  if (ch == 'b')
  {
    // invoke the function to dial a phone number
    callNumber();
  }
}

// Logic to send SMS
void sendAlertSMS()
{
    Serial.println("Sending SMS...");
     
    // Issue AT command to set SMS format to ASCII characters
    GSM_SIM800.print("AT+CMGF=1\r\n");
    delay(1000);
   
    // Issue an AT command to send a new SMS to a phone number
    GSM_SIM800.print("AT+CMGS=\"" + phoneNumber + "\"\r\n");
    delay(1000);
     
    // Next step is to send SMS content to the modem
    // Note that this step does not use a separate AT command
    GSM_SIM800.print("This is an SMS");
    delay(1000);
     
    // The last AT command is to
    // send Ctrl+Z /ESC character sequence
    // to indicate to the GSM modem
    // that the SMS message is complete
    GSM_SIM800.print((char)26);
    delay(2000);

    // Get results of sending SMS
    // Print the results in the Serial Monitor window
    if(GSM_SIM800.available())
    {
      Serial.println(GSM_SIM800.read());
    }
  }

// Logic to call phone number
void callNumber()
{
   // Send AT command TD to the GSM modem
   // along with the number to be called
   Serial.println("Calling...");
   GSM_SIM800.print("ATD" + phoneNumber + ";\r\n" );
   
   // wait 10 seconds before the next loop
   delay(15000);

   // Issue an AT command to the GSM modem to disconnect the call
   GSM_SIM800.print("ATH\r\n"); 
}
