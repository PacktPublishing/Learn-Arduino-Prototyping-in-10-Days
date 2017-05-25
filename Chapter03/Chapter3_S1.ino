// Step-1: No variables are used in this sketch

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
  // initialize digital pins as an output.
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);

}
//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
// the loop function runs over and over again forever
void loop()
{
  digitalWrite(2, HIGH);   // turn LED 1 ON
  delay(1000);             // wait for a second
  digitalWrite(2, LOW);    // turn LED 1 OFF
  delay(1000);             // wait for a second

  digitalWrite(4, HIGH);   // turn LED 2 ON
  delay(1000);             // wait for a second
  digitalWrite(4, LOW);    // turn LED 2 OFF
  delay(1000);             // wait for a second

  digitalWrite(7, HIGH);   // turn LED 3 ON
  delay(1000);             // wait for a second
  digitalWrite(7, LOW);    // turn LED 3 OFF
  delay(1000);             // wait for a second
}