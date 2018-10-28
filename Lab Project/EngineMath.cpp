/**
* @file EngineMath.cpp
*
* @author Bobak Manavi (BM)
*/

#include "EngineMath.h"


//////////////////////////////////////////////////////////////////////////
// Common math functions
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// General Utility functions
//////////////////////////////////////////////////////////////////////////

// Are two floating point numbers equal to each other
// Floating Point Error Safe
//
// IN:		a		The first number
//			b		The second number
//
// RETURN: TRUE iff |a-b| < Tolerance
//
// NOTE:	EPSILON is tolerance
bool IsEqual(float a, float b)
{
	// NOTE: Do not modify.
	return fabs(a - b) < EPSILON;
}

// Is a floating point value equal to zero
// Floating Point Error Safe
//
// IN:		a		The number to check
//
// RETURN:	TRUE iff |a| < Tolerance
//
// NOTE:	Tolerance set by EPSILON
bool IsZero(float a)
{
	// NOTE: Do not modify
	return (fabs(a))<EPSILON;
}

// RETURN: MAX of two numbers
float Max(float a, float b)
{
	// NOTE: Do not modify.
	return (a > b) ? a : b;
}

// RETURN: MIN of two numbers
float Min(float a, float b)
{
	// NOTE: Do not modify.
	return (a < b) ? a : b;
}

// RETURN: Converts input to radian measure
float Degrees_To_Radians(float Deg)
{
	// NOTE: Do not modify.
	return Deg * PI / 180.0f;
}

// RETURN: Converts input to degree measure
float Radians_To_Degrees(float Rad)
{
	// NOTE: Do not modify.
	return Rad * 180.0f / PI;
}
////////////////////////////////////////////////////////////////////////
// Linear Algebra Functions Day 1
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// Vector Functions
//////////////////////////////////////////////////////////////////////////

// Check if two TVECTOR's are equal to each other
//
// IN:		v		First Vector
//			w		Second Vector
//
// RETURN:  True if v==w, False otherwise
//
// NOTE:	Use's all four components
//			Should be floating point error safe.
bool Vector_IsEqual(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.

	if (IsEqual(v.x, w.x) && IsEqual(v.y, w.y) && IsEqual(v.z, w.z) && IsEqual(v.w, w.w))
		return true;
	return false;
}

// ADD two TVECTOR's togother
//
// IN:		v		First Vector. Left Hand Side
//			w		Second Vector. Right Hand Side
//
// RETURN:  v + w
//
// NOTE:	Use's all four components
TVECTOR Vector_Add(TVECTOR v, TVECTOR w)
{
	v.x += w.x;
	v.y += w.y;
	v.z += w.z;
	v.w += w.w;
	// TODO LAB 1: Replace with your implementation.
	return v;
}

// SUBTRACT one TVECTOR from another
//
// IN:		v		First Vector. Left Hand Side
//			w		Second Vector. Right Hand Side
//
// RETURN:  v - w
//
// NOTE:	Use's all four components
TVECTOR Vector_Sub(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.
	v.x -= w.x;
	v.y -= w.y;
	v.z -= w.z;
	v.w -= w.w;

	return v;
}

// MULTIPLY all four components of a TVECTOR by a scalar
//
// IN:		v		The vector to scale
//			s		The value to scale by
//
// RETURN:  s * v
TVECTOR Vector_Scalar_Multiply(TVECTOR v, float s)
{
	// TODO LAB 1: Replace with your implementation.
	v.x = v.x * s;
	v.y = v.y * s;
	v.z = v.z * s;
	v.w = v.w * s;

	return v;
}

// NEGATE all the components of a TVECTOR
//
// IN:		v		The vector to negate
//
// RETURN:	-1 * v
//
// NOTE:	Use's all four components
TVECTOR Vector_Negate(TVECTOR v)
{
	// TODO LAB 1: Replace with your implementation.

	v.x = v.x * (-1);
	v.y = v.y * (-1);
	v.z = v.z * (-1);
	v.w = v.w * (-1);

	return v;
}

