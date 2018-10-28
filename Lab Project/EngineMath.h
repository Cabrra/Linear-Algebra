/**
* @file EngineMath.h
* This file is included in all files of the project so all major includes are
* included in this file for access by all other files and to prevent multiple
* includes and/or circular includes.
* @author Bobak Manavi (BM)
*/

#ifndef _ENGINEMATH_H_
#define _ENGINEMATH_H_

#include <cmath>

// Pie is not round, pie are squared :)
#define PI		3.14159f

// Roundoff error to be ignored in floating point number comparisons
#define EPSILON 0.00001f

/**
* Structure represents a 
* vector with 4 components
*/
typedef union TVECTOR
{
	// array access to vector elements
	float e[4];

	// individual component access
	struct  
	{
		float x,y,z,w;
	};
}*LPTVECTOR;

/**
* Constant world axis
*/
const TVECTOR gc_xAxis = {1.0f,0.0f,0.0f,0.0f};
const TVECTOR gc_yAxis = {0.0f,1.0f,0.0f,0.0f};
const TVECTOR gc_zAxis = {0.0f,0.0f,1.0f,0.0f};

/**
* Structure represents a 4x4 matrix 
* row major.
*/
typedef union TMATRIX
{
	// NOTE - first 4 are _e11 - _e14
	float e[16];

	// Single elements in row major format
	struct  
	{
		float _e11,_e12,_e13,_e14;
		float _e21,_e22,_e23,_e24;
		float _e31,_e32,_e33,_e34;
		float _e41,_e42,_e43,_e44;
	};
}*LPTMATRIX;

//////////////////////////////////////////////////////////////////////////
// All math functions. Comments in cpp file
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// General Utility functions
/////////////////////////////////////////////////////////////////////////

bool IsEqual(float a, float b);

bool IsZero(float a);

float Max(float a, float b);

float Min(float a, float b);

float Degrees_To_Radians(float Deg);

float Radians_To_Degrees(float Rad);

//////////////////////////////////////////////////////////////////////////
// Vector Functions
//////////////////////////////////////////////////////////////////////////

bool    Vector_IsEqual(TVECTOR v, TVECTOR w);

TVECTOR Vector_Add(TVECTOR v, TVECTOR w);

TVECTOR Vector_Sub(TVECTOR v, TVECTOR w);

TVECTOR Vector_Scalar_Multiply(TVECTOR v, float s);

TVECTOR Vector_Negate(TVECTOR v);

float   Vector_Dot(TVECTOR v, TVECTOR w);

TVECTOR Vector_Cross(TVECTOR v, TVECTOR w);

float   Vector_LengthSq(TVECTOR v);

float   Vector_Length(TVECTOR v);

TVECTOR Vector_Normalize(TVECTOR v);

TVECTOR Vector_Homogenise(TVECTOR v);

TVECTOR Vector_Maximize(TVECTOR v, TVECTOR w);

TVECTOR Vector_Minimize(TVECTOR v, TVECTOR w);

TVECTOR Vector_Average(TVECTOR v, TVECTOR w);

float   Vector_AngleBetween(TVECTOR v, TVECTOR w);

float   Vector_Component(TVECTOR v, TVECTOR w);

TVECTOR Vector_Project(TVECTOR v, TVECTOR w);

TVECTOR Vector_Reflect(TVECTOR v, TVECTOR w);

//////////////////////////////////////////////////////////////////////////
// Matrix Functions
//////////////////////////////////////////////////////////////////////////

TMATRIX Matrix_Zero(void);

TMATRIX Matrix_Identity(void);

TMATRIX Matrix_Create_Translation(float x, float y, float z);

TMATRIX Matrix_Create_Scale(float x, float y, float z);

TMATRIX Matrix_Create_Rotation_X(float Deg);

TMATRIX Matrix_Create_Rotation_Y(float Deg);

TMATRIX Matrix_Create_Rotation_Z(float Deg);

TMATRIX Matrix_Matrix_Add(TMATRIX m, TMATRIX n);

TMATRIX Matrix_Matrix_Sub(TMATRIX m, TMATRIX n);

TMATRIX Matrix_Scalar_Multiply(TMATRIX m, float s);

TMATRIX Matrix_Negate(TMATRIX m);

TMATRIX Matrix_Transpose(TMATRIX m);

TVECTOR Vector_Matrix_Multiply(TVECTOR v, TMATRIX m);

TVECTOR Matrix_Vector_Multiply(TMATRIX m, TVECTOR v);

TMATRIX Matrix_Matrix_Multiply(TMATRIX m, TMATRIX n);

float   Matrix_Determinant(TMATRIX m);

TMATRIX Matrix_Inverse(TMATRIX m);

#endif