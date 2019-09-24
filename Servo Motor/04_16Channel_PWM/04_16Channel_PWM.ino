#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwmServoDriver = Adafruit_PWMServoDriver(0x40);

#define PIN_PWM_LED1 14
#define PIN_PWM_LED2 15

#define SERVO_ANGLE_MIN 0
#define SERVO_ANGLE_MAX 180

#define LED_BRIGHTNESS_MIN 0      // in percent
#define LED_BRIGHTNESS_MAX 100    // in percent

#define PIN_POT A0

void setup() {
  Serial.begin(57600);

  while (!Serial);

  pwmServoDriver.begin();
  pwmServoDriver.setPWMFreq(50);  // 50 Hz

  pinMode(PIN_POT, INPUT);
}

void loop() {
  int analogValue = analogRead(PIN_POT);

  // LED
  int ledBrightness = map(analogValue, 0, 1023, LED_BRIGHTNESS_MIN, LED_BRIGHTNESS_MAX);

  setPwmServoDrivePWM(pwmServoDriver, PIN_PWM_LED1, ledBrightness);
  setPwmServoDrivePWM(pwmServoDriver, PIN_PWM_LED2, ledBrightness);

  delay(50);
}


void setPwmServoDrivePWM(Adafruit_PWMServoDriver _pwmServoDriver, int _pinPWM, float _dutyCycle) {
  // _dutyCycle is from 0.0 to 100.0

  if (_dutyCycle < 0) _dutyCycle = 0;
  else if (_dutyCycle > 100) _dutyCycle = 100;
  
  const int COUNTER_MAX = 4095;
  
  // dutyCycle is in percent
  int counterOff = _dutyCycle * COUNTER_MAX / 100;
  _pwmServoDriver.setPWM(_pinPWM, 0, counterOff);
}