// Perform a Dot Product on two TVECTOR's
//
// IN:		v		First Vector. Left Hand Side
//			w		Second Vector. Right Hand Side
//
// RETURN:  v (DOT) w
//
// NOTE:	Use's all four components
float Vector_Dot(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.

	float dot = 0;
	dot = (v.x * w.x) + (v.y * w.y) + (v.z * w.z) + (v.w * w.w);
	return dot;
}

// Perform a Cross Product on two TVECTOR's
//
// IN:		v		First Vector. Left Hand Side
//			w		Second Vector. Right Hand Side
//
// RETURN:  v (CROSS) w
//
// NOTE:	The w-component of each vector is not used.
//			The resultant vector will have a w-component of zero.
TVECTOR Vector_Cross(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.

	TVECTOR p = v;

	v.x = p.y * w.z - p.z * w.y;
	v.y = p.z * w.x - p.x * w.z;
	v.z = p.x * w.y - p.y * w.x;
	v.w = 0;

	return v;
}

// Find the squared length of a TVECTOR
//
// IN:		v		The vector to find the squared length of
//
// RETURN:	Squared Length of TVECTOR
//
// NOTE:	Use's all four components
float Vector_LengthSq(TVECTOR v)
{
	// TODO LAB 1: Replace with your implementation.

	float square = 0;
	square = v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w;
	return square;
}

// Find the length of a TVECTOR
//
// IN:		v		The vector to find the length of
//
// RETURN:	Length of TVECTOR
//
// NOTE:	Use's all four components
float Vector_Length(TVECTOR v)
{
	// TODO LAB 1: Replace with your implementation.
	float root = sqrtf(Vector_LengthSq(v));
	return root;
}

// Normalize a TVECTOR
//
// IN:		v		The vector to normalize
//
// RETURN:	Normalized version of v
//
// NOTE:	Use's all four components
TVECTOR Vector_Normalize(TVECTOR v)
{
	// TODO LAB 1: Replace with your implementation.

	float temp = Vector_Length(v);
	if (!IsZero(temp)){
		v.x = v.x / temp;
		v.y = v.y / temp;
		v.z = v.z / temp;
		v.w = v.w / temp;

	}
	else
		v.x = v.y = v.z = v.w = 0;

	return v;

}

// Makes a TVECTOR's w-component normalized
//
// IN:		v		The vector (point object) to homogenise
//
// RETURN:	The homogenised vector (point)
//
// NOTE:	If the w-component of the vector is 0 then the
//			function will return a zero vector with a w-component
//			of 0.
TVECTOR Vector_Homogenise(TVECTOR v)
{
	// TODO LAB 1: Replace with your implementation.

	if (!IsZero(v.w)){
		v.x = v.x / v.w;
		v.y = v.y / v.w;
		v.z = v.z / v.w;
		v.w = v.w / v.w;

	}
	else
		v.x = v.y = v.z = v.w = 0;

	return v;
}

// Get a TVECTOR made from the maximun components of two TVECTORs
//
// IN:		v		The first vector
//			w		The second vector
//
// RETURN:	A maximized vector
//
// NOTE:	Use's all four components
TVECTOR Vector_Maximize(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.
	v.x = Max(v.x, w.x);
	v.y = Max(v.y, w.y);
	v.z = Max(v.z, w.z);
	v.w = Max(v.w, w.w);

	return v;
}

// Get a TVECTOR made from the minimum components of two TVECTOR's
//
// IN:		v		The first vector
//			w		The second vector
//
// RETURN:	A minimum vector
//
// NOTE:	Use's all four components
TVECTOR Vector_Minimize(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.

	v.x = Min(v.x, w.x);
	v.y = Min(v.y, w.y);
	v.z = Min(v.z, w.z);
	v.w = Min(v.w, w.w);

	return v;
}

// Get a TVECTOR made from the average of two TVECTORs
//
// IN:		v		The first vector
//			w		The second vector
//
// RETURN:	A vector made from the average of two vectors
//
// NOTE:	Use's all four components

