#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision11__BLUE1 = signature (1, -3421, -2271, -2846, 907, 11221, 6064, 1.1, 0);
signature Vision11__RED1 = signature (2, 623, 6187, 3405, -1973, -1175, -1574, 1.3, 0);
vision Vision11 = vision (PORT11, 50, Vision11__BLUE1, Vision11__RED1);
/*vex-vision-config:end*/
digital_out DigitalOutA = digital_out(Brain.ThreeWirePort.A);
digital_out DigitalOutB = digital_out(Brain.ThreeWirePort.B);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
