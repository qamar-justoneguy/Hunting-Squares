#pragma once

class PID
{
    public:
        PID(float kp, float ki, float kd, float satMax, float satMin);
        float compute(float setPoint, float feedback, float dt);

    private:
        float prevError = 0.0f;
        float integralError = 0.0f;
        float satMax = 10.0f;
        float satMin = -10.0f;
        float kp;
        float ki;
        float kd;

};