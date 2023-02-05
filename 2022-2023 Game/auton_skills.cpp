/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ketan                                                     */
/*    Created:      Sun Aug 14 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*
                          oooo$$$$$$$$$$$$oooo
                      oo$$$$$$$$$$$$$$$$$$$$$$$$o
                   oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o         o$   $$ o$
   o $ oo        o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o       $$ $$ $$o$
oo $ $ "$      o$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$o       $$$o$$o$
"$$$$$$o$     o$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$o    $$$$$$$$
  $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$
  $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  """$$$
   "$$$""""$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     "$$$
    $$$   o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     "$$$o
   o$$"   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$o
   $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" "$$$$$$ooooo$$$$o
  o$$$oooo$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   o$$$$$$$$$$$$$$$$$
  $$$$$$$$"$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$""""""""
 """"       $$$$    "$$$$$$$$$$$$$$$$$$$$$$$$$$$$"      o$$$
            "$$$o     """$$$$$$$$$$$$$$$$$$"$$"         $$$
              $$$o          "$$""$$$$$$""""           o$$$
               $$$$o                 oo             o$$$"
                "$$$$o      o$$$$$$o"$$$$o        o$$$$
                  "$$$$$oo     ""$$$$o$$$$$o   o$$$$""  
                     ""$$$$$oooo  "$$$o$$$$$$$$$"""
                        ""$$$$$$$oo $$$$$$$$$$       
                                """"$$$$$$$$$$$        
                                    $$$$$$$$$$$$       
                                     $$$$$$$$$$"      
                                      "$$$""""
*/


// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision11             vision        11              
// DigitalOutA          digital_out   A               
// DigitalOutB          digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <string>

using namespace vex;

// A global instance of competition
competition Competition;

// define motors with ports
// true = reversed
vex::motor  Intake = vex::motor( vex:: PORT3, ratio18_1);
vex::motor  Roller = vex::motor( vex:: PORT2, ratio36_1, true);
vex::motor  Flywheel1 = vex::motor( vex:: PORT15, ratio6_1);
vex::motor  Flywheel2 = vex::motor( vex:: PORT16, ratio6_1, true);
vex::motor  RightBack = vex::motor(vex::PORT1, ratio18_1);
vex::motor  RightFront = vex::motor(vex::PORT8, ratio18_1);
vex::motor  LeftBack = vex::motor(vex::PORT10, ratio18_1, true);
vex::motor  LeftFront = vex::motor(vex::PORT18, ratio18_1, true);

vex::vision VisionSensor (vex::PORT11);

//Setting up the controller
vex::controller Controller = vex::controller();

//prevent going above or below 100
int runoff(int parameter) {
  if (parameter > 127){
    parameter = 127;
  }
  else if (parameter < -127){
    parameter = -127;
  }
  return parameter;
}

