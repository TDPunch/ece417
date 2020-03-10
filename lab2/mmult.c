/* Tyler Punch
 * ECE 417
 * Purpose: Lab 2 subroutines
 */

#include <stdlib.h>

float **matrix_mult(float A[4][4], float B[4][4])
{
	// Allocate memory for return array
	float **C = malloc(sizeof(float *) * 4);
	float sum = 0;

	
	for (int i = 0; i < 4; i++) {
		C[i] = malloc(sizeof(float *) * 4);
	} 

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				sum = sum + A[i][k] * B[k][j];
			}
			C[i][j] = sum;
			sum = 0;
		}
	}
	return C;
}
