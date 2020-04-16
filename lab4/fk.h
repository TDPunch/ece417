#ifndef FK_H
#define FK_H

#define PI 3.1415927

/* --- Lab 3 function prototypes --- */
float **create_prm_array(int num_joints);
float **create_matrix(void);
float **get_thetas(float **prms, int num_joints);
float **build_matrix(float **prms, float **return_matrix, int col);
void destroy_prm(float **prms, int num_joints);
void destroy_matrix(float **matrix);

/* --- Lab 2 function prototypes --- */
float **matrix_mult(float **A, float **B);
float *point_trans(float R[4][4], float Puvw[3]);
float **inverse(float a[4][4]);
void print_matrix(float **m);
void print_point(float *p);

#endif
