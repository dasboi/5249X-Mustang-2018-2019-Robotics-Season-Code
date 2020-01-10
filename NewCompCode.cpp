/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\hartmannd                                        */
/*    Created:      Sat Dec 14 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::motor LeftMotor        = vex::motor( vex::PORT20 );
vex::motor RightMotor       = vex::motor( vex::PORT8, true);
vex::motor ArmMotor         = vex::motor( vex::PORT11 );
vex::motor ClawMotor1       = vex::motor( vex::PORT10 );
vex::motor ClawMotor2       = vex::motor( vex::PORT12 , true);
vex::controller Controller1 = vex::controller();
vex::motor LiftMotor1       = vex::motor( vex::PORT7 );
vex::motor LiftMotor2       = vex::motor( vex::PORT1 , true);
vex::gyro ChassisGyro       = vex::gyro(Brain.ThreeWirePort.D);
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here


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
static void drive(double velocity, directionType dir, int inches){
      float degrees = inches * (360/12);

      LeftMotor.setVelocity(velocity, velocityUnits::pct);
      RightMotor.setVelocity(velocity, velocityUnits::pct);

      LeftMotor.rotateFor(dir, degrees, rotationUnits::deg, false);
      RightMotor.rotateFor(dir, degrees, rotationUnits::deg, false);
    }

static void liftRamp(){
      ArmMotor.setVelocity(100, percentUnits::pct);
      ArmMotor.spinFor(1200, rotationUnits::deg);
      task::sleep(1000);
    }

    static void dropRamp(){
      ArmMotor.setReversed(true);
      ArmMotor.spinFor(1200, rotationUnits::deg);
      ArmMotor.setReversed(false);
    }

    static void raiseArms(){
      LiftMotor1.setVelocity(100, velocityUnits::rpm);
      LiftMotor1.setVelocity(100, velocityUnits::rpm);
      LiftMotor1.spinFor(-200, rotationUnits::deg, false);
      LiftMotor2.spinFor(-200, rotationUnits::deg, false);
    }
    static void dropArms(){
      LiftMotor1.spinFor(200, rotationUnits::deg, false);
      LiftMotor2.spinFor(200, rotationUnits::deg, false);
    }

    static void stopIntake() {
      ClawMotor1.stop(brakeType::hold);
      ClawMotor2.stop(brakeType::hold);
    }
    static void startIntake() {
      ClawMotor1.setVelocity(200, velocityUnits::rpm);
      ClawMotor2.setVelocity(200, velocityUnits::rpm);
      ClawMotor1.spin(directionType::rev);
      ClawMotor2.spin(directionType::rev);
    }

    static void Intake() {
      ClawMotor1.setVelocity(200, velocityUnits::rpm);
      ClawMotor2.setVelocity(200, velocityUnits::rpm);
      ClawMotor1.spin(directionType::fwd);
      ClawMotor2.spin(directionType::fwd);
    }

    static void RemoveIntake() {
      ClawMotor1.setVelocity(50, velocityUnits::rpm);
      ClawMotor2.setVelocity(50, velocityUnits::rpm);
      ClawMotor1.spin(directionType::fwd);
      ClawMotor2.spin(directionType::fwd);
    }

    //Work on this my man DENNIS
static void turn(double velocity, bool right, int inches){
      float degrees = inches;

      LeftMotor.setVelocity(velocity, velocityUnits::pct);
      RightMotor.setVelocity(velocity, velocityUnits::pct);
      if(right == true){
        LeftMotor.rotateFor(directionType::fwd, degrees, rotationUnits::deg, false);
        RightMotor.rotateFor(directionType::rev, degrees, rotationUnits::deg, false);
      }else{
        LeftMotor.rotateFor(directionType::rev, degrees, rotationUnits::deg, false);
        RightMotor.rotateFor(directionType::fwd, degrees, rotationUnits::deg, false);
      }
    
}
void autonomous( void ) {
  raiseArms();
  vex::task::sleep(300);
  //turn(30, true, 340);
  startIntake();
  liftRamp();
  //vex::task::sleep(100);
  stopIntake();
  dropRamp();
  //vex::task::sleep(300);
  dropArms();
  Intake();
  drive(35, directionType::fwd, 40);
  vex::task::sleep(3000);
  stopIntake();
  turn(25, true, 580);
  vex::task::sleep(3000);
  drive(25, directionType::fwd, 40);
  vex::task::sleep(2500);
  liftRamp();
  vex::task::sleep(250);
  RemoveIntake();
  drive(20, directionType::rev, 15);
  
  
  //stopIntake();
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  //drive(100, directionType::fwd, 90);
  //vex::task::sleep(1000);
  //liftRamp();
  //vex::task::sleep(1000);
  //dropRamp();
  //raiseArms();
  //vex::task::sleep(1000);
  //startIntake();
  //vex::task::sleep(1000);
  //stopIntake();
  //liftRamp();
  //drive(50, directionType::rev, 24);

  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                howdy                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.
    int armSpeedPCT  = 60;
    int clawSpeedPCT = 200;

    LeftMotor.spin(vex::directionType::fwd,((Controller1.Axis3.value() + Controller1.Axis4.value() * .8)) , vex::velocityUnits::pct);
    RightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value()) *.8 , vex::velocityUnits::pct);

    if(Controller1.ButtonR1.pressing()) { 
        //...Spin the arm motor forward.
        LiftMotor1.spin(vex::directionType::rev, armSpeedPCT * .6, vex::velocityUnits::pct);
        LiftMotor2.spin(vex::directionType::rev, armSpeedPCT * .6, vex::velocityUnits::pct);
      }
      else
      if(Controller1.ButtonR2.pressing()){
        LiftMotor1.spin(vex::directionType::fwd, armSpeedPCT * .3, vex::velocityUnits::pct);
        LiftMotor2.spin(vex::directionType::fwd, armSpeedPCT * .3, vex::velocityUnits::pct);
      }else{
        LiftMotor1.stop(vex::brakeType::hold);
        LiftMotor2.stop(vex::brakeType::hold);
      }
      /*
      if(Controller1.ButtonR2.pressing()) { 
        //...Spin the arm motor forward.
        LiftMotor1.spin(vex::directionType::rev, armSpeedPCT, vex::velocityUnits::pct);
        LiftMotor2.spin(vex::directionType::rev, armSpeedPCT, vex::velocityUnits::pct);
      }else { 
        //...Stop the arm motor.
        LiftMotor1.stop(vex::brakeType::hold);
        LiftMotor2.stop(vex::brakeType::hold);
      }*/
      // else If the down button is pressed...
      if(Controller1.ButtonUp.pressing()) { 
        //...Spin the arm motor forward.
        ArmMotor.spin(vex::directionType::fwd, armSpeedPCT, vex::velocityUnits::pct);
      }
      else
      if(Controller1.ButtonDown.pressing()) { 
        //...Spin the arm motor backward.
        ArmMotor.spin(vex::directionType::rev, armSpeedPCT, vex::velocityUnits::pct);
      }
      // else If neither up or down button is pressed...
      else{
        //...Stop the arm motor.
        ArmMotor.stop(vex::brakeType::brake);
      }
      // Claw Control
      // If the A button is pressed...
      if(Controller1.ButtonA.pressing()) { 
        //...Spin the claw motor forward.
        ClawMotor1.spin(vex::directionType::fwd, clawSpeedPCT, vex::velocityUnits::pct);
        ClawMotor2.spin(vex::directionType::fwd, clawSpeedPCT, vex::velocityUnits::pct);
      }
      // else If the Y button is pressed..
      else 
      if(Controller1.ButtonY.pressing()) { 
        //...Spin the claw motor backward.
        ClawMotor1.spin(vex::directionType::rev, clawSpeedPCT, vex::velocityUnits::pct);
        ClawMotor2.spin(vex::directionType::rev, clawSpeedPCT, vex::velocityUnits::pct);
      }
      //se If neither the A or Y button is pressed...
      else {
        //...Stop the claw motor.
        ClawMotor1.stop(vex::brakeType::brake);
        ClawMotor2.stop(vex::brakeType::brake);        
      }
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  /*
    Brain.Screen.clearLine(0,color::black);
    Brain.Screen.clearLine(1,color::black);
    Brain.Screen.setCursor(1,0);
    //Brain.Screen.render(true,false);
    Brain.Screen.print("Arm rotation: %f degrees",ChassisGyro.value(rotationUnits::deg));
    */
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}
