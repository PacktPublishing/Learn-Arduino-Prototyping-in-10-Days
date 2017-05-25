//**********************************************************/
// Step-1: Variables used in this sketch
//**********************************************************/
int LEDPin = 2;        // specify the digital pin number

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
  // initialize digital pins as an output.
  pinMode(LEDPin, OUTPUT);
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
// the loop function runs over and over again forever
void loop()
{
  digitalWrite(LEDPin, HIGH);   // turn LED 1 ON
  delay(1000);                  // wait for a second
  digitalWrite(LEDPin, LOW);    // turn LED 1 OFF
  delay(1000);                  // wait for a second
}