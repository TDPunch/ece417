#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

int main(int argc, char *argv[])
{
	float **prms, **T1, **T2, **T3, **T4, **T5, **sol;
	int num_joints = atoi(argv[1]);

	printf("%d", num_joints);

	// Allocate memory for joint parameters and matrices
	create_prm_array(prms, num_joints);
	//create_matrix(T1);
	//create_matrix(T2);
	//create_matrix(T3);
	//create_matrix(T4);
	//create_matrix(T5);
	//create_matrix(sol);

	// d values
	prms[0][0] = 27.2;
	prms[1][0] = 0.0;
	prms[2][0] = 0.0;
	prms[3][0] = 0.0;
//	prms[4][0] = 10.5;

	// a values
	prms[0][2] = 0.0;
	prms[1][2] = 19.2;
	prms[2][2] = 19.2;
	prms[3][2] = 0.0;
//	prms[4][2] = 0.0;

	// alpha values
	prms[0][3] = 90.0;
	prms[1][3] = 180.0;
	prms[2][3] = 0.0;
	prms[3][3] = 90.0;
//	prms[4][3] = 0.0;

	//get_thetas(prms, num_joints);
	
	//build_matrix(prms[0], T1);

	// Deallocate the memory
	destroy_prm(prms, num_joints);
	//destroy_matrix(T1);
	//destroy_matrix(T2);
	//destroy_matrix(T3);
	//destroy_matrix(T4);
	//destroy_matrix(T5);
	//destroy_matrix(sol);

	return 0;
}