TVECTOR Vector_Average(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.

	TVECTOR temp;

	temp.x = (v.x + w.x) / 2;
	temp.y = (v.y + w.y) / 2;
	temp.z = (v.z + w.z) / 2;
	temp.w = (v.w + w.w) / 2;

	return temp;
}

// Find the angle between two TVECTORs
//
// IN:		v		The first vector
//			w		The second vector
//
// RETURN:  The angle in degrees between the two vectors
//
// NOTE:	If either vector is a zero vector then the return
//			value will be 0.
float Vector_AngleBetween(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.
	float angle = 0;

	if (!IsZero(Vector_Length(v)) && !IsZero(Vector_Length(w))){

		angle = acosf((Vector_Dot(v, w) / (Vector_Length(v) * Vector_Length(w))));
		angle = angle * 180 / PI;
	}
	return angle;
}

// Get the distance one TVECTOR points in the direction of another
// TVECTOR
//
// IN:		v		The first vector
//			w		The direction of the component
//
// RETURN:	The distance that v points in the direction of w.
//
// NOTE:	If w or v is a zero vector then the return value is zero.
float Vector_Component(TVECTOR v, TVECTOR w)
{
	float temp = 0;
	if (!IsZero(w.x) || !IsZero(w.y) || !IsZero(w.z) || !IsZero(v.w)){
		w = Vector_Normalize(w);
		temp = Vector_Dot(v, w);
	}
	// TODO LAB 1: Replace with your implementation.
	return temp;
}

// Get the TVECTOR that represents v projected on w.
//
// IN:		v		The first vector
//			w		The direction of the projection
//
// RETURN:	The projection of v onto w
//
// NOTE:	If w or v is a zero vector then the return value is zero.
TVECTOR Vector_Project(TVECTOR v, TVECTOR w)
{
	// TODO LAB 1: Replace with your implementation.
	float comp = Vector_LengthSq(w);
	float dot = Vector_Dot(v, w);

	if (!IsZero(comp)){
		float temp = dot / comp;

		v.x = w.x * temp;
		v.y = w.y * temp;
		v.z = w.z * temp;
		v.w = w.w * temp;

		//v = Vector_Scalar_Multiply(v, temp);
	}
	else
		v.x = v.y = v.z = v.w = 0;
	return v;
}

////////////////////////////////////////////////////////////////////////
// Functions Lab  #2
///////////////////////////////////////////////////////////////////////


// Get the reflection of v across w
//
// IN:		v		The vector to reflect 
//			w		The "axis" to reflect across 
//
// RETURN:	v reflected across w
//
// NOTE:	If w is a zero vector then return -v.
TVECTOR Vector_Reflect(TVECTOR v, TVECTOR w)
{
	// TODO LAB 2: Replace with your implementation.

	if (IsZero(w.x) && IsZero(w.y) && IsZero(w.z) && IsZero(w.w))
		v = Vector_Negate(v);
	else{
		TVECTOR l = v;  // L doesn't need to normalize
		TVECTOR n = Vector_Normalize(w);
		float f = Vector_Dot(l, n);
		f = f * 2;
		n = Vector_Scalar_Multiply(n, f);

		v = Vector_Add(Vector_Negate(l), n);

	}

	return v;
}

//////////////////////////////////////////////////////////////////////////
// Matrix Functions
//////////////////////////////////////////////////////////////////////////

// Get a [0] matrix
//
// RETURN: A 0 4x4 matrix
TMATRIX Matrix_Zero(void)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { 0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0 };

	return m;
}

// Get a [I] matrix
//
// RETURN: A 4x4 Identity matrix
TMATRIX Matrix_Identity(void)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { 1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1 };
	return m;
}

// Get a translation matrix
//
// IN:		x		Amount of translation in the x direction
//			y		Amount of translation in the y direction
//			z		Amount of translation in the z direction
//
// RETURN:	The translation matrix
TMATRIX Matrix_Create_Translation(float x, float y, float z)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { 1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1 };

	return m;
}

