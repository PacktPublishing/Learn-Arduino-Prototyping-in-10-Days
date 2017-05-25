//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
int photoDiodePin = A3;    // analog pin 3
                           // to measure voltage from
                           // photodiode

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup(void)
{
  Serial.begin(9600);       // begin serial connection
                            // so that out of this sketch
                            // can be received in Arduino’s
                            // Serial Monitor
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
void loop(void)
{
  // read the value at analog pin 3 to which the photodiode is connected
  int value = analogRead(photoDiodePin);
  // analogRead() function returns a number which is proportional to
  // Arduino Uno’s voltage which is between 0 – 5 volts
  // For example, 5.0 volts would return 1023
  // similarly 2.5 volts would return 511
  // Therefore the following calculation is used to convert the value
  // read from pin A3
  float voltage = (value / 1024.0) * 5.0;

  // The following statements is used to write text output to
  // Arduino Uno’s Serial Monitor window
  Serial.print("Sampled Voltage: ");
  Serial.println(voltage);

  // Wait for 2 seconds before sampling the value on pin A3
  delay(2000);
}
