/* Tyler Punch
 * ECE 417
 * Purpose: Lab 2 subroutines
 */

#include <stdlib.h>
#include <stdio.h>
#include "lab3.h"

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
