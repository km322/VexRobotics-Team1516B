/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ketan                                                     */
/*    Created:      Sun Aug 14 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

//Intake Motor
vex::motor  Intake = vex::motor( vex:: PORT19);
vex::motor  Roller = vex::motor( vex:: PORT2, true);
vex::motor  Flywheel1 = vex::motor( vex:: PORT3);
vex::motor  Flywheel2 = vex::motor( vex:: PORT4, true);
vex::motor  RightBack = vex::motor(vex::PORT1);
vex::motor  RightFront = vex::motor(vex::PORT8);
vex::motor  LeftBack = vex::motor(vex::PORT20, true);
vex::motor  LeftFront = vex::motor(vex::PORT18, true);

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
}

void usercontrol(void){
  // Setting the speeds and defining the variables
  int count = 0, axis3 = 0, axis4 = 0, axis1 = 0, X1 = 0, X2 = 0, Y1 = 0;

  Intake.setVelocity(100, percent);
  Roller.setVelocity(100, percent);
  Flywheel1.setVelocity(100, percent);
  Flywheel2.setVelocity(100, percent);
  while (1){

    digital_out pneum = digital_out( Brain.ThreeWirePort.A);
    if(Controller.ButtonRight.pressing()) {
      pneum.set( true );
      this_thread::sleep_for(200);
      pneum.set( false );
    }
    digital_out pneum1 = digital_out( Brain.ThreeWirePort.B);
    if(Controller.ButtonLeft.pressing()) {
      pneum1.set( true );
      this_thread::sleep_for(200);
      pneum1.set( false );
    }

    this_thread::sleep_for(10);
    // Flywheel on and off buttom using A
    if(Controller.ButtonA.pressing()&&count%2==0) {
      Flywheel1.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
      Flywheel2.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
      count +=1;
      this_thread::sleep_for(200);
    }
    else {
      if(Controller.ButtonA.pressing()&&count%2==1){
        Flywheel1.stop(vex::brakeType::brake);
        Flywheel2.stop(vex::brakeType::brake);
        count+=1;
        this_thread::sleep_for(200);
      }
    }

    //Intake Controls
    if (Controller.ButtonR1.pressing() ) {
      Intake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if (Controller.ButtonR2.pressing()){
      Intake.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the intakes will stay stationary
    else {
      Intake.stop(vex::brakeType::brake);
    }

    //Roller Controls
    if (Controller.ButtonL1.pressing() ) {
      Roller.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if (Controller.ButtonL2.pressing()){
      Roller.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the rollers will stay stationary
    else {
      Roller.stop(vex::brakeType::brake);
    }

    //Drivertrain Control (This is very scuffed for now, once we test it will be better)
    axis3 = Controller.Axis3.position();
    axis1 = Controller.Axis1.position();
    axis4 = Controller.Axis4.position();
    Y1=axis3;
    X1=axis4;
    X2=axis1;

    RightFront.spin(vex::directionType::fwd, runoff(overFlow(Y1-X2-X1)),vex::velocityUnits::pct);
    RightBack.spin(vex::directionType::fwd,runoff(overFlow(Y1-X2+X1)),vex::velocityUnits::pct);
    LeftFront.spin(vex::directionType::fwd,runoff(overFlow(Y1+X2+X1)),vex::velocityUnits::pct);
    LeftBack.spin(vex::directionType::fwd,runoff(overFlow(Y1+X2-X1)),vex::velocityUnits::pct);
    wait(20, msec);
  }
}

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
