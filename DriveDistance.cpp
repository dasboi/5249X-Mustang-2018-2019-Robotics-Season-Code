#include "robot-config.h"
#include "math.h" //Include math.h in order to gain access to math functions like PI. 

int main() {
     vex::task::sleep(2000); //Wait 2 seconds or 2000 milliseconds before starting the program.
     //Print to the screen that the program has started.
     Brain.Screen.print("User Program has Started.");
    
    //Define variables. You may need to change these variables for this program to work for your robot.
    double wheelDiameterCM  = 10.16; //wheelDiameter is the measurement of a wheel from edge to edge in centimeters.
    double travelTargetCM = 90; //travelTarget will define how far we want the robot to move in centimeters.
    
    //Calculate wheel circumferance: circumference = (wheelDiameter)(PI)
    double circumference = wheelDiameterCM * M_PI; //Note that M_PI is from the math library which is included on line 14.    
    //Now we know the robot will travel the Circumference per 360 degrees of rotation or (circumference / 360 degrees).
    //We also know that are target distance is defined as travelTargetCM, but we do not know the degrees to of rotation. (traveTargetCM / ?)
    //Using propotional reasoning we know (circumference / 360) = (travelTarget / degreesToRotate).
    //Solving for our unkown (degreesToRotate) we get:
    double degreesToRotate = (360 * travelTargetCM) / circumference; //All calculations are complete. Start the rest of the program.
    
    //Set the velocity of the left and right motor to 50% power. This command will not make the motor spin.
    FrontLeftMotor.setVelocity(50, vex::velocityUnits::pct); 
    FrontRightMotor.setVelocity(50, vex::velocityUnits::pct);
    BackLeftMotor.setVelocity(50, vex::velocityUnits::pct); 
    BackRightMotor.setVelocity(50, vex::velocityUnits::pct);

    
    
    //Rotate the Left and Right Motor for degreesToRotate. 
    FrontLeftMotor.rotateFor(degreesToRotate, vex::rotationUnits::deg, false); //This command must be non blocking.
    FrontRightMotor.rotateFor(degreesToRotate, vex::rotationUnits::deg, false); //This command is blocking so the program will wait here until the right motor is done.  
    BackLeftMotor.rotateFor(degreesToRotate, vex::rotationUnits::deg, false); //This command must be non blocking.
    BackRightMotor.rotateFor(degreesToRotate, vex::rotationUnits::deg, false); //This command is blocking so the program will wait here until the right motor is done.  

    //The motors will brake once they reach their destination.
    
    //Print to the brain's screen that the program has ended.
    Brain.Screen.newLine();//Move the cursor to a new line on the screen.
    Brain.Screen.print("User Program has Ended.");
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }
	
}
