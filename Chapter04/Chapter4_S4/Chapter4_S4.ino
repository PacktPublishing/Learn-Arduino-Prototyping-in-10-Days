//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
// Analog Pin A3 will be connected to the A0 pin
// from the soil moisture sensor
int moisturePin = A3;

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
  // Configure the A3 pin in input mode
  pinMode(moisturePin, INPUT);

  // Begin the serial connection so that
  // we can see the sensor measurements
  // on the Serial Monitor
  Serial.begin(9600);
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
void loop()
{
  // Read the value from the A3 pin
  int sensorValue = analogRead(moisturePin);

  // Display the value on the Serial Monitor
  Serial.print("Soil Moisture Reading: ");
  Serial.println(sensorValue);

  // Wait for 5 seconds and repeat the steps again
  delay(5000);
}