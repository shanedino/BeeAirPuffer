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
    digitalWrite(LED_PIN, LOW);
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
  for (int i = 0; i < 5; i++) {
    Serial.print("Cycle ");
    Serial.println(i + 1);
  
  //Blink LED for 20 seconds
  Serial.println("Blinking LED for 20 seconds (set bee in arena)...");
  blinkLED(2000, 100);

  //Run motor for 4 seconds air puff to bee face
  Serial.println("Running airpuff...");
  digitalWrite(LED_PIN, HIGH);
  myMotor->run(FORWARD);
  delay(4000);
  myMotor->run(RELEASE);

  //Blink LED for 20 seconds
  Serial.println("Blinking LED for 20 seconds (let bee rest post puff)...");
  blinkLED(20000, 100);

  //LED solid ON for 5 seconds for loop repeat and bee replacement 
  Serial.println("LED solid ON for 5 seconds...");
  digitalWrite(LED_PIN, HIGH);
  delay(5000);
  digitalWrite(LED_PIN, LOW);

  delay(1000); //Turn off light so that theres a pause between puff trials
  }

  //Wait for button press to restart loop
  Serial.println("5 cycles completed. Waiting for button press to restart...");
  while (digitalRead(BUTTON_PIN) == HIGH) {
    // Waiting for button press (active LOW)
    delay(100);
  }
  
  Serial.println("Button pressed. Restarting 5-cycle sequence...");
  delay(500); //Debounce delay
}
