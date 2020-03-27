#ifndef MMULT_H
#define MMULT_H

float **matrix_mult(float A[4][4], float B[4][4]);
float *point_trans(float R[4][4], float Puvw[3]);
float **inverse(float a[4][4]);
void print_matrix(float **m);
void print_point(float *p);

#endif
