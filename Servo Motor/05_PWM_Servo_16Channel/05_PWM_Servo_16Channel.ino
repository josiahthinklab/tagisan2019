#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwmServoDriver = Adafruit_PWMServoDriver(0x40);

#define PIN_POT A0

#define PIN_PWM_SERVO1 8
#define PIN_PWM_SERVO2 9

#define PIN_PWM_LED1 14
#define PIN_PWM_LED2 15

#define SERVO_ANGLE_MIN 0
#define SERVO_ANGLE_MAX 180

#define LED_BRIGHTNESS_MIN 0      // in percent
#define LED_BRIGHTNESS_MAX 100    // in percent

void setup() {
  Serial.begin(57600);

  while (!Serial);

  pwmServoDriver.begin();
  pwmServoDriver.setPWMFreq(50);  // 50 Hz

  pinMode(PIN_POT, INPUT);
}

void loop() {
  int analogValue = analogRead(PIN_POT);

  // SERVO
  int servoAngle = map(analogValue, 0, 1023, SERVO_ANGLE_MIN, SERVO_ANGLE_MAX);

  setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO1, servoAngle);
  setPwmSevoDriveServoAngle(pwmServoDriver, PIN_PWM_SERVO2, servoAngle);

  // LED
  int ledBrightness = map(analogValue, 0, 1023, LED_BRIGHTNESS_MIN, LED_BRIGHTNESS_MAX);

  setPwmServoDrivePWM(pwmServoDriver, PIN_PWM_LED1, ledBrightness);
  setPwmServoDrivePWM(pwmServoDriver, PIN_PWM_LED2, ledBrightness);

  delay(50);
}


void setPwmServoDrivePWM(Adafruit_PWMServoDriver _pwmServoDriver, int _pinPWM, float _dutyCycle) {
  const int COUNTER_MAX = 4095;

  if (_dutyCycle < 0) _dutyCycle = 0;
  else if (_dutyCycle > 100) _dutyCycle = 100;
  
  // dutyCycle is in percent
  int counterOff = _dutyCycle * COUNTER_MAX / 100;
  _pwmServoDriver.setPWM(_pinPWM, 0, counterOff);
}


void setPwmSevoDriveServoAngle(Adafruit_PWMServoDriver _pwmServoDriver, int _pinServo, float _angle) {
  const int COUNTER_WIDTH_MIN = 150;
  const int COUNTER_WIDTH_MAX = 470;

  int pulseWidth = map(_angle, SERVO_ANGLE_MIN, SERVO_ANGLE_MAX, COUNTER_WIDTH_MIN, COUNTER_WIDTH_MAX);

  Serial.println(pulseWidth);

  _pwmServoDriver.setPWM(_pinServo, 0, pulseWidth);
}
