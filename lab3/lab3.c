#include <stdio.h>
#include <stdlib.h>

// Prompt the user for the 4 joint parameters
void get_joint_prms(float *prms)
{
	printf("Enter joint parameter 'd': ");
	scanf("%f", prms);
	printf("Enter joint parameter 'theta': ");
	scanf("%f", prms+1);
	printf("Enter joint parameter 'a': ");
	scanf("%f", prms+2);
	printf("Enter joint parameter 'alpha': ");
	scanf("%f", prms+3);
}
