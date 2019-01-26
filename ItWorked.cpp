#include "robot-config.h"
void DriveDistance(int distance, int speed){
    //this fella needs to be changed so that it is 1:1
    double DistanceMultiplier = 1.000;
    double DistanceTheMotorHasToGo = distance * DistanceMultiplier;
    FrontLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
    FrontRightMotor.setVelocity(speed, vex::velocityUnits::pct);
    BackLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
    BackRightMotor.setVelocity(speed, vex::velocityUnits::pct);
    FrontLeftMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    FrontRightMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    BackLeftMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    BackRightMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
}
void rightDriveDistance(int distance, int speed){
    //this fella needs to be changed so that it is 1:1
    double DistanceMultiplier = 1.000;
    double DistanceTheMotorHasToGo = distance * DistanceMultiplier;
    FrontLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
    FrontRightMotor.setVelocity(speed, vex::velocityUnits::pct);
    BackLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
    BackRightMotor.setVelocity(speed, vex::velocityUnits::pct);
    FrontLeftMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    FrontRightMotor.rotateFor(-DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    BackLeftMotor.rotateFor(-DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    BackRightMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
}

void leftDriveDistance(int distance, int speed){
    //this fella needs to be changed so that it is 1:1
    double DistanceMultiplier = 1.000;
    double DistanceTheMotorHasToGo = distance * DistanceMultiplier;
    FrontLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
    FrontRightMotor.setVelocity(speed, vex::velocityUnits::pct);
    BackLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
    BackRightMotor.setVelocity(speed, vex::velocityUnits::pct);
    FrontLeftMotor.rotateFor(-DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    FrontRightMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    BackLeftMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    BackRightMotor.rotateFor(-DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
}
void backDriveDistance(int distance, int speed){
    //this fella needs to be changed so that it is 1:1
    double DistanceMultiplier = 1.000;
    double DistanceTheMotorHasToGo = distance * DistanceMultiplier;
    FrontLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
    FrontRightMotor.setVelocity(speed, vex::velocityUnits::pct);
    BackLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
    BackRightMotor.setVelocity(speed, vex::velocityUnits::pct);
    FrontLeftMotor.rotateFor(-DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    FrontRightMotor.rotateFor(-DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    BackLeftMotor.rotateFor(-DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
    BackRightMotor.rotateFor(-DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
}
//edit this so that it can turn
/*void Turn(int degrees, int speed, bool rightTurn, double distance){
    //this is for the speed in the other direction
    double gyroVal = ChassisGyro.value(vex::analogUnits::range12bit);
        Brain.Screen.printAt(1, 30, true, "Chassis Gyro: %f", gyroVal);
    int speedInOtherDirection = speed * -1;
    if (rightTurn == true){
    while(gyroVal < degrees){
        double gyroVal = ChassisGyro.value(vex::analogUnits::range12bit);
        Brain.Screen.printAt(1, 30, true, "Chassis Gyro: %f", gyroVal);
        if (gyroVal >= degrees - 6){
            break;
        }
        //needs to be set to speed
        FrontLeftMotor.spin(vex::directionType::fwd, speed,vex::velocityUnits::rpm);
        FrontRightMotor.spin(vex::directionType::rev, speed,vex::velocityUnits::rpm);
        BackLeftMotor.spin(vex::directionType::fwd, speed,vex::velocityUnits::rpm);
        BackRightMotor.spin(vex::directionType::rev, speed,vex::velocityUnits::rpm);
    }
        FrontLeftMotor.stop();
        FrontRightMotor.stop();
        BackLeftMotor.stop(); 
        BackRightMotor.stop();
   }else if (rightTurn == false){
    while(gyroVal > degrees){
        double gyroVal = ChassisGyro.value(vex::analogUnits::range12bit);
        Brain.Screen.printAt(1, 30, true, "Chassis Gyro: %f", gyroVal);
        if (gyroVal <= degrees + 90){
            break;
        }
        FrontLeftMotor.spin(vex::directionType::rev, speed,vex::velocityUnits::rpm);
        FrontRightMotor.spin(vex::directionType::fwd, speed,vex::velocityUnits::rpm);
        BackLeftMotor.spin(vex::directionType::rev, speed,vex::velocityUnits::rpm);
        BackRightMotor.spin(vex::directionType::fwd, speed,vex::velocityUnits::rpm);
    }    
        FrontLeftMotor.stop();
        FrontRightMotor.stop();
        BackLeftMotor.stop(); 
        BackRightMotor.stop();
   }
}
*/
void Lift(int degrees, int speed){
   LiftLeft.rotateFor(degrees,vex::rotationUnits::deg, speed, vex::velocityUnits::rpm);
   LiftRight.rotateFor(degrees,vex::rotationUnits::deg, speed, vex::velocityUnits::rpm);
   LiftLeft.stop(vex::brakeType::brake);
   LiftRight.stop(vex::brakeType::brake);
}

void BallShooterBasedOnSpeedInCaseWeHaveNoStandards(int speed){

}
void BallShooterMode(bool HighFlag){

}



int main() {
    DriveDistance(100, 200);
    vex::task::sleep(500);
    ClawMotor.spin(vex::directionType::fwd,200,vex::velocityUnits::rpm);
    vex::task::sleep(500);
    rightDriveDistance(350, 100);
    vex::task::sleep(500);
    DriveDistance(900, 100);
    //ChassisGyro.startCalibration();
    
    vex::task::sleep(500);
    //DriveDistance(100,200);
    vex::task::sleep(100);
    //backDriveDistance(100, 200);
    vex::task::sleep(500);
//Turn(-900, 50, false, 50);
//Turn(0, 50, true, 50);
}
