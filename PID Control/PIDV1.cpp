/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Dennis                                           */
/*    Created:      Sun Jan 19 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "math.h"
#include <cmath>

vex::brain       brain;
vex::motor LeftMotor        = vex::motor( vex::PORT20 );
vex::motor RightMotor       = vex::motor( vex::PORT8, true);
vex::motor ArmMotor         = vex::motor( vex::PORT11 );
vex::motor ClawMotor1       = vex::motor( vex::PORT10 );
vex::motor ClawMotor2       = vex::motor( vex::PORT12 , true);
vex::controller Controller1 = vex::controller();
vex::motor LiftMotor1       = vex::motor( vex::PORT7 );
vex::motor LiftMotor2       = vex::motor( vex::PORT1 , true);

using namespace vex;
using namespace std;

static void PIDDrive(double wantedDistance){

  double Kp = .25;
  double Ki = 0;
  double Kd = 0;

  double integral;
  double derivative;
  double error;

  double previous_error = 0;

  double motorSpeed;
  double targetDistance = (90 * wantedDistance)/(M_PI);

  while(LeftMotor.rotation(rotationUnits::deg) < targetDistance){

    //some kind of conversion beteen degrees and radians to make linear distrance

    error = targetDistance - LeftMotor.rotation(rotationUnits::deg);
    integral = integral + error;

    if(error == 0){
      integral = 0;
    }

    //fabs is the absolte value method for doubles
    if(fabs(error) > 40){
      integral = 0;
    }

    derivative = error - previous_error;
    previous_error = error;

    motorSpeed = Kp*error + Ki*integral + Kd*derivative;

    LeftMotor.spin(vex::directionType::fwd, motorSpeed, vex::velocityUnits::rpm);
    RightMotor.spin(vex::directionType::fwd, motorSpeed, vex::velocityUnits::rpm);
    Brain.Screen.print("%f", error);

    printf( "error = %f\n", error);
  }
  LeftMotor.stop(vex::brakeType::brake);
  RightMotor.stop(vex::brakeType::brake);

  RightMotor.resetRotation();
  LeftMotor.resetRotation();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  PIDDrive(18);
  
}
