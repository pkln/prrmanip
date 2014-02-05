/*
Title   : GeometricCalc.h
Author  : pkln91
License : GPL v3
Description: Prerequisites for PRR Manipulator Analysis
*/

#ifndef _GeometricCalc_h
#define _GeometricCalc_h

#define PI 3.14
#define BASEEDGE 540.0
#define FLOATEDGE 94.0
#define ROTLINK 183.0
#define MAXRUNLENGTH 150.0

typedef struct {
	float x;	// X co-ordinate
	float y;	// Y co-ordinate
} Point;

typedef struct {
	float a;	// Coefficient of X
	float b;	// Coefficient of Y
	float c;	// Constant term
} Line;

//float Dist(Point p1, Point p2);
//float PerpDist(Point p, Line l);
//Point Location(Point p, float r, float angle);
int Motion(Point p, float angle);

#endif
