/**
* @file EngineMath.cpp
*
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
	if (!IsEqual(v.x, w.x))
		return false;
	if (!IsEqual(v.y, w.y))
		return false;
	if (!IsEqual(v.z, w.z))
		return false;
	if (!IsEqual(v.w, w.w))
		return false;
	return true;
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
	// TODO LAB 1: Replace with your implementation.
	v.x += w.x;
	v.y += w.y;
	v.z += w.z;
	v.w += w.w;

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
	//TVECTOR temp;
	//for (int i = 0; i < 4; ++i)
	//{
	//	temp.e[i] = v.e[i] * s;
	//}

	//return temp;

	v.x *= s;
	v.y *= s;
	v.z *= s;
	v.w *= s;

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
	
	v.x *= -1;
	v.y *= -1;
	v.z *= -1;
	v.w *= -1;

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
	float dotProduct = 0.0F;

	dotProduct += v.x * w.x;
	dotProduct += v.y * w.y;
	dotProduct += v.z * w.z;
	dotProduct += v.w * w.w;

	return  dotProduct;
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
	TVECTOR result;
	result.x = v.y * w.z - v.z * w.y;
	result.y = v.z * w.x - v.x * w.z;
	result.z = v.x * w.y - v.y * w.x;
	result.w = 0;
	return result;
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
	float squared = (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w);
	return squared;
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

	return sqrtf(Vector_LengthSq(v));
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

	TVECTOR temp;
	// TODO LAB 1: Replace with your implementation.
	if (IsZero(Vector_Length(v)))
	{
		v.x = 0;
		v.y = 0;
		v.z = 0;

		return v;
	}

	temp.x = v.x / Vector_Length(v);
	temp.y = v.y / Vector_Length(v);
	temp.z = v.z / Vector_Length(v);
	temp.w = v.w / Vector_Length(v);
		
	return temp;
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
	//TVECTOR temp;
	if (IsZero(v.w))
	{
		v.x = 0;
		v.y = 0;
		v.z = 0;
		v.w = 0;

		return v;
	}

	v.x = v.x / v.w;
	v.y = v.y / v.w;
	v.z = v.z / v.w;
	v.w = v.w / v.w;

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
	TVECTOR temp;
	temp.w = Max(v.w, w.w);
	temp.x = Max(v.x, w.x);
	temp.y = Max(v.y, w.y);
	temp.z = Max(v.z, w.z);
	return temp;
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
	TVECTOR temp;
	temp.w = Min(v.w, w.w);
	temp.x = Min(v.x, w.x);
	temp.y = Min(v.y, w.y);
	temp.z = Min(v.z, w.z);
	return temp;
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
	float radians;
	float addV = v.x + v.y + v.z;
	float addW = w.x + w.y + w.z;
	if (IsZero(addV) || IsZero(addW))
	{
		return 0;
	}

	radians = acosf(Vector_Dot(v, w) / (Vector_Length(v) * Vector_Length(w)));
	
	return Radians_To_Degrees(radians);
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
	// TODO LAB 1: Replace with your implementation.
	float addW = w.x + w.y + w.z;
	float vec_Comp;

	if (IsZero(addW))
		return 0;

	vec_Comp = Vector_Dot(v, Vector_Normalize(w));
	
	return vec_Comp;
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
	TVECTOR temp;
	float addW = w.x + w.y + w.z + v.w;
	float addV = v.x + v.y + v.z + v.w;

	if (IsZero(addW) || IsZero(addV))
	{
		temp.x = 0;
		temp.y = 0;
		temp.z = 0;
		temp.w = 0;
		return temp;
	}

	temp.x = (Vector_Dot(v, w) / Vector_LengthSq(w)) * w.x;
	temp.y = (Vector_Dot(v, w) / Vector_LengthSq(w)) * w.y;
	temp.z = (Vector_Dot(v, w) / Vector_LengthSq(w)) * w.z;
	temp.w = (Vector_Dot(v, w) / Vector_LengthSq(w)) * w.w;

	return  temp;
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
	TVECTOR temp;

	float addW = w.x + w.y + w.z + w.w;

	if (IsZero(addW))
	{
		v.x *= -1;
		v.y *= -1;
		v.z *= -1;
		v.w *= -1;

		return v;
	}

	temp = Vector_Sub(v, Vector_Scalar_Multiply(Vector_Project(v, Vector_Normalize(w)), 2));

	temp.x *= -1;
	temp.y *= -1;
	temp.z *= -1;
	temp.w *= -1;

	return temp;
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
	TMATRIX m;
	m._e11 = 0;
	m._e12 = 0;
	m._e13 = 0;
	m._e14 = 0;
	m._e21 = 0;
	m._e22 = 0;
	m._e23 = 0;
	m._e24 = 0;
	m._e31 = 0;
	m._e32 = 0;
	m._e33 = 0;
	m._e34 = 0;
	m._e41 = 0;
	m._e42 = 0;
	m._e43 = 0;
	m._e44 = 0;

	return m;
}

// Get a [I] matrix
//
// RETURN: A 4x4 Identity matrix
TMATRIX Matrix_Identity(void)
{
	// TODO LAB 2: Replace with your implementation.
	TMATRIX m = {1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1};

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
	TMATRIX m = Matrix_Identity();
	m._e14 = x;
	m._e24 = y;
	m._e34 = z;
	m._e44 = 1;
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
	TMATRIX m = Matrix_Identity();
	m._e11 *= x;
	m._e22 *= y;
	m._e33 *= z;
	m._e44 *= 1;
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
	float theta = Degrees_To_Radians(Deg);
	TMATRIX m = Matrix_Identity();

	m._e11 = 1;
	m._e22 = cosf(theta);
	m._e23 = -1 * sinf(theta);
	m._e32 = sinf(theta);
	m._e33 = cosf(theta);
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
	float theta = Degrees_To_Radians(Deg);
	TMATRIX m = Matrix_Identity();

	m._e11 = cos(theta);
	m._e13 = sin(theta);
	m._e22 = 1;
	m._e31 = -1 * sin(theta);
	m._e33 = cos(theta);

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
	float theta = Degrees_To_Radians(Deg);
	TMATRIX m = Matrix_Identity();

	m._e11 = cos(theta);
	m._e12 = -1 * sin(theta);
	m._e21 = sin(theta);
	m._e22 = cos(theta);

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
	m._e11 += n._e11;
	m._e12 += n._e12;
	m._e13 += n._e13;
	m._e14 += n._e14;

	m._e21 += n._e21;
	m._e22 += n._e22;
	m._e23 += n._e23;
	m._e24 += n._e24;

	m._e31 += n._e31;
	m._e32 += n._e32;
	m._e33 += n._e33;
	m._e34 += n._e34;

	m._e41 += n._e41;
	m._e42 += n._e42;
	m._e43 += n._e43;
	m._e44 += n._e44;

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
	m._e11 -= n._e11;
	m._e12 -= n._e12;
	m._e13 -= n._e13;
	m._e14 -= n._e14;
		   
	m._e21 -= n._e21;
	m._e22 -= n._e22;
	m._e23 -= n._e23;
	m._e24 -= n._e24;
		   
	m._e31 -= n._e31;
	m._e32 -= n._e32;
	m._e33 -= n._e33;
	m._e34 -= n._e34;
		   
	m._e41 -= n._e41;
	m._e42 -= n._e42;
	m._e43 -= n._e43;
	m._e44 -= n._e44;

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

	m._e11 *= s;
	m._e12 *= s;
	m._e13 *= s;
	m._e14 *= s;
		   	  
	m._e21 *= s;
	m._e22 *= s;
	m._e23 *= s;
	m._e24 *= s;
		   	  
	m._e31 *= s;
	m._e32 *= s;
	m._e33 *= s;
	m._e34 *= s;
		   	  
	m._e41 *= s;
	m._e42 *= s;
	m._e43 *= s;
	m._e44 *= s;

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

	m._e11 *= -1;
	m._e12 *= -1;
	m._e13 *= -1;
	m._e14 *= -1;
			  
	m._e21 *= -1;
	m._e22 *= -1;
	m._e23 *= -1;
	m._e24 *= -1;
			  
	m._e31 *= -1;
	m._e32 *= -1;
	m._e33 *= -1;
	m._e34 *= -1;
			  
	m._e41 *= -1;
	m._e42 *= -1;
	m._e43 *= -1;
	m._e44 *= -1;

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

	TMATRIX temp = m;

	m._e11 = temp._e11;
	m._e12 = temp._e21;
	m._e13 = temp._e31;
	m._e14 = temp._e41;

	m._e21 = temp._e12;
	m._e22 = temp._e22;
	m._e23 = temp._e32;
	m._e24 = temp._e42;

	m._e31 = temp._e13;
	m._e32 = temp._e23;
	m._e33 = temp._e33;
	m._e34 = temp._e43;

	m._e41 = temp._e14;
	m._e42 = temp._e24;
	m._e43 = temp._e34;
	m._e44 = temp._e44;


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
	TVECTOR temp;
	temp.x = (m._e11 * v.x) + (m._e12 * v.y) + (m._e13 * v.z) + (m._e14 * v.w);
	temp.y = (m._e21 * v.x) + (m._e22 * v.y) + (m._e23 * v.z) + (m._e24 * v.w);
	temp.z = (m._e31 * v.x) + (m._e32 * v.y) + (m._e33 * v.z) + (m._e34 * v.w);
	temp.w = (m._e41 * v.x) + (m._e42 * v.y) + (m._e43 * v.z) + (m._e44 * v.w);

	return temp;
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

	TVECTOR temp;
	temp.x = (v.x * m._e11) + (v.y * m._e21) + (v.z * m._e31) + (v.w * m._e41);
	temp.y = (v.x * m._e12) + (v.y * m._e22) + (v.z * m._e32) + (v.w * m._e42);
	temp.z = (v.x * m._e13) + (v.y * m._e23) + (v.z * m._e33) + (v.w * m._e43);
	temp.w = (v.x * m._e14) + (v.y * m._e24) + (v.z * m._e34) + (v.w * m._e44);

	return temp;
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
	TMATRIX temp;

	temp._e11 = (m._e11 * n._e11) + (m._e12 * n._e21) + (m._e13 * n._e31) + (m._e14 * n._e41);
	temp._e12 = (m._e11 * n._e12) + (m._e12 * n._e22) + (m._e13 * n._e32) + (m._e14 * n._e42);
	temp._e13 = (m._e11 * n._e13) + (m._e12 * n._e23) + (m._e13 * n._e33) + (m._e14 * n._e43);
	temp._e14 = (m._e11 * n._e14) + (m._e12 * n._e24) + (m._e13 * n._e34) + (m._e14 * n._e44);

	temp._e21 = (m._e21 * n._e11) + (m._e22 * n._e21) + (m._e23 * n._e31) + (m._e24 * n._e41);
	temp._e22 = (m._e21 * n._e12) + (m._e22 * n._e22) + (m._e23 * n._e32) + (m._e24 * n._e42);
	temp._e23 = (m._e21 * n._e13) + (m._e22 * n._e23) + (m._e23 * n._e33) + (m._e24 * n._e43);
	temp._e24 = (m._e21 * n._e14) + (m._e22 * n._e24) + (m._e23 * n._e34) + (m._e24 * n._e44);

	temp._e31 = (m._e31 * n._e11) + (m._e32 * n._e21) + (m._e33 * n._e31) + (m._e34 * n._e41);
	temp._e32 = (m._e31 * n._e12) + (m._e32 * n._e22) + (m._e33 * n._e32) + (m._e34 * n._e42);
	temp._e33 = (m._e31 * n._e13) + (m._e32 * n._e23) + (m._e33 * n._e33) + (m._e34 * n._e43);
	temp._e34 = (m._e31 * n._e14) + (m._e32 * n._e24) + (m._e33 * n._e34) + (m._e34 * n._e44);

	temp._e41 = (m._e41 * n._e11) + (m._e42 * n._e21) + (m._e43 * n._e31) + (m._e44 * n._e41);
	temp._e42 = (m._e41 * n._e12) + (m._e42 * n._e22) + (m._e43 * n._e32) + (m._e44 * n._e42);
	temp._e43 = (m._e41 * n._e13) + (m._e42 * n._e23) + (m._e43 * n._e33) + (m._e44 * n._e43);
	temp._e44 = (m._e41 * n._e14) + (m._e42 * n._e24) + (m._e43 * n._e34) + (m._e44 * n._e44);


	return temp;
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
float Matrix_Determinant(float e_11,float e_12,float e_13,
						 float e_21,float e_22,float e_23,
						 float e_31,float e_32,float e_33)
{
	return 0;
}

// Get the determinant of a matrix
//
// IN:		m		The ONE!
//
// RETURN:	It's deterinant
float Matrix_Determinant(TMATRIX m)
{
	// TODO LAB 3: Replace with your implementation.
	return 0;
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
	return m;
}

