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


//edit this so that it can turn
void Turn(int degrees, int speed, bool rightTurn){
    
    //this is for the speed in the other direction
    int speedInOtherDirection = speed * -1;
    
    if (rightTurn == true){
    while(ChasisGyro.value(vex::analogUnits::range8bit) < degrees){
        
        FrontLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
        FrontRightMotor.setVelocity(speed, vex::velocityUnits::pct);
        BackLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
        BackRightMotor.setVelocity(speed, vex::velocityUnits::pct);
        
        
        //needs to be set to speed
        FrontLeftMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
        FrontRightMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
        BackLeftMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
        BackRightMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
        
    }
   }else{
    while(ChasisGyro.value(vex::analogUnits::range8bit) > degrees){
         
        FrontLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
        FrontRightMotor.setVelocity(speed, vex::velocityUnits::pct);
        BackLeftMotor.setVelocity(speed, vex::velocityUnits::pct); 
        BackRightMotor.setVelocity(speed, vex::velocityUnits::pct);
        
        
        //needs to be set to speed
        FrontLeftMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
        FrontRightMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
        BackLeftMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
        BackRightMotor.rotateFor(DistanceTheMotorHasToGo, vex::rotationUnits::deg, false);
        
    }    
   }
}

void Lift(int degrees, int speed){
    
}

void BallShooterBasedOnSpeedInCaseWeHaveNoStandards(int speed){
    
}

void BallShooterMode(bool HighFlag){
    
}

int main() {

}
