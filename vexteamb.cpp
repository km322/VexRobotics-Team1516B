/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Jan 13 2022                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// DigitalOutA          digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

//4 bar
vex::motor  FrontRLift = vex::motor( vex:: PORT12);
vex::motor  FrontLLift = vex::motor( vex:: PORT11, true);

//Back Lift
vex::motor  BackRLift = vex::motor( vex:: PORT20);
vex::motor  BackLLift = vex::motor( vex:: PORT8, true);

//Drivetrain
vex::motor  FrontRDrive = vex::motor( vex:: PORT5);
vex::motor  BackRDrive = vex::motor( vex:: PORT10);
vex::motor  FrontLDrive = vex::motor( vex:: PORT6, true);
vex::motor  BackLDrive = vex::motor( vex:: PORT9, true);


//Setting up the controller

vex::controller Yeetroller = vex::controller();

// define your global instances of motors and other devices here



int runoff(int parameter) {
  if (parameter > 100){
    parameter = 100;
  }
  else if (parameter < -100){
    parameter = -100;
  }
  return parameter;
}





int overFlow(int input){
  if (input < 30 && input > 0){
    input = 0;
  } else if (input > -30 && input < 0){
    input = 0;
  }
  return input;
}




int average(int input1, int input2){
  return (input1+input2)/2;
}



// void moveForward(float rotations){
//   int degrees = rotations*360;
//   leftSide.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
//   rightSide.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
// }

// void turnRight(float num){
//   int degrees = num;
//   leftSide.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
//   rightSide.startRotateFor(vex::directionType::rev, degrees, vex::rotationUnits::deg);
// }

// void turnLeft(float num){
//   int degrees = num;
//   leftSide.startRotateFor(vex::directionType::rev, degrees, vex::rotationUnits::deg);
//   rightSide.startRotateFor(vex::directionType::fwd, degrees, vex::rotationUnits::deg);
// }


// void ballIn(){
//   RightIntake.startRotateFor(vex::directionType::fwd, 1080, vex::rotationUnits::deg);
//   LeftIntake.rotateFor(vex::directionType::fwd, 1080, vex::rotationUnits::deg);
//   vcb.rotateFor(vex::directionType::fwd, 5*360, vex::rotationUnits::deg);
//   wait(1,seconds);
//   shell.rotateFor(vex::directionType::fwd, 8*360, vex::rotationUnits::deg);


// }

// void ballOut(){
//   RightIntake.startRotateFor(vex::directionType::rev, 1080, vex::rotationUnits::deg);
//   LeftIntake.rotateFor(vex::directionType::rev, 1080, vex::rotationUnits::deg);
//   vcb.rotateFor(vex::directionType::rev, 5*360, vex::rotationUnits::deg);
//   shell.rotateFor(vex::directionType::rev, 8*360, vex::rotationUnits::deg);

// }


// void intake(){
//   rings.startRotateFor(vex::directionType::fwd, 1080, vex::rotationUnits::deg);
// }

