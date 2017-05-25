#include <SPI.h>
#include "RF24.h"

RF24 radio(8,7);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int msg[1];       // use this to receive integers
//char msg[1];    // use this to receive characters

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}

void loop()
{
  if (radio.available())
  {
    bool endOfMsg = false;
    while (!endOfMsg)
    {
      endOfMsg = radio.read(msg, 1);
      Serial.println (msg[0]);
    }
  }
}