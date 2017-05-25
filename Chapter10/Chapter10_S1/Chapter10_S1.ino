#include <SPI.h>
#include "RF24.h"

int msg[1];	// use this for transmitting integers
//char msg[1];	// use this for transmitting characters

RF24 radio(8,7);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void)
{
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop(void)
{
  msg[0] = 1;      // integer will be sent
  //msg[0] = 'b';  // character will be sent
  radio.write(msg, 1);
}