//prevent deadzone
int overFlow(int input){
  if (input < 20 && input > -20){
    input = 0;
  }
  return input;
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
  //set all motor to 100 percent (default is not)
  Intake.setVelocity(127, percent);
  Roller.setVelocity(127, percent);
  Flywheel1.setVelocity(100, percent);
  Flywheel2.setVelocity(100, percent);
  LeftBack.setVelocity(127, percent);
  LeftFront.setVelocity(127, percent);
  RightFront.setVelocity(127, percent);
  RightBack.setVelocity(127, percent);

  //settting state of pneumatics at the start of auton period
  DigitalOutB.set(false);
  DigitalOutA.set(false);

  //[motor name].startRotateFor - (vex::directionType::[fwd/rev],[degree of rotation - (one full roatation = 360)] vex::rotationUnits::deg)
  //going backwards and rolling roller
  // LeftBack.startRotateFor(vex::directionType::rev, 750, vex::rotationUnits::deg);
  // LeftFront.startRotateFor(vex::directionType::fwd, 750, vex::rotationUnits::deg);
  // RightFront.startRotateFor(vex::directionType::rev, 750, vex::rotationUnits::deg);
  // RightBack.startRotateFor(vex::directionType::fwd, 750, vex::rotationUnits::deg);
  // wait(3,seconds);
  LeftBack.startRotateFor(vex::directionType::rev, 200, vex::rotationUnits::deg);
  LeftFront.startRotateFor(vex::directionType::rev, 200, vex::rotationUnits::deg);
  RightFront.startRotateFor(vex::directionType::rev, 200, vex::rotationUnits::deg);
  RightBack.startRotateFor(vex::directionType::rev, 200, vex::rotationUnits::deg);
  //wait for above action to finish
  wait(2,seconds);
  //vision sensor time
  Roller.startRotateFor(vex::directionType::fwd, 300, vex::rotationUnits::deg);
  //wait for above action to finish
  wait(1,seconds);
  LeftBack.startRotateFor(vex::directionType::rev, 200, vex::rotationUnits::deg);
  LeftFront.startRotateFor(vex::directionType::rev, 200, vex::rotationUnits::deg);
  RightFront.startRotateFor(vex::directionType::rev, 200, vex::rotationUnits::deg);
  RightBack.startRotateFor(vex::directionType::rev, 200, vex::rotationUnits::deg);
  wait(2,seconds);
  //start flywheels
  LeftFront.startRotateFor(vex::directionType::rev, 75, vex::rotationUnits::deg);
  RightBack.startRotateFor(vex::directionType::fwd, 75, vex::rotationUnits::deg);
  LeftBack.startRotateFor(vex::directionType::rev, 75, vex::rotationUnits::deg);
  RightFront.startRotateFor(vex::directionType::fwd, 75, vex::rotationUnits::deg);
  Flywheel1.startRotateFor(vex::directionType::rev, 20000, vex::rotationUnits::deg);
  Flywheel2.startRotateFor(vex::directionType::rev, 20000, vex::rotationUnits::deg);
  wait(3,seconds);

  //start pnuematics two times to shoot two discs

  DigitalOutA.set( true );
  wait(.5,seconds);
  DigitalOutA.set( false );
  wait(2, seconds);
  DigitalOutA.set( true );
  wait(.5,seconds);
  DigitalOutA.set( false );
  wait(.5, seconds);

  //coast = allow motor to slow down itself
  Flywheel1.stop(vex::brakeType::coast);
  Flywheel2.stop(vex::brakeType::coast);
  wait(4,seconds);

  LeftFront.startRotateFor(vex::directionType::rev, 300, vex::rotationUnits::deg);
  RightBack.startRotateFor(vex::directionType::fwd, 300, vex::rotationUnits::deg);
  LeftBack.startRotateFor(vex::directionType::rev, 300, vex::rotationUnits::deg);
  RightFront.startRotateFor(vex::directionType::fwd, 300, vex::rotationUnits::deg);
  wait(3,seconds);
  
  DigitalOutB.set( true );
}

