//Last Edit 11/19/2013
//Will Gilstrap
/////////////////////
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "Vector3.h"
#include "Vector4.h"

class Matrix3
{
public:
	static float m_aMatrix[3][3];

	//Set Matrix
	static void SetMatrixID(vector3 &a, vector3 &b, vector3 &c)
	{
		m_aMatrix[0][0] = a.x;
		m_aMatrix[0][1] = a.y;
		m_aMatrix[0][2] = a.z;
		m_aMatrix[1][0] = b.x;
		m_aMatrix[1][1] = b.y;
		m_aMatrix[1][2] = b.z;
		m_aMatrix[2][0] = c.x;
		m_aMatrix[2][1] = c.y;
		m_aMatrix[2][2] = c.z;
	}

	// matrix multiplication
	static Matrix3 Multi(Matrix3 &a, Matrix3 &b)
	{
		Matrix3 temp;
		float product[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

		for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 3; inner++) {
				product[row][col] += a.m_aMatrix[row][inner] * b.m_aMatrix[inner][col];
            }
            std::cout << product[row][col] << "  ";
        }
        std::cout << "\n";
		}

		temp.m_aMatrix[0][0] = product[0][0];
		temp.m_aMatrix[0][1] = product[0][1];
		temp.m_aMatrix[0][2] = product[0][2];
		temp.m_aMatrix[1][0] = product[1][0];
		temp.m_aMatrix[1][1] = product[1][1];
		temp.m_aMatrix[1][2] = product[1][2];
		temp.m_aMatrix[2][0] = product[2][0];
		temp.m_aMatrix[2][1] = product[2][1];
		temp.m_aMatrix[2][2] = product[2][2];

		return temp;
	}

};

class Matrix4
{
public:
	static float m_aMatrix[4][4];

	//Set Matrix
	static void SetMatrixID(vector4 &a, vector4 &b, vector4 &c, vector4 &d)
	{
		m_aMatrix[0][0] = a.t;
		m_aMatrix[0][1] = a.x;
		m_aMatrix[0][2] = a.y;
		m_aMatrix[0][3] = a.z;
		m_aMatrix[1][0] = b.t;
		m_aMatrix[1][1] = b.x;
		m_aMatrix[1][2] = b.y;
		m_aMatrix[1][3] = b.z;
		m_aMatrix[2][0] = c.t;
		m_aMatrix[2][1] = c.x;
		m_aMatrix[2][2] = c.y;
		m_aMatrix[2][3] = c.z;
		m_aMatrix[3][0] = d.t;
		m_aMatrix[3][1] = d.x;
		m_aMatrix[3][2] = d.y;
		m_aMatrix[3][3] = d.z;
	}

	// matrix multiplication
	static Matrix4 Multi(Matrix4 &a, Matrix4 &b)
	{
		Matrix4 temp;
		float product[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

		for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 4; inner++) {
				product[row][col] += a.m_aMatrix[row][inner] * b.m_aMatrix[inner][col];
            }
            std::cout << product[row][col] << "  ";
        }
        std::cout << "\n";
		}

		temp.m_aMatrix[0][0] = product[0][0];
		temp.m_aMatrix[0][1] = product[0][1];
		temp.m_aMatrix[0][2] = product[0][2];
		temp.m_aMatrix[0][3] = product[0][3];
		temp.m_aMatrix[1][0] = product[1][0];
		temp.m_aMatrix[1][1] = product[1][1];
		temp.m_aMatrix[1][2] = product[1][2];
		temp.m_aMatrix[1][3] = product[1][3];
		temp.m_aMatrix[2][0] = product[2][0];
		temp.m_aMatrix[2][1] = product[2][1];
		temp.m_aMatrix[2][2] = product[2][2];
		temp.m_aMatrix[2][3] = product[2][3];
		temp.m_aMatrix[3][0] = product[3][0];
		temp.m_aMatrix[3][1] = product[3][1];
		temp.m_aMatrix[3][2] = product[3][2];
		temp.m_aMatrix[3][3] = product[3][3];

		return temp;
	}
};

#endif