#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lab2.h"
#include "lab3.h"

// Pass a paramater array predefined in main and the number
// of joints or homogenous transformation matrices and
// allocate the required memory for all joint parameters
void create_prm_array(float **prms, int num_joints)
{
	prms = malloc(sizeof(float *) * num_joints);
	for (int i = 0; i < num_joints; i++) {
		prms[i] = malloc(sizeof(float *) * 4);
	}
}

// Pass the joint parameters and allocated 4x4 matrix
// and build the homogeneous transformation matrix 
void build_matrix(float *prms, float **htm)
{
	// Calculate sine and cosine of theta and alpha first and
	// get d and a for readability
	
	float ct = cosf(prms[1] * PI / 180.0);
	float st = sinf(prms[1] * PI / 180.0);
	float ca = cosf(prms[3] * PI / 180.0);
	float sa = sinf(prms[3] * PI / 180.0);
	float d = prms[0];
	float a = prms[2];

	// Build homogeneous transformation matrix (i-1)T(i) or
	// i with respect to i-1
	htm[0][0] = ct;
	htm[0][1] = -1.0 * ca * st;
	htm[0][2] = sa * st;
	htm[0][3] = a * ct;
	htm[1][0] = st;
	htm[1][1] = ca * ct;
	htm[1][2] = -1.0 * sa * ct;
	htm[1][3] = a * st;
	htm[2][0] = 0.0;
	htm[2][1] = sa;
	htm[2][2] = ca;
	htm[2][3] = d;
	htm[3][0] = 0.0;
	htm[3][1] = 0.0;
	htm[3][2] = 0.0;
	htm[3][3] = 1.0;

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

void destroy_prm(float **prms, int num_joints)
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