void usercontrol(void){

  // Setting the speeds and defining the variables
  int axis3 = 0, axis4 = 0, axis1 = 0, flyspeed = 100;
  bool flywheel = true, color1 = false;
  std::string col = "Red";
  Controller.Screen.print("Col: %s - Spd: %d", col.c_str() , flyspeed);
  Intake.setVelocity(127, percent);
  Roller.setVelocity(127, percent);
  Flywheel1.setVelocity(127, percent);
  Flywheel2.setVelocity(127, percent);
  while (1){
    //Pnuematic Code goes under here:
    //if right button is pressed pnuematic A activates and deactivates
    if(Controller.ButtonRight.pressing()) {
      DigitalOutA.set( true );
      this_thread::sleep_for(200);
      DigitalOutA.set( false );
    }
    //if left button is pressed pnuematic B activates
    if(Controller.ButtonLeft.pressing() && Controller.ButtonDown.pressing()) {
      DigitalOutB.set( true );
    }
    
        //Roller Controls
    if (Controller.ButtonUp.pressing()){
      Controller.Screen.clearLine(3);
      Controller.Screen.setCursor(3,1);
      if (flyspeed >=100){
        flyspeed = 127;
      }
      else {
        flyspeed += 10;
      }

      Controller.Screen.print("Col: %s - Spd: %d", col.c_str() , flyspeed);
      this_thread::sleep_for(200);
    }
    //Outputs the current color checked by the vision sensor
    if (Controller.ButtonDown.pressing()){
      Controller.Screen.clearLine(3);
      Controller.Screen.setCursor(3,1);
      if (flyspeed < 40){
        flyspeed = 40;
      }
      else {
        flyspeed -= 10;
      }

      Controller.Screen.print("Col: %s - Spd: %d", col.c_str() , flyspeed);
      this_thread::sleep_for(200);
    }

    // Flywheel on and off buttom using A
    if(Controller.ButtonA.pressing()&&flywheel) {
      Flywheel1.spin(vex::directionType::rev, flyspeed, vex::velocityUnits::pct);
      Flywheel2.spin(vex::directionType::rev, flyspeed, vex::velocityUnits::pct);
      flywheel = false;
      this_thread::sleep_for(200);
    }
    else {
      if(Controller.ButtonA.pressing()&&!flywheel){
        Flywheel1.stop(vex::brakeType::coast);
        Flywheel2.stop(vex::brakeType::coast);
        flywheel = true;
        this_thread::sleep_for(200);
      }
    }

    //Intake Controls: Checks pressed buttons
    if (Controller.ButtonR1.pressing() ) {
      Intake.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
    }
    else if (Controller.ButtonR2.pressing()){
      Intake.spin(vex::directionType::rev, 127, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the intakes will stay stationary
    else {
      Intake.stop(vex::brakeType::brake);
    }

    //Roller Controls
    if (Controller.ButtonY.pressing()&&color1){
      Controller.Screen.clearLine(3);
      Controller.Screen.setCursor(3,1);
      color1 = false;
      col = "Red";
      Controller.Screen.print("Col: %s - Spd: %d", col.c_str() , flyspeed);
      this_thread::sleep_for(200);
    }
    //Outputs the current color checked by the vision sensor
    else{
     if (Controller.ButtonY.pressing()&&!color1){
      Controller.Screen.clearLine(3);
      Controller.Screen.setCursor(3,1);
      color1 = true;
      col = "Blue";
      Controller.Screen.print("Col: %s - Spd: %d", col.c_str() , flyspeed);
      this_thread::sleep_for(200);
      }
    }

    //spin roller manually
    if (Controller.ButtonL1.pressing() ) {
      Roller.spin(vex::directionType::fwd, 127, vex::velocityUnits::pct);
    }
    else if (Controller.ButtonL2.pressing()){
      Roller.spin(vex::directionType::rev, 127, vex::velocityUnits::pct);
    }
    //If nothing is pressed, the rollers will stay stationary and vision sensor will do its job
    else {
      if(color1){
        VisionSensor.takeSnapshot(Vision11__BLUE1);
        if (VisionSensor.largestObject.exists){
          Roller.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
          }
        else{
          Roller.stop(vex::brakeType::brake);
        }
      }
      else if (!color1){
        VisionSensor.takeSnapshot(Vision11__RED1);
        if (VisionSensor.largestObject.exists){
          Roller.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
          }
        else{
          Roller.stop(vex::brakeType::brake);
        }
      }
    }
    //Drivertrain Control
    axis3 = Controller.Axis3.position();
    axis1 = Controller.Axis1.position();
    axis4 = Controller.Axis4.position();

    RightFront.spin(vex::directionType::fwd, runoff(overFlow(axis3-axis1-axis4)),vex::velocityUnits::pct);
    RightBack.spin(vex::directionType::fwd,runoff(overFlow(axis3-axis1+axis4)),vex::velocityUnits::pct);
    LeftFront.spin(vex::directionType::fwd,runoff(overFlow(axis3+axis1+axis4)),vex::velocityUnits::pct);
    LeftBack.spin(vex::directionType::fwd,runoff(overFlow(axis3+axis1-axis4)),vex::velocityUnits::pct);

    //Temperature Code

    // Brain.Screen.clearScreen();
    // Brain.Screen.setCursor(1, 1);
    // Brain.Screen.print("Right Front Drivetrain Motor: %.2f% ", RightFront.temperature(celsius));
    // Brain.Screen.setCursor(2, 1);
    // Brain.Screen.print("Left Front Drivetrain Motor: %.2f% ", LeftFront.temperature(celsius));
    // Brain.Screen.setCursor(3, 1);
    // Brain.Screen.print("Right Back Drivetrain Motor: %.2f% ", RightBack.temperature(celsius));
    // Brain.Screen.setCursor(4, 1);
    // Brain.Screen.print("Left Back Drivetrain Motor: %.2f% ", LeftBack.temperature(celsius));
    // Brain.Screen.setCursor(5, 1);
    // Brain.Screen.print("Roller Motor: %.2f% ", Roller.temperature(celsius));
    // Brain.Screen.setCursor(6, 1);
    // Brain.Screen.print("Intake Motor: %.2f% ", Intake.temperature(celsius));
    // Brain.Screen.setCursor(7, 1);
    // Brain.Screen.print("Flywheel Motor 1: %.2f% ", Flywheel1.temperature(celsius));
    // Brain.Screen.setCursor(8, 1);
    // Brain.Screen.print("Flywheel Motor 2: %.2f% ", Flywheel2.temperature(celsius));
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
