//**********************************************************/
// Step-1: Variables used in this sketch
//**********************************************************/
//The following frequency values for musical notes have been
//collected from the Arduino Foundation website
//address mentioned below
//https://www.arduino.cc/en/Tutorial/ToneKeyboard?from=Tutorial.Tone3
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494

int pin = 6;          // the pin used to send signals to the buzzer


//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
  // no special setup related code in this example
}


//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
// the loop function runs over and over again forever
void loop()
{
  tone(pin, NOTE_C4, 500);
  delay(1000);
  tone(pin, NOTE_D4, 500);
  delay(1000);
  tone(pin, NOTE_E4, 500);
  delay(1000);
  tone(pin, NOTE_F4, 500);
  delay(1000);
  tone(pin, NOTE_G4, 500);
  delay(1000);
  tone(pin, NOTE_A4, 500);
  delay(1000);
  tone(pin, NOTE_B4, 500);
  delay(1000);
}