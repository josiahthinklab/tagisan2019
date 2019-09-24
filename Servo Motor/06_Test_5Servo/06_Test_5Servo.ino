/**
 *  DO NOT RUN THIS PROGRAM USING A WEAK VOLTAGE SUPPLY FOR SERVO MOTORS 
 */


#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwmServoDriver = Adafruit_PWMServoDriver(0x40);

#define PIN_PWM_SERVO1 0
#define PIN_PWM_SERVO2 2
#define PIN_PWM_SERVO3 4
#define PIN_PWM_SERVO4 6
#define PIN_PWM_SERVO5 8

#define DELAY_TIME 3000

void setup() {
    Serial.begin(57600);

    pwmServoDriver.begin();
    pwmServoDriver.setPWMFreq(50);  // 50 Hz
}

void loop() {

    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO1, 0);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO2, 0);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO3, 0);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO4, 0);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO5, 0);
    delay(DELAY_TIME);

    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO1, 30);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO2, 30);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO3, 30);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO4, 30);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO5, 30);
    delay(DELAY_TIME);

    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO1, 60);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO2, 60);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO3, 60);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO4, 60);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO5, 60);
    delay(DELAY_TIME);

    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO1, 90);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO2, 90);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO3, 90);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO4, 90);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO5, 90);
    delay(DELAY_TIME);

    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO1, 120);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO2, 120);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO3, 120);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO4, 120);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO5, 120);
    delay(DELAY_TIME);

    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO1, 150);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO2, 150);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO3, 150);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO4, 150);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO5, 150);
    delay(DELAY_TIME);

    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO1, 180);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO2, 180);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO3, 180);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO4, 180);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO5, 180);
    delay(DELAY_TIME);

    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO1, 45);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO2, 45);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO3, 45);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO4, 45);
    setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO5, 45);
    delay(DELAY_TIME);
}


void setPwmSevoDriveServoAngle(Adafruit_PWMServoDriver _pwmServoDriver, int _pinServo, float _angle) {
    const int COUNTER_WIDTH_MIN = 150;    // 0 angle
    const int COUNTER_WIDTH_MAX = 470;    // 180 angle

    if (_angle < 0) _angle = 0;
    else if (_angle > 180) _angle = 180;

    int pulseWidth = map(_angle, 0, 180, COUNTER_WIDTH_MIN, COUNTER_WIDTH_MAX);

    Serial.println(pulseWidth);

    _pwmServoDriver.setPWM(_pinServo, 0, pulseWidth);
}
