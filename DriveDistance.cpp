#include "robot-config.h"
#include "math.h" //Include math.h in order to gain access to math functions like PI. 

int main() {
     vex::task::sleep(2000); 
     Brain.Screen.print("User Program has Started.");
    
    
    double wheelDiameterCM  = 10.16; 
    double travelTargetCM = 90; 
    
   
    double circumference = wheelDiameterCM * M_PI;
    
    double degreesToRotate = (360 * travelTargetCM) / circumference; //All calculations are complete. Start the rest of the program.
    
    
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