// void outake(){
//   rings.startRotateFor(vex::directionType::rev, 1080, vex::rotationUnits::deg);
// }


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

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

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  FrontLLift.setVelocity(80, percent);
  FrontRLift.setVelocity(80, percent);
  BackLLift.setVelocity(80, percent);
  BackRLift.setVelocity(80, percent);
  FrontRDrive.setVelocity(100, percent);
  FrontLDrive.setVelocity(100, percent);
  BackRDrive.setVelocity(100, percent);
  BackLDrive.setVelocity(100, percent);

  // Middle Goal
  FrontRLift.startRotateFor(vex::directionType::rev, 950, vex::rotationUnits::deg);
  FrontLLift.startRotateFor(vex::directionType::rev, 950, vex::rotationUnits::deg);
  FrontLDrive.startRotateFor(vex::directionType::fwd, 1700, vex::rotationUnits::deg);
  FrontRDrive.startRotateFor(vex::directionType::fwd, 1700, vex::rotationUnits::deg);
  BackRDrive.startRotateFor(vex::directionType::fwd, 1700, vex::rotationUnits::deg);
  BackLDrive.startRotateFor(vex::directionType::fwd, 1700, vex::rotationUnits::deg);
  wait(1.6,seconds);
  FrontRLift.startRotateFor(vex::directionType::fwd, 700, vex::rotationUnits::deg);
  FrontLLift.startRotateFor(vex::directionType::fwd, 700, vex::rotationUnits::deg);
  FrontLDrive.startRotateFor(vex::directionType::fwd, 100, vex::rotationUnits::deg);
  FrontRDrive.startRotateFor(vex::directionType::fwd, 100, vex::rotationUnits::deg);
  BackRDrive.startRotateFor(vex::directionType::fwd, 100, vex::rotationUnits::deg);
  BackLDrive.startRotateFor(vex::directionType::fwd, 100, vex::rotationUnits::deg);
  wait(.75,seconds);
  FrontLDrive.startRotateFor(vex::directionType::rev, 1850, vex::rotationUnits::deg);
  FrontRDrive.startRotateFor(vex::directionType::rev, 1850, vex::rotationUnits::deg);
  BackRDrive.startRotateFor(vex::directionType::rev, 1850, vex::rotationUnits::deg);
  BackLDrive.startRotateFor(vex::directionType::rev, 1850, vex::rotationUnits::deg);
  wait(2,seconds);
  // FrontLDrive.startRotateFor(vex::directionType::fwd, 400, vex::rotationUnits::deg);
  // FrontRDrive.startRotateFor(vex::directionType::rev, 400, vex::rotationUnits::deg);
  // BackRDrive.startRotateFor(vex::directionType::rev, 400, vex::rotationUnits::deg);
  // BackLDrive.startRotateFor(vex::directionType::fwd, 400, vex::rotationUnits::deg);
  // wait(2,seconds);
  // FrontLDrive.startRotateFor(vex::directionType::rev, 1850, vex::rotationUnits::deg);
  // FrontRDrive.startRotateFor(vex::directionType::rev, 1850, vex::rotationUnits::deg);
  // BackRDrive.startRotateFor(vex::directionType::rev, 1850, vex::rotationUnits::deg);
  // BackLDrive.startRotateFor(vex::directionType::rev, 1850, vex::rotationUnits::deg);
  // wait(2,seconds);

  // Get Alliance Goal
  // FrontRLift.startRotateFor(vex::directionType::rev, 1050, vex::rotationUnits::deg);
  // FrontLLift.startRotateFor(vex::directionType::rev, 1050, vex::rotationUnits::deg);
  // wait(1.5,seconds);
  // FrontLDrive.startRotateFor(vex::directionType::fwd, 360, vex::rotationUnits::deg);
  // FrontRDrive.startRotateFor(vex::directionType::fwd, 360, vex::rotationUnits::deg);
  // BackRDrive.startRotateFor(vex::directionType::fwd, 360, vex::rotationUnits::deg);
  // BackLDrive.startRotateFor(vex::directionType::fwd, 360, vex::rotationUnits::deg);
  // wait(1.5,seconds);
  // FrontRLift.startRotateFor(vex::directionType::fwd, 1050, vex::rotationUnits::deg);
  // FrontLLift.startRotateFor(vex::directionType::fwd, 1050, vex::rotationUnits::deg);

//   other code for rings
//   BackLLift.setVelocity(100, percent);
//   BackRLift.setVelocity(100, percent);
//   BackLDrive.setVelocity(60, percent);
//   BackRDrive.setVelocity(60, percent);
//   FrontLDrive.setVelocity(60, percent);
//   FrontRDrive.setVelocity(60, percent);
//   BackRLift.startRotateFor(vex::directionType::rev, 900, vex::rotationUnits::deg);
//   BackLLift.startRotateFor(vex::directionType::rev, 900, vex::rotationUnits::deg);
//   wait(1.5, seconds);
//   BackRDrive.startRotateFor(vex::directionType::fwd, 900, vex::rotationUnits::deg);
//   BackLDrive.startRotateFor(vex::directionType::fwd, 900, vex::rotationUnits::deg);
//   FrontRDrive.startRotateFor(vex::directionType::fwd, 900, vex::rotationUnits::deg);
//   FrontLDrive.startRotateFor(vex::directionType::fwd, 900, vex::rotationUnits::deg);
//   wait(1, seconds);
//   BackRLift.startRotateFor(vex::directionType::fwd, 600, vex::rotationUnits::deg);
//   BackLLift.startRotateFor(vex::directionType::fwd, 600, vex::rotationUnits::deg);
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

