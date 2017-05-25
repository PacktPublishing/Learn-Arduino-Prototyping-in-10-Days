#include <SoftwareSerial.h>

//Usage: object-name (RX-pin, TX-pin)
SoftwareSerial ESP8266 (6, 7);

void setup()
{
  // Configure the hardware and software Serial
  Serial.begin(9600);
  ESP8266.begin(9600);
}

// main program logic to run repeatedly
void loop()
{
  // keep checking for user input from the Serial Monitor window
  char cmd = Serial.read();
  if (cmd == '1') { AT(); }
  if (cmd == '2') { connectWifi(); }
  if (cmd == '3') { CIPSTART(); }
  if (cmd == '4') { CIPSEND(); }
  if (cmd == '5') { sendRequest(); }
  if (cmd == '6') { disconnectWifi(); }
}

// logic to check whether the ESP8266 chip is working properly
void AT()
{
  Serial.write("AT");
  ESP8266.write("AT\r\n");
  delay(1000);
  if(ESP8266.find("OK")) { Serial.println("OK"); }
  else { Serial.println("Not Working"); }
}

// logic to connect to Wi-Fi router
void connectWifi()
{
  Serial.println("Connecting to Wi-Fi ...");
  
  // Replace the Wi-Fi SSID and PASSWORD shown below
  // with the SSID and PASSWORD of your Wi-Fi network
  ESP8266.write("AT+CWJAP=\"SSID\",\"PASSWORD\"\r\n");
  delay(7000);
  Serial.println(ESP8266.readString());
}

// logic to initiate a new transmission to ThingSpeak IoT cloud
void CIPSTART()
{
  // You can use the below IP address as-is
  // Because this is the ThingSpeak IP address and will not change
  ESP8266.write("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n");
  delay(5000);
  Serial.println(ESP8266.readString());
}

// logic to specify data length to be transmitted
void CIPSEND()
{
  // The data length 46 was calculated for the request payload
  // GET /update?key=ID83C0GFDJM9B7GX&field1=56\r\n
  // This payload has been used in the function sendRequest()
  ESP8266.write("AT+CIPSEND=46\r\n");
  delay(3000);
  Serial.println(ESP8266.readString());
}

// logic to transmit data and signal end of transmission
void sendRequest()
{
  ESP8266.write("GET /update?key=ID83C0GFDJM9B7GX&field1=19\r\n");
  ESP8266.write("\r\n");
  delay(5000);
  Serial.println(ESP8266.readString());
}

// logic to disconnect from Wi-Fi
void disconnectWifi()
{
  ESP8266.write("AT+CWQAP\r\n");
  delay(2000);
  Serial.println(ESP8266.readString());
}
