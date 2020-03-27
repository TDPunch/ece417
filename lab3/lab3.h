#ifndef LAB3_H
#define LAB3_H

#define PI 3.1415927

void create_prm_array(float **prms, int num_joints);
//void get_joint_prms(float **prms);
void create_theta_arr(float *arr, int num_joints);
void create_matrix(float **matrix);
void get_thetas(float *arr, int num_joints);
void build_matrix(float *prms, float **htm);
//void build_matrix(float arr, float **htm);
void destroy_prm(float **prms);
void destroy_thetas(float *arr);
void destroy_matrix(float **matrix);

#endif
