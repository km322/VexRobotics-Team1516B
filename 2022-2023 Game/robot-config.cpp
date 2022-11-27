#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision11__DISK = signature (1, 3421, 4127, 3774, -6007, -5461, -5734, 3, 0);
signature Vision11__GEAR = signature (2, 11431, 13893, 12662, -1445, -511, -978, 3, 0);
vision Vision11 = vision (PORT11, 50, Vision11__DISK, Vision11__GEAR);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
