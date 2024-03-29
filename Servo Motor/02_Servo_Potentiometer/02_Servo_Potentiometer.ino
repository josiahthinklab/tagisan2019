#include <Servo.h>

#define PIN_POT A0

#define DELAY_TIME 15

Servo myservo;

void setup() {
  Serial.begin(57600);

  myservo.attach(9);

  Serial.println("Done Initialization");
}

void loop() {
  int analogValue = analogRead(A0);

  int servoAngle = map(analogValue, 0, 1023, 0, 180);

  myservo.write(servoAngle);

  Serial.print(analogValue);
  Serial.print(" ");
  Serial.println(servoAngle);

  delay(DELAY_TIME);
}
