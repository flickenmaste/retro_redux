//class vector 4d
//Last Edit 11/5/2013
//Will Gilstrap
/////////////////////
#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include <math.h> 
#include <stdlib.h>

class vector4
{
public:
	float t;
	float x;
	float y;
	float z;

	static vector4 Normalise(vector4 &v)
	{
		float mag = sqrt(v.t*v.t + v.x*v.x + v.y*v.y + v.z*v.z);
		v = {v.t/mag, v.x/mag, v.y/mag, v.z/mag};
		return v;
	}
};

#endif