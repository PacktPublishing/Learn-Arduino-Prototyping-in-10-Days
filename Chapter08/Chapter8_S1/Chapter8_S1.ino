//**********************************************************/
// Step-1: CONFIGURE VARIABLES
//**********************************************************/
int _pinD10 = 10;                  // pin 10 to receive input 
                                   // from sensor
int _pinD7 = 7;                    // pin 7 to send signal to 
                                   // relay
int _soundLevel = HIGH;            // variable for storing 
                                   // output of sensor
boolean _bRelayState = false;      // start by assuming OFF 
                                   // state
unsigned long _lastSoundEventTime; // variable to store the 
                                   // time  
                                   // of the last sound event
int _gapBetween2Sounds = 1000;     // gap between 2 sound 
                                   // events

//**********************************************************/
// Step-2: INITIALIZE I/O PARAMETERS
//**********************************************************/
void setup ()
{
  // configure the pins to be used for I/O
  pinMode (_pinD10, INPUT) ; // input from the sound sensor
  pinMode(_pinD7, OUTPUT);   // output to relay
}

//**********************************************************/
// Step-3: MAIN PROGRAM
//**********************************************************/
void loop ()
{
  _soundLevel = digitalRead (_pinD10) ; // read sound level
  if (_soundLevel == LOW)               // if a sound occurs
  {
    if (_bRelayState == false)          // if relay is in 
                                        // OPEN state
    {
      //if event is after at least 1 second of the previous 
      // event
      if( (millis()-_lastSoundEventTime)> _gapBetween2Sounds)
      {
        _lastSoundEventTime = millis(); // record event time
        _bRelayState = true;
        //Switch ON the Relay
        digitalWrite(_pinD7, 0);
      }
    }
    if (_bRelayState == true)        //if relay is already ON
    {
      //if event is after at least 1 second of the previous 
      // event
      if( (millis()-_lastSoundEventTime)> _gapBetween2Sounds)
      {
        _lastSoundEventTime = millis(); // record event time          
        _bRelayState = false;
        //Switch OFF the Relay
        digitalWrite(_pinD7, 1);
      }
    }
  }
}
