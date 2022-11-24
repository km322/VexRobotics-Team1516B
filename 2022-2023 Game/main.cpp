/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ketan                                                     */
/*    Created:      Sun Aug 14 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision11             vision        11              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"


using namespace vex;

// A global instance of competition
competition Competition;


vex::motor  Intake = vex::motor( vex:: PORT10);
vex::motor  Roller = vex::motor( vex:: PORT2, true);
vex::motor  Flywheel1 = vex::motor( vex:: PORT15);
vex::motor  Flywheel2 = vex::motor( vex:: PORT16, true);
vex::motor  RightBack = vex::motor(vex::PORT1);
vex::motor  RightFront = vex::motor(vex::PORT8);
vex::motor  LeftBack = vex::motor(vex::PORT3, true);
vex::motor  LeftFront = vex::motor(vex::PORT18, true);
vex::vision VisionSensor (vex::PORT11);

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
  
  // ..........................................................................
  // autonomous for closer to human field
  // ..........................................................................
  //set velocity percentage of motors
  Intake.setVelocity(100, percent);
  Roller.setVelocity(100, percent);
  Flywheel1.setVelocity(100, percent);
  Flywheel2.setVelocity(100, percent);
  LeftBack.setVelocity(100, percent);
  LeftFront.setVelocity(100, percent);
  RightFront.setVelocity(100, percent);
  RightBack.setVelocity(100, percent);

  //something that fixes the error
  digital_out pneum = digital_out( Brain.ThreeWirePort.A);
  digital_out pneum1 = digital_out( Brain.ThreeWirePort.B);

  //settting state of pneumatics
  pneum1.set(false);
  pneum.set(false);

  //[motor name].startRotateFor(vex::directionType::[fwd/rev],[degree of rotation (one full roatation = 360)] vex::rotationUnits::deg)
  //going backwards and rolling roller
  LeftBack.startRotateFor(vex::directionType::rev, 300, vex::rotationUnits::deg);
  LeftFront.startRotateFor(vex::directionType::rev, 300, vex::rotationUnits::deg);
  RightFront.startRotateFor(vex::directionType::rev, 300, vex::rotationUnits::deg);
  RightBack.startRotateFor(vex::directionType::rev, 300, vex::rotationUnits::deg);
  wait(2,seconds);
  Roller.startRotateFor(vex::directionType::rev, 400, vex::rotationUnits::deg);
  wait(2,seconds);

  // ..........................................................................
  // autonomous for further side rollers
  // ..........................................................................
  // sliding
  // LeftBack.startRotateFor(vex::directionType::fwd, 50, vex::rotationUnits::deg);
  // LeftFront.startRotateFor(vex::directionType::rev, 50, vex::rotationUnits::deg);
  // RightFront.startRotateFor(vex::directionType::fwd, 50, vex::rotationUnits::deg);
  // RightBack.startRotateFor(vex::directionType::rev, 50, vex::rotationUnits::deg);
  // wait(0.5,seconds);
  // //going backwards
  // LeftBack.startRotateFor(vex::directionType::rev, 75, vex::rotationUnits::deg);
  // LeftFront.startRotateFor(vex::directionType::rev, 75, vex::rotationUnits::deg);
  // RightFront.startRotateFor(vex::directionType::rev, 75, vex::rotationUnits::deg);
  // RightBack.startRotateFor(vex::directionType::rev, 75, vex::rotationUnits::deg);
  // wait(0.75,seconds);
  // //fly wheel and roller
  // Roller.startRotateFor(vex::directionType::rev, 200, vex::rotationUnits::deg);
  // wait(2,seconds);
  // Flywheel1.startRotateFor(vex::directionType::fwd, 10000, vex::rotationUnits::deg);
  // Flywheel2.startRotateFor(vex::directionType::fwd, 10000, vex::rotationUnits::deg);
  // //going back forward to the line 
  // LeftBack.startRotateFor(vex::directionType::fwd, 100, vex::rotationUnits::deg);
  // LeftFront.startRotateFor(vex::directionType::fwd, 100, vex::rotationUnits::deg);
  // RightFront.startRotateFor(vex::directionType::fwd, 100, vex::rotationUnits::deg);
  // RightBack.startRotateFor(vex::directionType::fwd, 100, vex::rotationUnits::deg);
  // wait(1,seconds);
  // //turning a bit getting into position for shooting
  // LeftFront.startRotateFor(vex::directionType::fwd, 12, vex::rotationUnits::deg);
  // LeftBack.startRotateFor(vex::directionType::fwd, 12, vex::rotationUnits::deg);
  // wait(0.12,seconds);
  // ///shooting
  // for (int i = 0; i < 2; i++){
  //   pneum.set( true );
  //   wait(0.2,seconds);
  //   pneum.set( false );
  //   wait(0.1,seconds);
  // }
}

void usercontrol(void){
  // Setting the speeds and defining the variables
  int count = 0, axis3 = 0, axis4 = 0, axis1 = 0, X1 = 0, X2 = 0, Y1 = 0, c = 0;
  Controller.Screen.print("Color: Blue");
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
    if(Controller.ButtonLeft.pressing() && Controller.ButtonDown.pressing()) {
      pneum1.set( true );
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
        Flywheel1.stop(vex::brakeType::coast);
        Flywheel2.stop(vex::brakeType::coast);
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
    if (Controller.ButtonY.pressing()&&c%2==0){
      Controller.Screen.clearLine(3);
      Controller.Screen.setCursor(3,1);
      c += 1;
      Controller.Screen.print("Color: Red");
      this_thread::sleep_for(200);
    }
    else{
     if (Controller.ButtonY.pressing()&&c%2==1){
      Controller.Screen.clearLine(3);
      Controller.Screen.setCursor(3,1);
      c += 1;
      Controller.Screen.print("Color: Blue");
      this_thread::sleep_for(200);
      }
    }

    if (Controller.ButtonL1.pressing() ) {
      Roller.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if (Controller.ButtonL2.pressing()){
      Roller.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
      //If nothing is pressed, the rollers will stay stationary
    else {
      VisionSensor.takeSnapshot(Vision11__DISK);
      if (VisionSensor.largestObject.exists){
        Roller.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
        }
      else{
        Roller.stop(vex::brakeType::brake);
      }
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

    //Temperature Code
    
    // Brain.Screen.clearScreen();
    // Brain.Screen.setCursor(1, 1);
    // Brain.Screen.print("Right Front Drivetrain Motor: %.2f% ", RightFront.temperature(fahrenheit));
    // Brain.Screen.setCursor(2, 1);
    // Brain.Screen.print("Left Front Drivetrain Motor: %.2f% ", LeftFront.temperature(fahrenheit));
    // Brain.Screen.setCursor(3, 1);
    // Brain.Screen.print("Right Back Drivetrain Motor: %.2f% ", RightBack.temperature(fahrenheit));
    // Brain.Screen.setCursor(4, 1);
    // Brain.Screen.print("Left Back Drivetrain Motor: %.2f% ", LeftBack.temperature(fahrenheit));
    // Brain.Screen.setCursor(5, 1);
    // Brain.Screen.print("Roller Motor: %.2f% ", Roller.temperature(fahrenheit));
    // Brain.Screen.setCursor(6, 1);
    // Brain.Screen.print("Intake Motor: %.2f% ", Intake.temperature(fahrenheit));
    // Brain.Screen.setCursor(7, 1);
    // Brain.Screen.print("Flywheel Motor 1: %.2f% ", Flywheel1.temperature(fahrenheit));
    // Brain.Screen.setCursor(8, 1);
    // Brain.Screen.print("Flywheel Motor 2: %.2f% ", Flywheel2.temperature(fahrenheit));
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
