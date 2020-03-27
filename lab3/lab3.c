#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mmult.h"


// Pass a paramater array predefined in main and the number
// of joints or homogenous transformation matrices and
// allocate the required memory for all joint parameters
void create_prm_array(float **prms, int num_joints)
{
	prms = malloc(sizeof(float *) * num_joints);
	for (int i = 0; i < num_joints; i++;) {
		prms[i] = malloc(sizeof(float *) * 4);
	}
}

/*
// Prompt the user for the 4 joint parameters for each joint
void get_joint_prms(float **prms, int num_joints)
{
	for (int i = 0; i < num_joints; i++) {
		for (int j = 0; j < 4; j++) {
			printf("Enter joint parameter 'd': ");
			scanf("%f", prms);
			printf("Enter joint parameter 'theta': ");
			scanf("%f", prms+1);
			printf("Enter joint parameter 'a': ");
			scanf("%f", prms+2);
			printf("Enter joint parameter 'alpha': ");
			scanf("%f", prms+3);
		}
	}
} */

// Pass the joint parameters and allocated 4x4 matrix
// and build the homogeneous transformation matrix 
void build_matrix(float *prms, float **htm)
{
	// Calculate sine and cosine of theta and alpha first and
	// get d and a for readability
	
	ct = cosf(prms[1] * PI / 180);
	st = sinf(prms[1] * PI / 180);
	ca = cosf(prms[3] * PI / 180);
	sa = sinf(prms[3] * PI / 180);
	d = prms[0];
	a = prms[2];

	// Build homogeneous transformation matrix (i-1)T(i) or
	// i with respect to i-1
	htm[0][0] = ct;
	htm[0][1] = -1 * ca * st;
	htm[0][2] = sa * st;
	htm[0][3] = a * ct;
	htm[1][0] = st;
	htm[1][1] = ca * ct;
	htm[1][2] = -1 * sa * ct;
	htm[1][3] = a * st;
	htm[2][0] = 0;
	htm[2][1] = sa;
	htm[2][2] = ca;
	htm[2][3] = d;
	htm[3][0] = 0;
	htm[3][1] = 0;
	htm[3][2] = 0;
	htm[3][3] = 1;

	printf("\n");
	print_matrix(htm);
	printf("\n");
} 

// Lab 3 only requires input joint angle theta
void create_theta_arr(float *arr, int num_joints)
{
	arr = malloc(sizeof(float) * num_joints);
}

// Pass a float ** and allocate the required memory for a 
// 4x4 homogenous transformation matrix
void create_matrix(float **matrix)
{
	matrix = malloc(sizeof(float *) * 4);
	for (int i = 0; i < 4; i++) {
		matrix[i] = malloc(sizeof(float *) * 4);
	}
}

// Prompt the user for num_joints joint angles
void get_thetas(float **arr, int num_joints)
{
	for (int i = 0; i < num_joints; i++) {
		printf("Enter joint parameter theta%d: ", i);
		scanf("%f", &arr[1][i]);
	}
}
/*
// Pass theta, alpha and the allocated 4x4 matrix
// and build the homogeneous transformation matrix 
void build_matrix(float arr, float **htm)
{
	// Calculate sine and cosine of theta and alpha first and
	// get d and a for readability
	ct = cosf(prms[1] * PI / 180);
	st = sinf(prms[1] * PI / 180);
	ca = cosf(prms[3] * PI / 180);
	sa = sinf(prms[3] * PI / 180);
	d = prms[0];
	a = prms[2];

	// Build homogeneous transformation matrix (i-1)T(i) or
	// i with respect to i-1
	htm[0][0] = ct;
	htm[0][1] = -1 * ca * st;
	htm[0][2] = sa * st;
	htm[0][3] = a * ct;
	htm[1][0] = st;
	htm[1][1] = ca * ct;
	htm[1][2] = -1 * sa * ct;
	htm[1][3] = a * st;
	htm[2][0] = 0;
	htm[2][1] = sa;
	htm[2][2] = ca;
	htm[2][3] = d;
	htm[3][0] = 0;
	htm[3][1] = 0;
	htm[3][2] = 0;
	htm[3][3] = 1;
} 
*/


void destroy_prm(float **prms)
{
	for (int i = 0; i < 4; i++) {
		free(prms[i]);
	}
	free(prms);
}

void destroy_thetas(float *arr)
{
	free(arr);
}

void destroy_matrix(float **matrix)
{
	for (int i = 0; i < 4; i++) {
		free(matrix[i]);
	}
	free(matrix);
}
