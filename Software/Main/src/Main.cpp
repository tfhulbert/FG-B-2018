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
#include <MotorMusic.h>
#include <Xbee.h>


/* NOTE Constructors are called in the .cpp file for each class */
RotationWrapper rotation = RotationWrapper();

void setup(){

    /* Begin Serial */
    #if DEBUG
        Serial.begin(9600);
    #endif

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
    #if ROBOT
        // O_bot
        robotMode.setDefault(attacker);
    #else
        // P2_bot
        robotMode.setDefault(defender);
    #endif

    // Dribbler Stuff - TODO
    // pinMode(13, OUTPUT);
    // digitalWrite(13, HIGH);
    // delay(500);
    // digitalWrite(13, LOW);
    // delay(3000);
    // kicker.controlBall(0, 100);
    // delay(2000);
}

void loop(){

    /* Get OpenMV7 Data */
    cam.getCamData(ATTACK_YELLOW);

    /* Get IR Data from ATMega */
    spi.getIRData();

    /* Update IMU */
    imu.update();

    /* Update Light */
    light.readLight();
    light.updateAngle();

    /* Send and recieve Xbee Data */
    xbee.update(dc.getXbeeData());

    // Serial.print("isConnected: "); Serial.println(xbee.isConnected());

    /* Update Game Data */
    dc.updateData(cam.data, spi.lidars, light.data, xbee.otherData, imu.getHeading(), robotMode.getMode());

    // kicker.controlBall(12);
    // kicker.kickBall();
    motors.move(dc.calculate());

    // moveControl ctrl = dc.calculate(attacker);
    // Serial.print(spi.lidars.frontDist); Serial.print(" "); Serial.println(spi.lidars.backDist);

    // Serial.print(ctrl.direction); Serial.print(" "); Serial.print(ctrl.speed); Serial.print(" "); Serial.println(ctrl.rotation);
    // Serial.println(imu.getHeading());
}
