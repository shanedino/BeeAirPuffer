#include <Wire.h>
#include <Adafruit_MotorShield.h>

#define LED_PIN 13
#define BUTTON_PIN 12
#define MOTOR_SPEED 75

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);   
 
void blinkLED(unsigned long duration, int blinkInterval) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration){
    digitalWrite(LED_PIN, HIGH);
    delay(blinkInterval);
    digitalWrite(LED_PIN, s);
    delay(blinkInterval);
  }
}

void setup() {
  Serial.begin(9600);  // this will help with troubleshooting       
  AFMS.begin(); 
  pinMode(LED_PIN, OUTPUT); 
  pinMode(BUTTON_PIN, INPUT); 
  myMotor->setSpeed(MOTOR_SPEED);  // this only needs to be defined once
}

void loop() {
  //Wait for button press to start sequence
  Serial.println("Place bee in arena, press button to start sequence.");

  while (digitalRead(BUTTON_PIN) == HIGH) {
    // Poll for button press (active LOW)
    delay(100);
  }
  Serial.println("Button pressed. Starting 5-cycle sequence.");

  for (int i = 0; i < 5; i++) {
    Serial.print("Cycle: ");
    Serial.println(i + 1);
  
    //Blink LED for 20 seconds
    Serial.println("Blinking LED for 20 seconds; let be acclimate to arena.");
    blinkLED(20000, 100);

    //Run motor for 4 seconds air puff to bee face
    Serial.println("Running airpuff...");
    digitalWrite(LED_PIN, HIGH);
    myMotor->run(FORWARD);
    delay(4000);
    myMotor->run(RELEASE);

    //Blink LED for 20 seconds
    Serial.println("Blinking LED for 20 seconds; let bee rest post puff.");
    blinkLED(20000, 100);

    //LED solid ON for period to replace bee
    Serial.println("LED solid ON for 10 seconds; remove and add new bee.");
    digitalWrite(LED_PIN, HIGH);
    delay(10000);
  }

  digitalWrite(LED_PIN, LOW);
}
