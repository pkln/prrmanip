/*
Title   : workspace.c
Author  : pkln91
License : GPL v3
Description: Workspace of prr manipulator
*/
#include <stdio.h>
#include <math.h>
#include "GeometricCalc.h"

int main()
{
	float i,j,k;
	Point testpoint;
	FILE * ws;
	ws=fopen("workspace.txt","w");
	printf("Processsing...\n");
	for(i=-ROTLINK; i< BASEEDGE+ROTLINK ; i++)
	{
		printf("%f,",i);
		for(j=-ROTLINK; j< BASEEDGE+ROTLINK ; j++)
		{
			testpoint.x=i;
			testpoint.y=j;
			for(k=0; k< 360 ; k++)
			{
				if(Motion(testpoint,k))
				{
					fprintf(ws,"%f\t%f\t%f\n", i,j,k);
				}
			}
		}
	}
	return 0;
}
