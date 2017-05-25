// include header files
String _inputString = "";
int _num = 0;

void setup()
{
   Serial.begin(9600);
   pinMode(13, OUTPUT);
}

void loop()
{
   if(Serial.available())
   {
     while(Serial.available())
     {
       //read the input from bluetooth serial
        char _ch = (char)Serial.read(); 
        _inputString += _ch;
     }
     
     _num = _inputString.toInt();
     if (_num > 0 && _num < 3)
     {
       // blink the onboard LED
       for (int i = 0; i < _num; i++)
       {
          digitalWrite(13, HIGH);  
          delay(500);
          digitalWrite(13, LOW);
          delay(500);
       }
     }
   }
   
   _inputString = "";
   _num = 0;
}
