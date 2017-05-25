//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // create LCD object

int trigPin = 8;
int echoPin = 7;

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
  // one time setup code
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
void loop()
{
  long duration, distance;

  // Signal a quick LOW just before giving a HIGH signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // After 2 micro-seconds of LOW signal, give a HIGH signal  
  // to trigger the sensor
  digitalWrite(trigPin, HIGH);
  // Keep the digital signal HIGH for
  // at least 10 micro-seconds
  // (required by HC-SR04 to activate emission of
  // ultra-sonic waves
  delayMicroseconds(10);

  // After 10 micro-seconds, signal a LOW
  digitalWrite(trigPin, LOW);

  // Now wait for the Ultra sonic echo to return from an 
  // obstacle
  duration = pulseIn(echoPin, HIGH);

  // Convert the distance to centimeters
  distance = (duration/2) / 29.1;

  // Print the distance on the Serial Monitor window
  Serial.print(distance);
  Serial.println(" cms");

  // Clear the LCD
  lcd.clear();
  // Set the cursor position
  lcd.setCursor(0, 0);

  // Print the distance on the LCD screen
  lcd.print("Distance (in cms):");
  lcd.setCursor(0, 1);
  lcd.print(distance);

  // Check for distance again
  delay(400);
}