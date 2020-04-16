#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fk.h"

/* --- Lab 3 subroutines --- */

// Take the number of joints and create a 2D-array for joint paramters
float **create_prm_array(int num_joints)
{
	float **prms = malloc(sizeof(float *) * num_joints);
	for (int i = 0; i < num_joints; i++) {
		prms[i] = malloc(sizeof(float) * 4);
	}
	return prms;
}

// Allocate memory for a 4x4 homogeneous transformation matrix
float **create_matrix(void)
{
	float **matrix = malloc(sizeof(float *) * 4);
	for (int i = 0; i < 4; i++) {
		matrix[i] = malloc(sizeof(float) * 4);
	}
	return matrix;
}

// Prompt the user for num_joints joint angles
float **get_thetas(float **prms, int num_joints)
{
	float **theta = prms;
	for (int i = 0; i < num_joints; i++) {
		printf("Enter joint parameter theta%d: ", i + 1);
		scanf("%f", &theta[i][1]);
	}
	return theta;
}

// Pass the joint parameters 
float **build_matrix(float **prms, float **return_matrix, int row) 
{
	float **htm = return_matrix;
	// Calculate sine and cosine of theta and alpha first and
	// get d and a for readability
	if ((row+1) == 4) prms[row][1] += 90.0;
	float ct = cosf(prms[row][1] * PI / 180.0);
	float st = sinf(prms[row][1] * PI / 180.0);
	float ca = cosf(prms[row][3] * PI / 180.0);
	float sa = sinf(prms[row][3] * PI / 180.0);
	float d = prms[row][0];
	float a = prms[row][2];

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

	printf("\n HTM %d wrt %d:\n", );
	print_matrix(htm);
	printf("\n");

	return htm;
}

void destroy_prm(float **prms, int num_joints)
{
	for (int i = 0; i < num_joints; i++) {
		free(prms[i]);
	}
	free(prms);
}

void destroy_matrix(float **matrix)
{
	for (int i = 0; i < 4; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

/* --- Lab 2 subroutines --- */

// matrix_mult() computes the product of two matrices and allocates
// memory for the solution
float **matrix_mult(float **A, float **B)
{
	// Allocate memory for the columns
	float **C = create_matrix();
	float sum = 0.0;

	// Multiply the matrices
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 4; k++) {
				sum = sum + A[i][k] * B[k][j];
			}
			C[i][j] = sum;
			sum = 0.0;
		}
	}

	return C;
}

// point_trans() transforms a point using matrix R and allocates memory
// for the transformed point
float *point_trans(float R[4][4], float Puvw[3])
{
	// Allocate memory for return point in XYZ-space
	float *Pxyz = malloc(sizeof(float *) * 3);
	float sum = 0.0;

	// Transform point to XYZ-space
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum = sum + R[i][j] * Puvw[j];
		}
		// Don't forget the last element
		Pxyz[i] = sum + R[i][3];
		sum = 0.0;
	}
	
	return Pxyz;
}

// inverse() computes the inverse of a homogeneous transformation matrix
float **inverse(float a[4][4])
{
	// Allocate memory for the columns
	float **sol = malloc(sizeof(float *) * 4);
	float sum = 0.0;

	// Allocate memory for the rows
	for (int i = 0; i < 4; i++) {
		sol[i] = malloc(sizeof(float *) * 4);
	}

	// The inverse of the rotation portion is just the transpose
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			sol[row][col] = a[col][row];
		}
	}

	// The inverse of the translation is -R(transpose) * T
	// multpiply the transpose of the rotation portion by the 
	// initial translation portion of the input matrix.
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			sum = sum + sol[row][col] * a[col][3];
		}
		sol[row][3] = -1.0 * sum;
		sum = 0.0;
	}

	// 4th row is just (0, 0, 0, 1)
	for (int col = 0 ; col < 4; col++) {
		sol[3][col] = (col + 1) / 4;
	}

	return sol;	
}

// This function just prints a 4x4 matrix to verify above subroutines
// are working properly, it also frees the allocated memory to keep
// main shorter
void print_matrix(float **m)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%f", m[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}

// This function just prints a 3 coordinate point to verify above subroutine
// is working properly, it also frees the allocated memory to keep main
// shorter
void print_point(float *p)
{
	for (int i = 0; i < 3; i++) {
		printf("%f", p[i]);
		printf("\t");
	}
	printf("\n");

	free(p);
}
