#include <stdio.h>
#include <stdlib.h>
#include "fk.h"
#include "ik.h"

int main(int argc, char *argv[])
{
	float **prms, **T1, **T2, **T3, **T4, **T5, **sol;
	float **temp1, **temp2, **temp3;
	float *angles, *ang_temp;
	int num_joints = 5;

	// Allocate memory for joint parameters and matrices
	prms = create_prm_array(num_joints);
	T1 = create_matrix();
	T2 = create_matrix();
	T3 = create_matrix();
	T4 = create_matrix();
	T5 = create_matrix();

	// d values
	prms[0][0] = 27.2;
	prms[1][0] = 0.0;
	prms[2][0] = 0.0;
	prms[3][0] = 0.0;
	prms[4][0] = 10.5;

	// a values
	prms[0][2] = 0.0;
	prms[1][2] = 19.2;
	prms[2][2] = 19.2;
	prms[3][2] = 0.0;
	prms[4][2] = 0.0;

	// alpha values
	prms[0][3] = 90.0;
	prms[1][3] = 180.0;
	prms[2][3] = 0.0;
	prms[3][3] = 90.0;
	prms[4][3] = 0.0;

	// Prompt user for theta values
	prms = get_thetas(prms, num_joints);
	
	// Create the 5 homogeneous transformation matrices
	T1 = build_matrix(prms, T1, 0);
	T2 = build_matrix(prms, T2, 1);
	T3 = build_matrix(prms, T3, 2);
	T4 = build_matrix(prms, T4, 3);
	T5 = build_matrix(prms, T5, 4);

	// Get transformation matrix 5 wrt 0
	temp1 = matrix_mult(T1, T2);
	temp2 = matrix_mult(T3, T4);
	temp3 = matrix_mult(temp1, temp2);
	sol = matrix_mult(temp3, T5);

	destroy_matrix(temp2);
	destroy_matrix(temp3);

	// Lab 3
	printf("\nHTM 5 wrt 0 (0A5):\n");
	print_matrix(sol);
	printf("\n");

	// Lab 4 code
	angles = find_joint_angles123(sol, prms);

	// deallocate
	destroy_matrix(temp1);
	temp1 = get_3A0(angles, prms);
	temp1 = get_3A5(temp1, sol);

	ang_temp = find_joint_angles45(temp1);

	angles[3] = ang_temp[0];
	angles[4] = ang_temp[1];

	printf("Lab4 Inverse Kinematics:\n");	
	for(int i = 0; i < 5; i++) printf("theta%d = %f\n", i, angles[i]);

	// Deallocate the memory
	free(angles);
	destroy_prm(prms, num_joints);
	destroy_matrix(T1);
	destroy_matrix(T2);
	destroy_matrix(T3);
	destroy_matrix(T4);
	destroy_matrix(T5);
	destroy_matrix(temp1);
	destroy_matrix(sol);

	return 0;
}
