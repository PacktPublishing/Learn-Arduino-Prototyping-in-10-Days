//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
int motorPin = 3;       //this is a PWM capable pin
int buttonPin = 8;
int buttonState = LOW;

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}


//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/ 
void loop() 
{
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH)
  {
    analogWrite(motorPin, 160);   //run the motor
    delay(1000);
    analogWrite(motorPin, 0);   //stop the motor
  }
}