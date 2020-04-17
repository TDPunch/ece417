#ifndef IK_H
#define IK_H

float *find_joint_angles123(float **htm, float **prms);
float *find_joint_angles45(float **htm);
float **get_3A0(float *angles, float **prms);
float **get_3A5(float **m3A0, float **m0A5);

#endif

