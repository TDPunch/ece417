// This program does some basic Lab-Volt 5150 robot movementsw

#include "/usr/linux/public/labvolt/labvolt.h"

int main(int argc, char *argv[])
{
	init();

	zero();	// Remember home position

	moverel(542, 0, 0, 0, 0);	// Rotate base 30 degrees CCW

	moverel(0, -478, 478, 361, -361);
	moverel(0, 0, 358, 271, -271);
	moverel(0, 0, 0, );

	shutdown();
}
