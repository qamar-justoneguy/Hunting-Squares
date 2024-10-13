#include "pid_controller.hpp"

PID::PID(float kp, float ki, float kd, float satMax, float satMin)
    : kp(kp), ki(ki), kd(kd), satMax(satMax), satMin(satMin) {}    

float PID::compute(float setPoint, float feedback, float dt)
{
    float error = setPoint - feedback;
    float derivativeError = (error - prevError) / dt;
    integralError += error * dt;

    float output = kp * error + ki * integralError + kd * derivativeError;

    output = (output > satMax) ? satMax : output;
    output = (output < satMin) ? satMin : output;

    // std::cout << setPoint << ' ' << feedback << ' ' << error << ' ' <<
    //      derivativeError << ' ' << integralError << ' ' << output << std::endl;

    prevError = error;

    return output;
}