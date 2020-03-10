#include <stdio.h>
#include <stdlib.h>
#include "mmult.h"

int main(int argc, char *argv[]) 
{
	float **solution = NULL;
	float x = (2.0/7.0), y = (3.0/7.0), z = (6.0/7.0);

	float a[4][4] = { 
		{y, x, z, 4},
		{x, z, -1*y, 5},
	    {-1*z, y, x, 6},
		{0, 0, 0, 1}	
	};

	float b[4][4] = {
		{x, -1*z, y, 1},
		{z, y, x, 2},
		{-1*y, x, z, 3},
		{0, 0, 0, 1}
	};

	solution = matrix_mult(a, b);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%f", solution[i][j]);
			printf("\t");
		}
		printf("\n");
	}

	for (int i = 0; i < 4; i++) {
		free(solution[i]);
	}
	free(solution);
	return 0;
}