// Create a scale matrix
//
// IN:		x		Amount to scale in the x direction
//			y		Amount to scale in the y direction
//			z		Amount to scale in the z direction
//
// RETURN:	The scale matrix
TMATRIX Matrix_Create_Scale(float x, float y, float z)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1 };
	return m;
}

// Get a rotation matrix for rotation about the x-axis
//
// IN:		Deg		Angle to rotate ( Degree measure)
//
// RETURN:	A X-Rotation Matrix
TMATRIX Matrix_Create_Rotation_X(float Deg)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { 1, 0, 0, 0,
		0, cos(Degrees_To_Radians(Deg)), -sin(Degrees_To_Radians(Deg)), 0,
		0, sin(Degrees_To_Radians(Deg)), cos(Degrees_To_Radians(Deg)), 0,
		0, 0, 0, 1 };


	return m;
}

// Get a rotation matrix for rotation about the y-axis
//
// IN:		Deg		Angle to rotate ( Degree measure)
//
// RETURN:	A Y-Rotation Matrix
TMATRIX Matrix_Create_Rotation_Y(float Deg)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { cos(Degrees_To_Radians(Deg)), 0, sin(Degrees_To_Radians(Deg)), 0,
		0, 1, 0, 0,
		-sin(Degrees_To_Radians(Deg)), 0, cos(Degrees_To_Radians(Deg)), 0,
		0, 0, 0, 1 };


	return m;
}

// Get a rotation matrix for rotation about the z-axis
//
// IN:		Deg		Angle to rotate ( Degree measure)
//
// RETURN:	A Z-Rotation Matrix
TMATRIX Matrix_Create_Rotation_Z(float Deg)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = { cos(Degrees_To_Radians(Deg)), -sin(Degrees_To_Radians(Deg)), 0, 0,
		sin(Degrees_To_Radians(Deg)), cos(Degrees_To_Radians(Deg)), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1 };

	return m;
}

// ADD two matrices together
//
// IN:		m		The first matrix
//			n		The second matrix
//
// RETURN: m + n
TMATRIX Matrix_Matrix_Add(TMATRIX m, TMATRIX n)
{
	// TODO LAB 2: Replace with your implementation.

	m._e11 = m._e11 + n._e11;
	m._e12 = m._e12 + n._e12;
	m._e13 = m._e13 + n._e13;
	m._e14 = m._e14 + n._e14;

	m._e21 = m._e21 + n._e21;
	m._e22 = m._e22 + n._e22;
	m._e23 = m._e23 + n._e23;
	m._e24 = m._e24 + n._e24;

	m._e31 = m._e31 + n._e31;
	m._e32 = m._e32 + n._e32;
	m._e33 = m._e33 + n._e33;
	m._e34 = m._e34 + n._e34;

	m._e41 = m._e41 + n._e41;
	m._e42 = m._e42 + n._e42;
	m._e43 = m._e43 + n._e43;
	m._e44 = m._e44 + n._e44;

	return m;
}

// SUBTRACT two matrices
//
// IN:		m		The first matrix (left hand side)
//			n		The second matrix (right hand side)
//
// RETURN: m - n
TMATRIX Matrix_Matrix_Sub(TMATRIX m, TMATRIX n)
{
	// TODO LAB 2: Replace with your implementation.

	m._e11 = m._e11 - n._e11;
	m._e12 = m._e12 - n._e12;
	m._e13 = m._e13 - n._e13;
	m._e14 = m._e14 - n._e14;

	m._e21 = m._e21 - n._e21;
	m._e22 = m._e22 - n._e22;
	m._e23 = m._e23 - n._e23;
	m._e24 = m._e24 - n._e24;

	m._e31 = m._e31 - n._e31;
	m._e32 = m._e32 - n._e32;
	m._e33 = m._e33 - n._e33;
	m._e34 = m._e34 - n._e34;

	m._e41 = m._e41 - n._e41;
	m._e42 = m._e42 - n._e42;
	m._e43 = m._e43 - n._e43;
	m._e44 = m._e44 - n._e44;

	return m;
}

