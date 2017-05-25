//**********************************************************/
// Step-1: Variables used in this sketch
//**********************************************************/
int LEDPin = 2;        // specify the digital pin number
int transistorPin = 5; // specify pin for switching ON
                       // the transistor base
 
//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
  pinMode(LEDPin, OUTPUT);        // Pin 2 as output
  pinMode(transistorPin, OUTPUT); // Pin 5 as output
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
// the loop function runs over and over again forever
void loop()
{
  digitalWrite(LEDPin, HIGH);      // turn LED 1 ON
  analogWrite(transistorPin, 200); // turn transitor ON
  delay(1000);                     // wait for a second
  digitalWrite(LEDPin, LOW);       // turn LED 1 OFF
  analogWrite(transistorPin, 0);   // turn transistor OFF
  delay(1000);                     // wait for a second
}
