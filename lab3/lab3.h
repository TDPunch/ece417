#ifndef LAB3_H
#define LAB3_H

#define PI 3.1415927

void create_prm_array(float **prms, int num_joints);
void get_joint_prms(float **prms);
void create_matrix(float **matrix);
void build_matrix(float *prms, float **htm);
void destroy_prm(float **prms);
void destroy_matrix(float **matrix);

#endif
