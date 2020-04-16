#include "fk.h"
#include "ik.h"
#include <math.h>

float *find_joint_angles123(float **htm, float **prms)
{
	float angles[3] = {0.0};
	float theta1 = 0.0, theta2 = 0.0, theta3 = 0.0, theta4 = 0.0, theta5 = 0.0;
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
	den = 2.0 * prms[2][1] * prms[2][2];
	theta3 = acos(num/den);

	% Calculate theta 2
	theta2 = atan2(z, a) + atan2(a3*sin(theta3), a2 + a3*cos(theta3));

	angles[0] = theta1;
	angles[1] = theta2;
	angles[2] = theta3;
	
	return angles;
}

float *find_joint_angles45(float **htm)
{
	float *angles[2] = {0.0};
	float *theta4 = atan2(htm[1][2], htm[0][2]);
	float *theta5 = atan2(htm[2][0], htm[2][1]);
	
	angles[0] = theta4;
	angles[1] = theta5;

	return angles;
}

float **get_3A0(float *angles, float **prms)
{
	float theta1 = angles[0], theta2 = angles[1], theta3 = angles[2];
	float **sol = create_matrix();

	float a2 = prms[2][1], a3 = prms[2][2], d1 = prms[0][0];
	float c1 = cos(theta1), s1 = sin(theta1);
	float c3 = cos(theta3), s3 = sin(theta3);
	float c32 = cos(theta3-theta2), s32 = sin(theta3-theta2);

	sol[0][0] = c1*c32;
	sol[1][0] = s1*c32;
	sol[2][0] = -1.0*s32;
	sol[3][0] = -1.0*a3 - a2*c3 + d1*s32;
	sol[0][1] = -1.0*c1*s32;
	sol[1][1] = -1.0*s1*s32;
	sol[2][1] = -1.0*c32;
	sol[3][1] = a2*s3 + d1*c32;
	sol[0][2] = -1.0 * s1;
	sol[1][2] = c1;
	sol[2][2] = 0;
	sol[3][2] = 0;
	sol[0][3] = 0;
	sol[1][3] = 0;
	sol[2][3] = 0;
	sol[3][3] = 1;

	return sol;

}

float **get_3A5(float **3A0, float **0A5)
{
	float **sol = matrix_mult(3A0, 0A5);
	return sol;
}
