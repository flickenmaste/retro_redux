//class vector 3d
//Last Edit 11/5/2013
//Will Gilstrap
/////////////////////
#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <math.h> 
#include <stdlib.h>

class vector3
{
public:
	float x;
	float y;
	float z;

	// operators
	vector3 operator+ (const vector3 &w)
	{
		vector3 temp;
		temp.x = this->x + w.x;
		temp.y = this->y + w.y;
		temp.z = this->z + w.z;
		return temp;
	}

	vector3 operator+= (const vector3 &w)
	{
		vector3 temp;
		temp.x = this->x += w.x;
		temp.y = this->y += w.y;
		temp.z = this->z += w.z;
		return temp;
	}

	vector3 operator+ (float s) //scalar add
	{
		vector3 temp;
		temp.x = this->x + s; 
		temp.y = this->y + s;
		temp.z = this->z + s;
		return temp;
	}

	vector3 operator- (const vector3 &w)
	{
		vector3 temp;
		temp.x = this->x - w.x;
		temp.y = this->y - w.y;
		temp.z = this->z - w.z;
		return temp;
	}

	vector3 operator-= (const vector3 &w)
	{
		vector3 temp;
		temp.x = this->x -= w.x;
		temp.y = this->y -= w.y;
		temp.z = this->z -= w.z;
		return temp;
	}

	vector3 operator- (float s) //scalar sub
	{
		vector3 temp;
		temp.x = this->x - s; 
		temp.y = this->y - s;
		temp.z = this->z - s;
		return temp;
	}

	vector3 operator* (float s) //scalar multi
	{
		vector3 temp;
		temp.x = this->x * s; 
		temp.y = this->y * s;
		temp.z = this->z * s;
		return temp;
	}

	vector3 operator*= (float s) //scalar multi *=
	{
		vector3 temp;
		temp.x = this->x *= s; 
		temp.y = this->y *= s;
		temp.z = this->z *= s;
		return temp;
	}

	vector3 operator/ (float s) //scalar divide
	{
		vector3 temp;
		temp.x = this->x / s; 
		temp.y = this->y / s;
		temp.z = this->z / s;
		return temp;
	}

	vector3 operator/ (float s) //scalar divide /=
	{
		vector3 temp;
		temp.x = this->x /= s; 
		temp.y = this->y /= s;
		temp.z = this->z /= s;
		return temp;
	}
	
	// functions
	static float GetMagnitude(vector3 &v)
	{
		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}

	static vector3 Normalise(vector3 &v)
	{
		float mag = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
		v = {v.x/mag, v.y/mag, v.z/mag};
		return v;
	}
	
	static vector3 GetNormal(vector3 &v) 
	{
		float mag = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
		vector3 result = {v.x/mag, v.y/mag, v.z/mag};
		return result;
	}
	
	static float DotProduct(vector3 &a, vector3 &b) 
	{ 
		return (a.x * b.x + a.y * b.y + a.z * b.z); 
	}

	static vector3 CrossProduct(vector3& c)
	{
		return vector3( this->y * c.z - this->z * c.y,
						this->z * c.x - this->x * c.z,
						this->x * c.y - this->y * c.x);
	}

};

#endif