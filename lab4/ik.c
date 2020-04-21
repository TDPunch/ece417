#include "fk.h"
#include "ik.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float *find_joint_angles123(float **htm, float **prms)
{
	// Allocate memory for all five joint angles
	float *angles = malloc(5 * sizeof(float));

	// Declare meaningful variables
	float theta1 = 0.0, theta2 = 0.0, theta3 = 0.0;
	float d1 = prms[0][0], d5 = prms[4][0];
	float a2 = prms[1][2], a3 = prms[2][2];
	
	// Calculate theta 1.
	// y1/x1 = ty/x - d5 * ay/x
	float y1 = htm[1][3] - d5 * htm[1][2];
	float x1 = htm[0][3] - d5 * htm[0][2];
	theta1 = atan2(y1, x1);
	
	// Calculate theta 3
	float a = sqrt(x1*x1 + y1*y1);
	float z = htm[2][3] - d5 * htm[2][2] - d1;
	float num = a*a + z*z - a2*a2 - a3*a3;
	float den = 2.0 * a2 * a3;
	float c3 = num/den;

	// Make sure we're not trying to take the arccos of a value > |1|
	if (c3 > 1) c3 = 1;
	else if (c3 < -1) c3 = -1;
	theta3 = acos(c3);

	// Calculate theta 2
	theta2 = atan2(z, a) + atan2(a3*sin(theta3), a2 + a3*cos(theta3));

	angles[0] = theta1;
	angles[1] = theta2;
	angles[2] = theta3;

	return angles;
}

float *find_joint_angles45(float **htm)
{
	float *angles = malloc(2 * sizeof(float));

	// Calculate theta 4 and theta 5
	// theta4 = atan2((3A5)23, (3A5)13)
	// theta5 = atan2((3A5)31, (3A5)32)
	float theta4 = atan2(htm[1][2], htm[0][2]);
	float theta5 = atan2(htm[2][0], htm[2][1]);
	
	// Convert radians to degrees
	angles[0] = theta4;
	angles[1] = theta5;

	return angles;
}

// Determine 3A5 = 3A0 * 0A5 by substituting theta1, 2, and 3 into 3A0
// This matrix is required to calculate theta4 and theta5
float **get_3A0(float *angles, float **prms)
{
	// Declare variables
	float theta1 = angles[0], theta2 = angles[1], theta3 = angles[2];
	float **sol = create_matrix();

	float a2 = prms[2][1], a3 = prms[2][2], d1 = prms[0][0];
	float c1 = cos(theta1), s1 = sin(theta1);
	float c3 = cos(theta3), s3 = sin(theta3);
	float c32 = cos(theta3-theta2), s32 = sin(theta3-theta2);

	// Substitute theta1, 2 and 3 in to determine 3A0
	sol[0][0] = c1*c32;
	sol[0][1] = s1*c32;
	sol[0][2] = -1.0*s32;
	sol[0][3] = -1.0*a3 - a2*c3 + d1*s32;
	sol[1][0] = -1.0*c1*s32;
	sol[1][1] = -1.0*s1*s32;
	sol[1][2] = -1.0*c32;
	sol[1][3] = a2*s3 + d1*c32;
	sol[2][0] = -1.0 * s1;
	sol[2][1] = c1;
	sol[2][2] = 0;
	sol[2][3] = 0;
	sol[3][0] = 0;
	sol[3][1] = 0;
	sol[3][2] = 0;
	sol[3][3] = 1;

	return sol;

}

// Performs matrix multiplation 3A5 = 3A0 * 0A5
float **get_3A5(float **m3A0, float **m0A5)
{
	float **sol = matrix_mult(m3A0, m0A5);
	return sol;
}
