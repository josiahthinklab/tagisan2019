#include "MonsterMotor.h"


MonsterMotor::MonsterMotor(int _pinEnable, int _pinDir1, int _pinDir2, int _pinPwm) {
    pinEnable = _pinEnable;
    pinDir1 = _pinDir1;
    pinDir2 = _pinDir2;
    pinPwm = _pinPwm;

    pinMode(pinEnable, OUTPUT);
    pinMode(pinDir1, OUTPUT);
    pinMode(pinDir2, OUTPUT);
    pinMode(pinPwm, OUTPUT);

    setSpeed(0.0);
    disable();
}


void MonsterMotor::setMaxPower(float _maxPowerPercent) {
    maxPowerPercent = _maxPowerPercent;

    if (maxPowerPercent > 100) maxPowerPercent = 100;

    else if (maxPowerPercent < 0) maxPowerPercent = 0;

    setSpeed(speedPercent);
}


float MonsterMotor::getMaxPower() {
    return maxPowerPercent;
}


void MonsterMotor::setDirection(bool _direction) {

    direction = _direction;

    if (direction) {
        digitalWrite(pinDir1, HIGH);
        digitalWrite(pinDir2, LOW);

    }
    else {
        digitalWrite(pinDir1, LOW);
        digitalWrite(pinDir2, HIGH);
    }

}


bool MonsterMotor::getDirection() {
    return direction;
}

void MonsterMotor::setSpeed(float _speedPercent) {

    speedPercent = _speedPercent;

    if (speedPercent > 100) speedPercent = 100;
    else if (speedPercent <= 0) speedPercent = 0;

    float dutyCycle = maxPowerPercent * speedPercent / 100;

    setPWM(dutyCycle);
}

float MonsterMotor::getSpeed() {
    return speedPercent;
}

void MonsterMotor::stop() {
    setSpeed(0.0);
}


void MonsterMotor::enable() {
    state = true;

    digitalWrite(pinEnable, HIGH);
}

void MonsterMotor::disable() {
    state = false;

    digitalWrite(pinEnable, LOW);
}

bool MonsterMotor::getState() {
    return state;
}

int MonsterMotor::getPwmValue() {
    return pwmValue;
}



float MonsterMotor::mapFloat(float value, float fromLow, float fromHigh, float toLow, float toHigh) {
  return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow; 
}

void MonsterMotor::setPWM(float _dutyCycle) {

    int pwmVal = mapFloat(_dutyCycle, 0, 100, 0, 255);

    if (pwmVal > 255) pwmVal = 255;
    else if (pwmVal < 0) pwmVal = 0;

    analogWrite(pinPwm, pwmVal);

    pwmValue = pwmVal;
}


