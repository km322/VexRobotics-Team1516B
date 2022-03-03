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
vex::motor  FourBar = vex::motor( vex:: PORT1, true);

//Drivetrain
vex::motor  FrontRDrive = vex::motor( vex:: PORT2);
vex::motor  BackRDrive = vex::motor( vex:: PORT3);
vex::motor  MiddleRDrive = vex::motor( vex:: PORT4);
vex::motor  FrontLDrive = vex::motor( vex:: PORT5, true);
vex::motor  BackLDrive = vex::motor( vex:: PORT6, true);
vex::motor  MiddleLDrive = vex::motor( vex:: PORT7, true);

//Ring Lift
vex::motor  Rings = vex::motor( vex:: PORT8, true);

//Setting up the controller

vex::controller Controller = vex::controller();

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
  Rings.setVelocity(100, percent);
  FourBar.setVelocity(100, percent);
  MiddleLDrive.setVelocity(100, percent);
  MiddleRDrive.setVelocity(100, percent);
  FrontRDrive.setVelocity(100, percent);
  FrontLDrive.setVelocity(100, percent);
  BackRDrive.setVelocity(100, percent);
  BackLDrive.setVelocity(100, percent);

  digital_out pneum = digital_out( Brain.ThreeWirePort.A);
  digital_out pneum1 = digital_out( Brain.ThreeWirePort.B);
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
  FourBar.setVelocity(100, percent);
  Rings.setVelocity(100, percent);
  MiddleLDrive.setVelocity(100, percent);
  MiddleRDrive.setVelocity(100, percent);
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

    if(Controller.ButtonA.pressing()&&count%2==0) {
      pneum.set( true );
      count +=1;
      this_thread::sleep_for(200);
    }
    else {
      if(Controller.ButtonA.pressing()&&count%2==1){
        pneum.set( false );
        count+=1;
        this_thread::sleep_for(200);
      }
    }

    this_thread::sleep_for(10);


    digital_out pneum1 = digital_out( Brain.ThreeWirePort.B);

    if(Controller.ButtonLeft.pressing()&&count1%2==0) {
      pneum1.set( true );
      count1 +=1;
      wait(200, msec);
    }
    else {
      if(Controller.ButtonLeft.pressing()&&count1%2==1){
        pneum1.set( false );
        count1 +=1;
        wait(200, msec);
      }
    }

    this_thread::sleep_for(10);
    
    //Drive Train Program
    int leftForward = Controller.Axis3.position();
    int rightSideways = Controller.Axis1.position();  

    
    int lefto = leftForward + rightSideways;
    lefto = runoff(lefto);
    lefto = overFlow(lefto);
    int righto = leftForward - rightSideways;
    righto = runoff(righto);
    righto = overFlow(righto);
    
    FrontLDrive.spin(vex::directionType::fwd, lefto, vex::velocityUnits::pct);
    MiddleLDrive.spin(vex::directionType::fwd, lefto, vex::velocityUnits::pct);
    BackLDrive.spin(vex::directionType::fwd, lefto, vex::velocityUnits::pct);
    FrontRDrive.spin(vex::directionType::fwd, righto, vex::velocityUnits::pct);
    BackRDrive.spin(vex::directionType::fwd, righto, vex::velocityUnits::pct);
    MiddleRDrive.spin(vex::directionType::fwd, righto, vex::velocityUnits::pct);

    //lift Program

    //Lift Up
    if (Controller.ButtonR1.pressing() ) {
      FourBar.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
    }
    //Lift Down
    else if (Controller.ButtonR2.pressing()){
      FourBar.spin(vex::directionType::rev, intakeSpeed, vex::velocityUnits::pct);
  
    }
    //If nothing is pressed, the intakes will stay stationary
    else {
      FourBar.stop(vex::brakeType::brake);
    }
    //BackLift

    //BackLift Up
    if (Controller.ButtonL1.pressing() ) {
      Rings.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
    }
    //BackLift Down
    else if (Controller.ButtonL2.pressing()){
      Rings.spin(vex::directionType::fwd, intakeSpeed, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the BackLift will stay stationary
    else {
      Rings.stop(vex::brakeType::brake);
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
