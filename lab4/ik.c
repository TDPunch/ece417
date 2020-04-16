#include "lab3.h"
#include <math.h>

float *find_joint_angles123(float **htm, float **prms)
{
	float angles[3] = {0};
	float theta1 = 0, theta2 = 0, theta3 = 0, theta4 = 0, theta5 = 0;
	float d1 = prms[0][0], d5 = prms[0][4];
	float a2 = prms[2][1], a3 = prms[2][2];
	
	% Calculate theta 1.
	y1 = htm[3][1] - d5 * htm[2][1];
	x1 = htm[3][0] - d5 * htm[2][0];
	theta1 = atan2(y1, x1);
	
	% Calculate theta 3
	a = sqrt(x1*x1 + y1*y1);
	z = htm[3][2] - d5 * htm[2][2] - prms[0][0];
	a2 = prms[2][1];
	a3
	num = a*a + z*z - prms[2][1] - prms[2][2];
	den = 2 * prms[2][1] * prms[2][2];
	theta3 = acos(num/den);

	% Calculate theta 2
	theta2 = atan2(z, a) + atan2(a3*sin(theta3), a2 + a3*cos(theta3));

	angles[0] = theta1;
	angles[1] = theta2;
	angles[2] = theta3;
	
	return angles;
}

float **get_3A0(float *angles)
{
	float theta1 = angles[0], theta2 = angles[1], theta3 = angles[2];

	create_mat
}
