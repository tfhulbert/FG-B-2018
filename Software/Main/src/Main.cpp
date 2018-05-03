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
RotationWrapper rotation = RotationWrapper();

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
    // if(ROBOT){
    //     robotMode.setDefault(defender);
    // }else{
    //     robotMode.setDefault(attacker);
    // }
    robotMode.setDefault(defender);

    // pinMode(13, OUTPUT);
    // digitalWrite(13, HIGH);
    // delay(500);
    // digitalWrite(13, LOW);
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

    // PLACEHOLDER DATA THAT NEEDS TO BE DONE
    xbeeData xdata = {{0, 0}, {0, 0}, false, false};

    /* Update Game Data */
    dc.updateData(cam.data, spi.lidars, light.data, xdata, imu.getHeading());

    /* Send and recieve Xbee Data */
    // xbee.updateData(dc.getXbeeData());

    // kicker.controlBall(20);

    motors.move(dc.calculate(defender));
    // moveControl ctrl = dc.calculate(defender);

    // Serial.print(spi.lidars.rightDist); Serial.print(" "); Serial.println(spi.lidars.leftDist);

    // Serial.print(ctrl.direction); Serial.print(" "); Serial.print(ctrl.speed); Serial.print(" "); Serial.println(ctrl.rotation);
}