// Multiply a matrix by a scalar
//
// IN:		m		The matrix to be scaled (right hand side)
//			s		The value to scale by   (left hand side)
//
// RETURN:	The matrix formed by s*[m]
TMATRIX Matrix_Scalar_Multiply(TMATRIX m, float s)
{
	// TODO LAB 2: Replace with your implementation.

	m._e11 = m._e11 * s;
	m._e12 = m._e12 * s;
	m._e13 = m._e13 * s;
	m._e14 = m._e14 * s;

	m._e21 = m._e21 * s;
	m._e22 = m._e22 * s;
	m._e23 = m._e23 * s;
	m._e24 = m._e24 * s;

	m._e31 = m._e31 * s;
	m._e32 = m._e32 * s;
	m._e33 = m._e33 * s;
	m._e34 = m._e34 * s;

	m._e41 = m._e41 * s;
	m._e42 = m._e42 * s;
	m._e43 = m._e43 * s;
	m._e44 = m._e44 * s;


	return m;
}

// Negate a matrix
//
// IN:		m		The matrix to negate
//
// RETURN:  The negation of m
TMATRIX Matrix_Negate(TMATRIX m)
{
	// TODO LAB 2: Replace with your implementation.

	m._e11 = -m._e11;
	m._e12 = -m._e12;
	m._e13 = -m._e13;
	m._e14 = -m._e14;

	m._e21 = -m._e21;
	m._e22 = -m._e22;
	m._e23 = -m._e23;
	m._e24 = -m._e24;

	m._e31 = -m._e31;
	m._e32 = -m._e32;
	m._e33 = -m._e33;
	m._e34 = -m._e34;

	m._e41 = -m._e41;
	m._e42 = -m._e42;
	m._e43 = -m._e43;
	m._e44 = -m._e44;

	return m;
}

// Transpose a matrix
//
// IN:		m		The matrix to transpose
//
// RETURN:	The transpose of m
TMATRIX Matrix_Transpose(TMATRIX m)
{
	// TODO LAB 2: Replace with your implementation.

	TMATRIX tras = m;
	// 	m._e11 = tras._e11;
	m._e21 = tras._e12;
	m._e31 = tras._e13;
	m._e41 = tras._e14;

	m._e12 = tras._e21;
	//m._e22 = tras._e22;
	m._e32 = tras._e23;
	m._e42 = tras._e24;

	m._e13 = tras._e31;
	m._e23 = tras._e32;
	//m._e33 = tras._e33;
	m._e43 = tras._e34;

	m._e14 = tras._e41;
	m._e24 = tras._e42;
	m._e34 = tras._e43;
	//m._e44 = tras._e44;

	return m;
}

// Multipy a matrix and a vector
//
// IN:		m		The matrix (left hand side)
//			v		The vector (right hand side)
//
// RETURN:	[m]*v
TVECTOR Matrix_Vector_Multiply(TMATRIX m, TVECTOR v)
{
	// TODO LAB 2: Replace with your implementation.
	// 4x4 mult 4x1 ---> 4x1 result

	TVECTOR c = v;
	v.x = m._e11 * c.x + m._e12 * c.y + m._e13 * c.z + m._e14 * c.w;
	v.y = m._e21 * c.x + m._e22 * c.y + m._e23 * c.z + m._e24 * c.w;
	v.z = m._e31 * c.x + m._e32 * c.y + m._e33 * c.z + m._e34 * c.w;
	v.w = m._e41 * c.x + m._e42 * c.y + m._e43 * c.z + m._e44 * c.w;


	return v;
}

