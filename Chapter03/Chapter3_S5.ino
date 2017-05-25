//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
int buttonPin = 7;          // D7 used to read input from button
int ledPin = 4;             // D4 used to control LED
int buttonState = LOW;      // Initialize state to LOW to start with

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup() 
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);  // D7 will receive input from button
  pinMode(ledPin, OUTPUT);    // D4 will send output to LED
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/ 
void loop() 
{
  buttonState = digitalRead(buttonPin);  // Read button state
  
  // If user presses the push button
  // Then state will be HIGH
  if(buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH);   // glow the LED
    delay(250);                  // wait for 1 second
    digitalWrite(ledPin, LOW);    // switch OFF the glowing LED
  }
  delay(1000);
}