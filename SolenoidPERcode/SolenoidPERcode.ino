#include <Wire.h>
#include <Adafruit_MotorShield.h>

#define LED_PIN 13
#define BUTTON_PIN 12
#define MOTOR_SPEED 75

byte ButtonRead = LOW;
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);   
 
void setup() {
  Serial.begin(9600);  // this will help with troubleshooting       
  AFMS.begin(); 
  pinMode(LED_PIN, OUTPUT); 
  pinMode(BUTTON_PIN, INPUT); 
  myMotor->setSpeed(110);  // this only needs to be defined once
}
 
void loop() {
  ButtonRead = digitalRead(BUTTON_PIN);
  if (ButtonRead == LOW){  
    Serial.print("button pressed: ");
    Serial.println(ButtonRead);
    delay(4000);
    Serial.print("Motor running forward");
    digitalWrite(LED_PIN, HIGH);
    myMotor->run(FORWARD);
    delay(4000);
    Serial.print("Motor stopping");
    myMotor->run(RELEASE);  // turn off the motor after 4 seconds
    digitalWrite(LED_PIN, LOW);
  }
}
