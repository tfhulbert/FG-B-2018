#include <MotorArray.h>

MotorArray motors = MotorArray();

MotorArray::MotorArray(){
    /* Motor Array Constructor */
}

void MotorArray::move(double angle, double rotation, int speed, bool boost){
    /* Calculate motor pwm values to move the robot on a certain angle */
    if(angle != 65506.00){
        for(int i = 0; i < 4; i++){
            motorSpeeds[i] = (cos(((motorAngles[i] + 90 - angle) * angToRad)));
        }
        scale = 255/doubleAbs(fmax(fmax(fmax(doubleAbs(motorSpeeds[0]), doubleAbs(motorSpeeds[1])), doubleAbs(motorSpeeds[2])), doubleAbs(motorSpeeds[3])));
        for(int i = 0; i < 4; i++){
            motorSpeeds[i] = (motorSpeeds[i] * scale) + rotation*2.5;
        }
        scale = 255/doubleAbs(fmax(fmax(fmax(doubleAbs(motorSpeeds[0]), doubleAbs(motorSpeeds[1])), doubleAbs(motorSpeeds[2])), doubleAbs(motorSpeeds[3])));
        for(int i = 0; i < 4; i++){
            // motorSpeeds[i] = (motorSpeeds[i] * scale)/100 * isFrontal(angle) && boost ? FORWARD_SPEED : speed;
            motorSpeeds[i] = (motorSpeeds[i] * scale)/100 * speed;
        }
    }else{
        for(int i = 0; i < 4; i ++){
            motorSpeeds[i] = rotation;
        }
    }

    motorA.set(motorSpeeds[0]);
    motorB.set(motorSpeeds[1]);
    motorC.set(motorSpeeds[2]);
    motorD.set(motorSpeeds[3]);
}

int MotorArray::sign(double value) {
    return value >= 0 ? 1 : -1;
}

double MotorArray::doubleAbs(double value) {
    return value * sign(value);
}
