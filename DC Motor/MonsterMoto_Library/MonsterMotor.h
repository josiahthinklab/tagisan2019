#ifndef MonsterMotor_h
#define MonsterMotor_h

#include "Arduino.h"

#define CW true
#define CCW false

class MonsterMotor {
    public:
        MonsterMotor(int _pinEnable, int _pinDir1, int _pinDir2, int _pinPwm);
        void setMaxPower(float _maxPowerPercent);
        float getMaxPower();

        void setDirection(bool _direction);
        bool getDirection();

        void setSpeed(float _speedPercent);
        float getSpeed();

        void stop();

        void enable();
        void disable();
        bool getState();
        
        int getPwmValue();

    private:
        int pinEnable;
        int pinDir1;
        int pinDir2;
        int pinPwm;

        int pwmValue;

        bool direction = CW;

        float maxPowerPercent = 20;
        float speedPercent = 0;

        bool state;

        void setPWM(float _dutyCycle);

        float mapFloat(float value, float fromLow, float fromHigh, float toLow, float toHigh);
};

#endif