// Multipy a vector and a matrix
//
// IN:		v		The vector ( left hand side)
//			m		The matrix (right hand side)
//
// RETURN:	v*[m]
TVECTOR Vector_Matrix_Multiply(TVECTOR v, TMATRIX m)
{
	// TODO LAB 2: Replace with your implementation.
	TVECTOR c = v;
	v.x = m._e11 * c.x + m._e21 * c.y + m._e31 * c.z + m._e41 * c.w;
	v.y = m._e12 * c.x + m._e22 * c.y + m._e32 * c.z + m._e42 * c.w;
	v.z = m._e13 * c.x + m._e23 * c.y + m._e33 * c.z + m._e43 * c.w;
	v.w = m._e14 * c.x + m._e24 * c.y + m._e34 * c.z + m._e44 * c.w;

	return v;
}
// Multiply a matrix by a matrix
//
// IN:		m		First Matrix (left hand side)
//			n		Second Matrix (right hand side)
//
// RETURN:	[m]*[n]
TMATRIX Matrix_Matrix_Multiply(TMATRIX m, TMATRIX n)
{
	// TODO LAB 2: Replace with your implementation.

	TMATRIX c = m;

	m._e11 = c._e11 * n._e11 + c._e12 * n._e21 + c._e13 * n._e31 + c._e14 * n._e41;
	m._e12 = c._e11 * n._e12 + c._e12 * n._e22 + c._e13 * n._e32 + c._e14 * n._e42;
	m._e13 = c._e11 * n._e13 + c._e12 * n._e23 + c._e13 * n._e33 + c._e14 * n._e43;
	m._e14 = c._e11 * n._e14 + c._e12 * n._e24 + c._e13 * n._e34 + c._e14 * n._e44;

	m._e21 = c._e21 * n._e11 + c._e22 * n._e21 + c._e23 * n._e31 + c._e24 * n._e41;
	m._e22 = c._e21 * n._e12 + c._e22 * n._e22 + c._e23 * n._e32 + c._e24 * n._e42;
	m._e23 = c._e21 * n._e13 + c._e22 * n._e23 + c._e23 * n._e33 + c._e24 * n._e43;
	m._e24 = c._e21 * n._e14 + c._e22 * n._e24 + c._e23 * n._e34 + c._e24 * n._e44;

	m._e31 = c._e31 * n._e11 + c._e32 * n._e21 + c._e33 * n._e31 + c._e34 * n._e41;
	m._e32 = c._e31 * n._e12 + c._e32 * n._e22 + c._e33 * n._e32 + c._e34 * n._e42;
	m._e33 = c._e31 * n._e13 + c._e32 * n._e23 + c._e33 * n._e33 + c._e34 * n._e43;
	m._e34 = c._e31 * n._e14 + c._e32 * n._e24 + c._e33 * n._e34 + c._e34 * n._e44;

	m._e41 = c._e41 * n._e11 + c._e42 * n._e21 + c._e43 * n._e31 + c._e44 * n._e41;
	m._e42 = c._e41 * n._e12 + c._e42 * n._e22 + c._e43 * n._e32 + c._e44 * n._e42;
	m._e43 = c._e41 * n._e13 + c._e42 * n._e23 + c._e43 * n._e33 + c._e44 * n._e43;
	m._e44 = c._e41 * n._e14 + c._e42 * n._e24 + c._e43 * n._e34 + c._e44 * n._e44;

	return m;
}

////////////////////////////////////////////////////////////////////////
// Matrix Functions Lab # 3
///////////////////////////////////////////////////////////////////////

// HELPER FUNCTION  *** NOT GRADED, ONLY SUGGESTED ***
// USE THIS FUNCTION TO FIND THE DETERMINANT OF A 3*3
// MATRIX. IT CAN BE USED IN THE MATRIX DETERMINANT
// AND MATRIX INVERSE FUNCTIONS BELOW
// 
// RETURN:	The determinant of a 3x3 matrix
float Matrix_Determinant3(float e_11, float e_12, float e_13,
						  float e_21, float e_22, float e_23,
						  float e_31, float e_32, float e_33)
{
	float result = (e_11 * e_22 * e_33 + e_21 * e_32 * e_13 + e_12 * e_23 * e_31) - (e_31 * e_22 * e_13 + e_32 * e_23 * e_11 + e_21 * e_12 * e_33);

	return result;
}

