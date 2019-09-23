#include <MonsterMotor.h>

#define DELAY_TIME 300

#define MOTOR1_PIN_ENABLE A0
#define MOTOR1_DIR1 7
#define MOTOR1_DIR2 8
#define MOTOR1_PWM 5

MonsterMotor motor1 = MonsterMotor(MOTOR1_PIN_ENABLE, MOTOR1_DIR1, MOTOR1_DIR2, MOTOR1_PWM);


#define MOTOR2_PIN_ENABLE A1
#define MOTOR2_DIR1 4
#define MOTOR2_DIR2 9
#define MOTOR2_PWM 6

MonsterMotor motor2 = MonsterMotor(MOTOR2_PIN_ENABLE, MOTOR2_DIR1, MOTOR2_DIR2, MOTOR2_PWM);

void setup() {

    Serial.begin(9600);

    motor1.setMaxPower(50);
    motor1.setDirection(CCW);
    // motor1.setSpeed(0);
    motor1.enable();

    motor2.setMaxPower(30);
    motor2.setDirection(CCW);
    // motor2.setSpeed(0);
    motor2.enable();

    Serial.print("Enter any value to continue: ");

    while(!Serial.available());
}



void loop() {

    motor1.setDirection(CW);
    motor2.setDirection(CCW);
    for(int i = 0; i <= 100; i++) {
        Serial.println(i);

        motor1.setSpeed(i);
        motor2.setSpeed(i);

        delay(DELAY_TIME);
    }
    for(int i = 100; i >= 0; i--) {
        Serial.println(i);
        
        motor1.setSpeed(i);
        motor2.setSpeed(i);

        delay(DELAY_TIME);
    }

    motor1.stop();
    motor2.stop();

    motor1.setDirection(CCW);
    motor2.setDirection(CW);
    for(int i = 0; i <= 100; i++) {
        Serial.println(i);
        
        motor1.setSpeed(i);
        motor2.setSpeed(i);

        delay(DELAY_TIME);

    }
    for(int i = 100; i >= 0; i--) {
        Serial.println(i);
        
        motor1.setSpeed(i);
        motor2.setSpeed(i);

        delay(DELAY_TIME);
    }


}