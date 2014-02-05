/*
Title   : GeometricCalc.c
Author  : pkln91
License : GPL v3
Description:  Function definitions for GeometricCalc
*/
#include <math.h>
#include "GeometricCalc.h"

static float run[3]={75, 75, 75};

Line edge[3]={
	{0, 1, 0},
	{1, sqrt(3), -sqrt(3)*BASEEDGE},
	{1, sqrt(3), 0}
};

Point baseVert[]={
	{0, 0},
	{BASEEDGE, 0},
	{BASEEDGE/2, sqrt(3)*BASEEDGE/2}
};

float hypotenuse(float val1,float val2)	// Hypotenuse of a triangle Given two sides
{
	float val;
	val=sqrt(val1*val1 + val2*val2);
	return val;
}

float Side(float val1,float val2)		// Side of a triangle Given a side and hypotenuse
{
	float val;
	val=sqrt(val1*val1 - val2*val2);
	return val;
}

float Dist(Point p1, Point p2)			// Distance between two points
{
	float dist;
	dist=hypotenuse(p1.x-p2.x, p1.y-p2.y);
	return dist;
}

float PerpDist(Point p, Line l)			// Perpendicular Distance from a point to a line
{	
	float numerator;
	float denominator;
	float dist;
	numerator=abs(l.a*p.x + l.b*p.y + l.c);
	denominator=hypotenuse(p.x, p.y);
	dist=numerator/denominator;
	return dist;
}

Point Location(Point p, float r, float angle) {
	Point position;
	angle=PI*angle/180;
	position.x = p.x + r*cos(angle);
	position.y = p.y + r*sin(angle);
	return position;
}

int Motion(Point p, float angle) {
	int i;
	float plus,minus;
	float a[3];
	float b[3];
	float temprun[3];
	Point vertex[3];
	vertex[0]=p;
	vertex[1]=Location(p, ROTLINK, angle);
	vertex[2]=Location(p, ROTLINK, angle+PI/3);
	for(i=0;i<3;i++){
		a[i]=Side(Dist(baseVert[i],vertex[i]),PerpDist(vertex[i],edge[i]));
		b[i]=Side(ROTLINK,PerpDist(vertex[i],edge[i]));
		plus=a[i]+b[i];
		minus=a[i]-b[i];
		if(plus>0 && plus<MAXRUNLENGTH && minus>0 && minus<MAXRUNLENGTH)
		{
			temprun[i]= (abs(plus-run[i]))<(abs(minus-run[i]))?plus:minus;
		}
		else if(plus>0 && plus<MAXRUNLENGTH)
		{
			temprun[i]=plus;
		}
		else if(minus>0 && minus<MAXRUNLENGTH)
		{
			temprun[i]=minus;
		}
		else
		{
			return 0;
		}
	}
	for(i=0;i<3;i++)
	{
		run[i]=temprun[i];
	}
	return 1;
}
