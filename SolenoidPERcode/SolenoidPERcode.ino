#include <Wire.h>
#include <Adafruit_MotorShield.h>
 
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
 
int ButtonValue = 4;  //holds the value received from the button connection
 
void setup() {
  Serial.begin(9600);  // this will help with troubleshooting          
  AFMS.begin();  
  
myMotor->setSpeed(255);  // this only needs to be defined once
}
 
void loop() {
ButtonValue = analogRead(A0);  // read the value from the button connected to pin A0
 myMotor->run(FORWARD);
if (ButtonValue > 10000){   // if the button value is above a certain threshold, do something, as per below
  Serial.print("button pressed: ");
  Serial.println(ButtonValue);
  delay(4000);
  // serial print button value so you know what’s going on
  Serial.print("Motor running forward");
  myMotor->run(FORWARD);
  delay(4000);
  Serial.print("Motor stopping");
  myMotor->run(RELEASE);  // turn off the motor after 4 seconds
  }  // the if/then loop stops here
 
}
