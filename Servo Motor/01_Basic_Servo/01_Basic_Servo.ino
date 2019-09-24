#include <Servo.h>

#define DELAY_TIME 3000

Servo myservo;

void setup() {
    Serial.begin(57600);

    myservo.attach(9);

    Serial.println("Done Initialization");
}

void loop() {
    myservo.write(0);
    delay(DELAY_TIME);

    myservo.write(30);
    delay(DELAY_TIME);

    myservo.write(90);
    delay(DELAY_TIME);

    myservo.write(180);
    delay(DELAY_TIME);

    myservo.write(45);
    delay(DELAY_TIME);
}
