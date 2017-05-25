//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
int motorPin = 3;       //this is a PWM capable pin
int buttonPin = 8;      //button to start at low speed
int buttonPin2 = 7;     //button to start at high speed
int buttonPin3 = 2;     //button to stop
int buttonState = LOW;
int buttonState2 = LOW;
int buttonState3 = LOW;
//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup() 
{ 
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}
//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/ 
void loop() 
{
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
  if(buttonState == HIGH)
  {
    Serial.println("button 1");
    delay(1000);
    analogWrite(motorPin, 170);   //run at low speed
  }
  else if(buttonState2 == HIGH)
  {
    Serial.println("button 2");
    delay(1000);
    analogWrite(motorPin, 240);   //run at high speed
  }
  else if(buttonState3 == HIGH)
  {
    Serial.println("button 3");
    delay(1000);
    analogWrite(motorPin, 0);   //stop the motor
  }
}