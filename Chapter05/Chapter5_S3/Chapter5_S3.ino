//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
#include <SPI.h>            // For SD Card
#include <SD.h>             // For SD Card
// declare handles to the data logging file
File logFile;         // log file to which smoke detected events
                      // will be logged
File settingsFile;    // contains interval setting after which
                      // smoke detection function should be run
int smokePin = A5;
int buzzerPin = 8;

// 2 seconds by default, but will be changed through the value
// configured in the IntStng.txt file in the SD Card
int samplingInterval = 2000;
bool sdCardOK = false;

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup()
{
  // Initialize serial communication
  // wait for serial monitor window to connect via USB port
  Serial.begin(9600);
  while (!Serial) { ; }

  // Initialize the SD card
  // The SD object used below is available globally
  // The SD object is defined in the header files
  // Digital Pin 4 is used to enable the SD card
  if(!SD.begin(4))
  {
    Serial.println("There seems to be a problem with the SD card");
    Serial.println("Default sampling interval will be 2 seconds");
  }
  else
  {
    sdCardOK = true;
    // Read the sampling interval from SD Card
    samplingInterval = readSamplingIntervalSetting("IntStng.txt");
    Serial.print("Sampling Interval Found from SD Card = ");
    Serial.println(samplingInterval);
  }
  
  pinMode(smokePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
void loop()
{
  // Read the input at Arduino Uno’s Analog Pin A5.
  // As soon as smoke is detected, the reading should be above 325
  int value = analogRead(smokePin);
  if (value > 325)
  {
    Serial.println("Smoke detected...");
    // Log the event to the SD Card
    // data will be logged only if SD Card is available properly
    if(sdCardOK)
    {
      logDataToFile(value);
    }
    else
    {
      Serial.println("SD Card not proper, data not logged.");
    }

    // Ring the buzzer 5 times at half second intervals.
    tone(buzzerPin, 2000, 1000);
    delay(1000);
    tone(buzzerPin, 2000, 1000);
    delay(1000);
    tone(buzzerPin, 2000, 1000);
    delay(1000);
    tone(buzzerPin, 2000, 1000);
    delay(1000);
    tone(buzzerPin, 2000, 1000);
    delay(1000);
  }
  
  // Wait for the number of seconds as per settings file
  // in the SD card file IntStng.txt
  delay(samplingInterval);
}

void logDataToFile(int data)
{
  // open the data logging file
  logFile = SD.open("datalog.txt", FILE_WRITE);

  // if the log file opens successfully
  if (logFile)
  {
    // then write the measured parameters in the log
    logFile.println(data);
    Serial.println("Data logged");
    // the file should be closed after data logging
    logFile.close();
  }
  else
  {
    Serial.println("File datalog.txt could not be opened");
  }
}

int readSamplingIntervalSetting(String fileName)
{
  // This function will read and display pre-configured
  // settings from a settings file on the Serial Monitor window
  // Assumption: IntStng.txt file has only 1 line
  // and in that first line only an integer value is expected
  settingsFile = SD.open(fileName, FILE_READ);
  int iSetting = 0;
  
  // if the file was opened successfully
  if (settingsFile)
  {
    // read from the file one line at a time
    // this will go on until it reaches the end of the file
    int counter = 0;

    // this loop is designed to read only the
    // first character on the first line in the file
    while (settingsFile.available())
    {
      counter = counter + 1;
      iSetting = settingsFile.read();
      if(counter > 0) //first character has been read
      {
        break;        //break out of this while loop
      }
    }
    iSetting = 3 * 1000; // convert to milli seconds
    
    // close the file after reading is complete
    settingsFile.close();
  }
  else
  {
    // the file could not be opened
    Serial.println("Could not open IntStng.txt");
  }
  return iSetting;
}