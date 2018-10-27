#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.

vex::competition    Competition;
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void autonomous( void ) {
  // ..........................................................................

  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

//a method for controlling the lift that takes in a boolean value to determine the direction the lift will go 
void ControllerLift(bool up){
  if (up){
    LiftLeft.spin(vex::directionType::fwd);
    LiftRight.spin(vex::directionType::fwd);
  }else{
    //make sure the syntax is right, not sure what the name for reverse is
                                
    LiftLeft.spin(vex::directionType::rev);
    LiftRight.spin(vex::directionType::rev);

  }
}

void usercontrol( void ) {

  // User control code here, inside the loop
  while (true) {

    //this if statement is checking the lower right bumper is being pressed, if so, 

    //the CotrollerLift method will cause the lift to go up.
/*
if (Controller.ButtonR2.pressing()){
    LiftLeft.spin(vex::directionType::fwd);
    LiftRight.spin(vex::directionType::fwd);
    }else{
    //LiftLeft.stop(vex::brakeType::hold);
Motor.spin(vex::directionType::fwd,50,vex::velocityUnits::rpm);    //LiftRight.stop(vex::brakeType::hold);
    }
*/
if (Controller.ButtonL2.pressing()){
    LiftLeft.spin(vex::directionType::fwd,200,vex::velocityUnits::rpm);
    LiftRight.spin(vex::directionType::fwd,200,vex::velocityUnits::rpm);
    }else{
    LiftLeft.stop(vex::brakeType::hold);
    LiftRight.stop(vex::brakeType::hold);
    }
     
if (Controller.ButtonR2.pressing()){
    LiftLeft.spin(vex::directionType::rev,200,vex::velocityUnits::rpm);
    LiftRight.spin(vex::directionType::rev,200,vex::velocityUnits::rpm);
    }else{
    //LiftLeft.stop(vex::brakeType::hold);
    //LiftRight.stop(vex::brakeType::hold);
    }

      

    //this block of code is waht makes the x-drive move in all directions
    FrontLeftMotor.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value() + Controller.Axis4.value(), vex::velocityUnits::pct);
    FrontRightMotor.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value() - Controller.Axis4.value(), vex::velocityUnits::pct);
    BackLeftMotor.spin(vex::directionType::fwd, Controller.Axis3.value() + Controller.Axis1.value() - Controller.Axis4.value(), vex::velocityUnits::pct);
    BackRightMotor.spin(vex::directionType::fwd, Controller.Axis3.value() - Controller.Axis1.value() + Controller.Axis4.value(), vex::velocityUnits::pct);
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.
    // ........................................................................



    // Insert user code here. This is where you use the joystick values to 



          // update your motors, etc.



    // ........................................................................
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}
//

//Controller.Screen.clearLine(1);// Main will set up the competition functions and callbacks.
int main() {
    //Run the pre-autonomous function.
    pre_auton();
    //Set up callbacks for autonomous and driver control periods
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    //Prevent main from exiting with an infinite loop.                        
    while(1) {

      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.

    }    
}
