#include <Common.h>
#include <Structs.h>
#include <SPIWrapper.h>
#include <MotorArray.h>
#include <Common.h>
#include <Orbit.h>
#include <IMU.h>
#include <RotationWrapper.h>
#include <BallManager.h>
#include <CameraWrapper.h>
#include <DirectionController.h>
#include <Light.h>
#include <ModeWrapper.h>
// #include <Xbee.h>


/* NOTE Constructors are called in the .cpp file for each class */

void setup(){
    /* Begin Serial */
    // Serial.begin(9600);
    /* Init SPI */
    spi.initSPI();
    /* Init IMU */
    imu.init();
    /* Calibrate IMU for drift etc. */
    imu.calibrate();
    /* Init Lightsensors */
    light.init();
    /* Init Serial */
    cam.initSerial();
    /* Set robot mode based on default mode */
    /*
    if(ROBOT){
        robotMode.setDefault(defender);
    }else{
        robotMode.setDefault(attacker);
    }*/

    // pinMode(13, OUTPUT);
    // digitalWrite(13, HIGH);
    // delay(500);
    // digitalWrite(13, LOW);
}

void loop(){

    /* Get OpenMV7 Data */
    cam.getCamData(ATTACK_YELLOW);
    // Serial.println(cam.data.ballAngle);

    /* Get IR Data from ATMega */
    spi.getIRData();
    /* Update IMU */
    imu.update();

    /* Update Light */
    light.readLight();
    light.updateAngle();

    // PLACEHOLDER DATA THAT NEEDS TO BE DONE
    lidarData ldata = spi.lidars;
    xbeeData xdata = {{0, 0}, {0, 0}, false, false};

    /* Update Game Data */
    dc.updateData(cam.data, spi.lidars, light.data, xdata, imu.getHeading());

    /* Move based on mode and other data */
    // if(robotMode.getMode() == mode::defender){
        // directionController.calculateGoalie();
        // motors.move(dc.getDirection(), imu.getHeading(), dc.getSpeed(), false);
    // }else{
        // directionController.calculateAttack();
        // motors.move(dc.getDirection(), imu.getHeading(), dc.getSpeed(), dc.getFollowingBall());
    // }

    /* Send and recieve Xbee Data */
    // xbee.updateData(dc.getBallX(), dc.getBallY(), dc.getX(), dc.getY(), dc.getFollowingBall(), dc.getBallX() != 65506 ? 1 : 0);

    /* Update other robots data to direction Controller */
    // directionController.updateOtherData(xbee.OballX, xbee.OballY, xbee.OrobotX, xbee.OrobotY, xbee.OseeingBall == 1 ? true : false, xbee.OknowsPosition == 1 ? true : false);

    rotation.calculateRotation(imu.getHeading(), cam.data.yGoalAngle, 0);
    motors.move(orbit(cam.data.ballAngle, strengthToDistance(cam.data.ballStrength)), rotation.getRotation(), 75, true);
    // Serial.println(orbit(cam.data.ballAngle, strengthToDistance(cam.data.ballStrength)));
}
