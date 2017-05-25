#include <Servo.h> 	// Arduino header file for servo motor

Servo servo;		// Servo motor object

int leftButton = 7;	// pin for reading left button state
int servoPin = 9;	// pin for sending signals to the servo motor
int rightButton = 2;	// pin for reading right button state

int angle = 0;   		// to track servo position in degrees 
bool leftPressed = false;  	// flag to track pressed button
bool rightPressed = false; 	// flag to track pressed button

void setup() 
{ 
  Serial.begin(9600);
  servo.attach(servoPin);	// specify the pin for controlling
					// the Servo motor
} 
 
void loop() 
{
  // do not press both buttons at once
  // otherwise the sketch logic will get confused
  leftPressed = digitalRead(leftButton);
  rightPressed = digitalRead(rightButton);
  
  if(leftPressed)
  {
    decreaseAngle();
    Serial.println("left");
    Serial.println(angle);
  }

  if(rightPressed)
  {
    increaseAngle();
    Serial.println("right");
    Serial.println(angle);
  }
}

void decreaseAngle()
{
  // decrease angle
  if (angle > 10)
  {
    angle = angle - 5;    
    servo.write(angle);
    delay(1000);           
  }
}

void increaseAngle()
{
  // increase angle
  if (angle < 170)
  {
    angle = angle + 5;    
    servo.write(angle);           
    delay(1000);
  } 
}