void usercontrol(void) {
  FrontLLift.setVelocity(100, percent);
  FrontRLift.setVelocity(100, percent);
  BackLLift.setVelocity(100, percent);
  BackRLift.setVelocity(100, percent);
  FrontRDrive.setVelocity(100, percent);
  FrontLDrive.setVelocity(100, percent);
  BackRDrive.setVelocity(100, percent);
  BackLDrive.setVelocity(100, percent);

  int intakeSpeed = 100;
  int count = 0;
  int count1 = 0;
  // User control code here, inside the loop
  while (1) {
 
    digital_out pneum = digital_out( Brain.ThreeWirePort.A);

    if(Yeetroller.ButtonLeft.pressing()&&count%2==0) {
      pneum.set( true );
      count +=1;
      wait(400, msec);
    }
    else {
      if(Yeetroller.ButtonLeft.pressing()&&count%2==1){
        pneum.set( false );
        count+=1;
        wait(400, msec);
      }
    }

    this_thread::sleep_for(10);


    digital_out pneum1 = digital_out( Brain.ThreeWirePort.D);

    if(Yeetroller.ButtonA.pressing()&&count1%2==0) {
      pneum1.set( true );
      count1 +=1;
      wait(400, msec);
    }
    else {
      if(Yeetroller.ButtonA.pressing()&&count1%2==1){
        pneum1.set( false );
        count1 +=1;
        wait(400, msec);
      }
    }

    this_thread::sleep_for(10);
    
    //Drive Train Program
    int leftForward = Yeetroller.Axis3.position();
    int rightSideways = Yeetroller.Axis1.position();  

    
    int lefto = leftForward + rightSideways;
    lefto = runoff(lefto);
    lefto = overFlow(lefto);
    int righto = leftForward - rightSideways;
    righto = runoff(righto);
    righto = overFlow(righto);
    
    FrontLDrive.spin(vex::directionType::fwd, lefto, vex::velocityUnits::pct);
    BackLDrive.spin(vex::directionType::fwd, lefto, vex::velocityUnits::pct);
    FrontRDrive.spin(vex::directionType::fwd, righto, vex::velocityUnits::pct);
    BackRDrive.spin(vex::directionType::fwd, righto, vex::velocityUnits::pct);
    //strafe.spin(vex::directionType::fwd, middle, vex::velocityUnits::pct);
    // rightTopDriveMotor.spin(vex::directionType::fwd, RT, vex::velocityUnits::pct);

    //lift Program

    //Lift Up
    if (Yeetroller.ButtonL1.pressing() ) {
      FrontLLift.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
      FrontRLift.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
    }
    //Lift Down
    else if (Yeetroller.ButtonL2.pressing()){
      FrontLLift.spin(vex::directionType::rev, intakeSpeed, vex::velocityUnits::pct);
      FrontRLift.spin(vex::directionType::rev, intakeSpeed, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the intakes will stay stationary
    else {
      FrontLLift.stop(vex::brakeType::brake);
      FrontRLift.stop(vex::brakeType::brake);
    }
    //BackLift

    //BackLift Up
    if (Yeetroller.ButtonR2.pressing() ) {
      BackLLift.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
      BackRLift.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
    }
    //BackLift Down
    else if (Yeetroller.ButtonR1.pressing()){
      BackLLift.spin(vex::directionType::rev, intakeSpeed, vex::velocityUnits::pct);
      BackRLift.spin(vex::directionType::rev, intakeSpeed, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the BackLift will stay stationary
    else {
      BackLLift.stop(vex::brakeType::brake);
      BackRLift.stop(vex::brakeType::brake);
    }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
