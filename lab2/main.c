// This is the main program that asks for 2 4x4 matrices and a point,
// then calls functions that multiply the two matrices, transform the
// point and take the inverse of a matrix respectively. All results
// are output to stdout.

#include <stdio.h>	/* Inlcude standard C library functions */
#include <stdlib.h> /* malloc(), free()*/
#include "mmult.h"  /* Include matrix manipulation functions */

int main(int argc, char *argv[]) 
{
	/*
	// Variable declaration and initialization
	float **solution = NULL;
	float *px = NULL;
	float x = (2.0/7.0), y = (3.0/7.0), z = (6.0/7.0);

	float a[4][4] = { 
		{y,   	 x,   z, 	  4.0},
		{x,		 z,   -1.0*y, 5.0},
	    {-1.0*z, y,   x, 	  6.0},
		{0.0, 	 0.0, 0.0, 	  1.0}	
	};

	float b[4][4] = {
		{x, 	 -1.0*z, y,   1.0},
		{z, 	 y, 	 x,   2.0},
		{-1.0*y, x, 	 z,   3.0},
		{0.0, 	 0.0,	 0.0, 1.0}
	};

	float p[3] = {0.0,1.0,2.0};

	// Call multiplication function and print result
	solution = matrix_mult(a, b);
	print_composite(solution);

	// Call transform function and print result
	px = point_trans(b, p);
	print_point(px);

	// Call inverse function and print result
	solution = inverse(b);
	print_composite(solution);
	*/
	
	// Variable decleration and initialization
	float a[4][4] = {0}, b[4][4] = {0}, p[3] = {0};
	float **comp = NULL, *transform = NULL, **inv = NULL;
	char xyz[3] = {'x','y','z'};

	printf("Enter the first matrix:\n");

	// Input matrix from user
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("Enter matrix element [%d, %d]: ", i, j);
			scanf("%f", &a[i][j]);
		}
	}

	printf("Enter the second matrix:\n");

	// Input matrix from user
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("Enter matrix element [%d, %d]: ", i, j);
			scanf("%f", &b[i][j]);
		}
	}

	printf("Enter the point:\n");

	// Input point from user
	for (int i = 0; i < 3; i++) {
		printf("Enter %c coordinate: ", xyz[i]);
		scanf("%f", &p[i]);
	}

	print_matrix(matrix_mult(a, b));
	printf("\n");
	print_point(point_trans(b, p));
	printf("\n");
	print_matrix(inverse(b));

	return 0;
}
