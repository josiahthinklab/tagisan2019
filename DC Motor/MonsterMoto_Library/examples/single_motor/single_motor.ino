#include <MonsterMotor.h>

#define MOTOR1_PIN_ENABLE A0
#define MOTOR1_DIR1 7
#define MOTOR1_DIR2 8
#define MOTOR1_PWM 5

#define DELAY_TIME 300

MonsterMotor motor1 = MonsterMotor(MOTOR1_PIN_ENABLE, MOTOR1_DIR1, MOTOR1_DIR2, MOTOR1_PWM);

void setup() {

    Serial.begin(9600);

    motor1.setMaxPower(50);

    motor1.setDirection(CCW);

    motor1.setSpeed(0);
    motor1.stop();

    motor1.enable();

    printMotorValues();

    Serial.print("Enter any value to continue: ");

    while(!Serial.available());

    
}



void loop() {

    motor1.setDirection(CW);
    for(int i = 0; i <= 100; i++) {
        motor1.setSpeed(i);
        delay(DELAY_TIME);

        printMotorValues();

    }
    for(int i = 100; i >= 0; i--) {
        motor1.setSpeed(i);
        delay(DELAY_TIME);

        printMotorValues();
    }

    motor1.stop();

    motor1.setDirection(CCW);
    for(int i = 0; i <= 100; i++) {
        motor1.setSpeed(i);
        delay(DELAY_TIME);

        printMotorValues();

    }
    for(int i = 100; i >= 0; i--) {
        motor1.setSpeed(i);
        delay(DELAY_TIME);

        printMotorValues();
    }
    


}


void printMotorValues() {
    Serial.print("getMaxPower: ");
    Serial.println(motor1.getMaxPower());

    Serial.print("getDirection: ");
    Serial.println(motor1.getDirection());

    Serial.print("getSpeed: ");
    Serial.println(motor1.getSpeed());

    Serial.print("getState: ");
    Serial.println(motor1.getState());

    Serial.print("getPwmValue: ");
    Serial.println(motor1.getPwmValue());

    Serial.println();

}