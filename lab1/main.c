// This program does some basic Lab-Volt 5150 robot movementsw

#include "/home/pi/ece417/labvolt/inc/labvolt.h"
#include <unistd.h>

int main(void)
{
	init();

	zero();	// Remember home position

	moverel(542, 0, 0, 0, 0);	// Rotate base 30 degrees CCW

	moverel(0, -478, 478, 361, -361); // Rotate shoulder 20 degrees down
	moverel(0, 0, 358, 271, -271);    // Rotate elbow 15 degrees in
	moverel(0, 0, 0, -361, -361);	  // Roll wrist 20 degrees CW
	moverel(0, 0, 0, -361, 361);	  // Pitch wrist 20 degrees up

	sleep(5);						  // Sleep for 5 seconds

	gripperClose();					  // Close the gripper
	nest();							  // Return to home positions

	shutdown();						  // Power down

	return 0;
}