// Get the determinant of a matrix
//
// IN:		m		The ONE!
//
// RETURN:	It's deterinant
float Matrix_Determinant(TMATRIX m)
{
	// TODO LAB 3: Replace with your implementation.

	float result = m._e11 * Matrix_Determinant3(m._e22, m._e23, m._e24, m._e32, m._e33, m._e34, m._e42, m._e43, m._e44);
	result = result - (m._e12 * Matrix_Determinant3(m._e21, m._e23, m._e24, m._e31, m._e33, m._e34, m._e41, m._e43, m._e44));
	result = result + (m._e13 * Matrix_Determinant3(m._e21, m._e22, m._e24, m._e31, m._e32, m._e34, m._e41, m._e42, m._e44));
	result = result - (m._e14 * Matrix_Determinant3(m._e21, m._e22, m._e23, m._e31, m._e32, m._e33, m._e41, m._e42, m._e43));

	return result;
}

// Get the inverse of a matrix
//
// IN:		m		The matrix to inverse
//
// RETURN:	The Inverse of [m]
//
// NOTE: Returns the matrix itself if m is not invertable.
TMATRIX Matrix_Inverse(TMATRIX m)
{
	// TODO LAB 3: Replace with your implementation.
	if (Matrix_Determinant(m) != 0){

		TMATRIX c = m;
		float det = 1 / Matrix_Determinant(m);

		m._e11 = Matrix_Determinant3(c._e22, c._e23, c._e24, c._e32, c._e33, c._e34, c._e42, c._e43, c._e44) * det;
		m._e12 = - Matrix_Determinant3(c._e21, c._e23, c._e24, c._e31, c._e33, c._e34, c._e41, c._e43, c._e44) * det;
		m._e13 = Matrix_Determinant3(c._e21, c._e22, c._e24, c._e31, c._e32, c._e34, c._e41, c._e42, c._e44) * det;
		m._e14 = - Matrix_Determinant3(c._e21, c._e22, c._e23, c._e31, c._e32, c._e33, c._e41, c._e42, c._e43) * det;

		m._e21 = - Matrix_Determinant3(c._e12, c._e13, c._e14, c._e32, c._e33, c._e34, c._e42, c._e43, c._e44) * det;
		m._e22 = Matrix_Determinant3(c._e11, c._e13, c._e14, c._e31, c._e33, c._e34, c._e41, c._e43, c._e44) * det;
		m._e23 = - Matrix_Determinant3(c._e11, c._e12, c._e14, c._e31, c._e32, c._e34, c._e41, c._e42, c._e44) * det;
		m._e24 = Matrix_Determinant3(c._e11, c._e12, c._e13, c._e31, c._e32, c._e33, c._e41, c._e42, c._e43) * det;

		m._e31 = Matrix_Determinant3(c._e12, c._e13, c._e14, c._e22, c._e23, c._e24, c._e42, c._e43, c._e44) * det;
		m._e32 = - Matrix_Determinant3(c._e11, c._e13, c._e14, c._e21, c._e23, c._e24, c._e41, c._e43, c._e44) * det;
		m._e33 = Matrix_Determinant3(c._e11, c._e12, c._e14, c._e21, c._e22, c._e24, c._e41, c._e42, c._e44) * det;
		m._e34 = - Matrix_Determinant3(c._e11, c._e12, c._e13, c._e21, c._e22, c._e23, c._e41, c._e42, c._e43) * det;

		m._e41 = - Matrix_Determinant3(c._e12, c._e13, c._e14, c._e22, c._e23, c._e24, c._e32, c._e33, c._e34) * det;
		m._e42 = Matrix_Determinant3(c._e11, c._e13, c._e14, c._e21, c._e23, c._e24, c._e31, c._e33, c._e34) * det;
		m._e43 = - Matrix_Determinant3(c._e11, c._e12, c._e14, c._e21, c._e22, c._e24, c._e31, c._e32, c._e34) * det;
		m._e44 = Matrix_Determinant3(c._e11, c._e12, c._e13, c._e21, c._e22, c._e23, c._e31, c._e32, c._e33) * det;

		m = Matrix_Transpose(m);

	}

	return m;
}

