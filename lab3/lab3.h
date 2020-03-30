#ifndef LAB3_H
#define LAB3_H

#define PI 3.1415927

float **create_prm_array(int num_joints);
float **create_matrix(void);
float **get_thetas(float **prms, int num_joints);
float **build_matrix(float **prms, float **return_matrix, int col);
void destroy_prm(float **prms, int num_joints);
void destroy_matrix(float **matrix);

#endif
