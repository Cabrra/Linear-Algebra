// Test.cpp -- Produces a report testing every core function.

// NOTE: Do not modify.

// Includes.

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "EngineMath.h"

#include "Test.h"


// SWITCH TO PICK WHICH FUNCTIONS TO CHECK
enum { NOLAB, ALLLABS, LAB1, LAB2, LAB3 };
static const int Switch = ALLLABS; 


// Methods.

int main(int argc, char **argv)
{
	// Seed, from command-line if able.
	
	unsigned seed = 3141;
	
	if (argc >= 2)
		seed = (unsigned)atoi(argv[1]);

	srand(seed);
	
	std::cout << "Seed ( ) = I " << seed << std::endl;
	std::cout << std::endl;
	
	// Tests.
	
	std::cout << std::setprecision(8);


	if (Switch == LAB1 || Switch == ALLLABS)
	{   // Begin LAB1
		TVECTOR _a = RV(-4, 4, 0), _b = _a, _c = _a;
		_b.e[rand() % 4] += (EPSILON * 2);
		_c.e[rand() % 4] += (EPSILON / 2);
		TEST2(B, Vector_IsEqual,            V, _a          , V, _a                           ); // Exactly equal.
		TEST2(B, Vector_IsEqual,            V, _a          , V, _b                           ); // Close but different.
		TEST2(B, Vector_IsEqual,            V, _a          , V, _c                           ); // Close and equal.
		TEST2(V, Vector_Add,                V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Vector_Add,                V, RN(-9, 9, 0), V, RN(-9, 9, 0)                 );
		TEST2(V, Vector_Sub,                V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Vector_Sub,                V, RN(-9, 9, 0), V, RN(-9, 9, 0)                 );
		TEST2(V, Vector_Scalar_Multiply,    V, RV(-9, 9, 0), F, RF(-9, 9, 0)                 );
		TEST2(V, Vector_Scalar_Multiply,    V, RV(-9, 9, 0), F, RF(-9, 9, 0)                 );
		TEST2(V, Vector_Scalar_Multiply,    V, RV(-9, 9, 0), F, RF(-9, 9, 0)                 );
		TEST1(V, Vector_Negate,             V, RV(-9, 9, 0)                                  );
		TEST1(V, Vector_Negate,             V, RV(-9, 9, 0)                                  );
		TEST2(F, Vector_Dot,                V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(F, Vector_Dot,                V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Vector_Cross,              V, RN(-9, 9, 0), V, RN(-9, 9, 0)                 );
		TEST2(V, Vector_Cross,              V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 ); // Non-zero W component.
		TEST1(F, Vector_LengthSq,           V, RV(-9, 9, 0)                                  );
		TEST1(F, Vector_LengthSq,           V, RV(-9, 9, 0)                                  );
		TEST1(F, Vector_Length,             V, RV(-9, 9, 0)                                  );
		TEST1(F, Vector_Length,             V, RV(-9, 9, 0)                                  );
		TEST1(V, Vector_Normalize,          V, RV(-9, 9, 0)                                  );
		TEST1(V, Vector_Normalize,          V, RV(-9, 9, 0)                                  );
		TEST1(V, Vector_Normalize,          V, RV( 0, 0, 0)                                  ); // Zero-length vector.
		TEST1(V, Vector_Homogenise,         V, RV(-9, 9, 0)                                  );
		TEST1(V, Vector_Homogenise,         V, RN(-9, 9, 0)                                  ); // Zero W component.
		TEST2(V, Vector_Maximize,           V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Vector_Maximize,           V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Vector_Minimize,           V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Vector_Minimize,           V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Vector_Average,            V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Vector_Average,            V, RN(-9, 9, 0), V, RN(-9, 9, 0)                 );
		TEST2(V, Vector_Average,            V, RN(-9, 9, 0), V, RN(-9, 9, 0)                 );
		TEST2(F, Vector_AngleBetween,       V, RN(-9, 9, 0), V, RN(-9, 9, 0)                 );
		TEST2(F, Vector_AngleBetween,       V, RN( 0, 0, 0), V, RN(-9, 9, 0)                 ); // First zero-length vector
		TEST2(F, Vector_AngleBetween,       V, RN(-9, 9, 0), V, RN( 0, 0, 0)                 ); // Second zero-length vector
		TEST2(F, Vector_AngleBetween,       V, RN( 0, 0, 0), V, RN( 0, 0, 0)                 ); // Both zero-length vectors
		TEST2(F, Vector_AngleBetween,       V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 ); // Non-zero W component.
		TEST2(F, Vector_AngleBetween,       V, RV( 0, 0, 0), V, RV(-9, 9, 0)                 ); // Non-zero W component, first zero-length vector
		TEST2(F, Vector_AngleBetween,       V, RV(-9, 9, 0), V, RV( 0, 0, 0)                 ); // Non-zero W component, second zero-length vector
		TEST2(F, Vector_Component,          V, RN(-9, 9, 0), V, RN(-9, 9, 0)                 );
		TEST2(F, Vector_Component,          V, RN(-9, 9, 0), V, RN( 0, 0, 0)                 ); // Zero-length vector.
		TEST2(F, Vector_Component,          V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 ); // Non-zero W component.
		TEST2(F, Vector_Component,          V, RV(-9, 9, 0), V, RN( 0, 0, 0)                 ); // Non-zero W component, zero-length vector.
		TEST2(V, Vector_Project,            V, RN(-9, 9, 0), V, RN(-9, 9, 0)                 );
		TEST2(V, Vector_Project,            V, RN(-9, 9, 0), V, RN( 0, 0, 0)                 ); // Zero-length vector.
		TEST2(V, Vector_Project,            V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 ); // Non-zero W component.
		TEST2(V, Vector_Project,            V, RV(-9, 9, 0), V, RN( 0, 0, 0)                 ); // Non-zero W component, zero-length vector.
	}	// End LAB1																				// Test Notes...

		
	if (Switch == LAB2 || Switch == ALLLABS)
	{	// Begin LAB2
		TEST2(V, Vector_Reflect,            V, RN(-9, 9, 0), V, RN(-9, 9, 0)                 );
		TEST2(V, Vector_Reflect,            V, RN(-9, 9, 0), V, RN( 0, 0, 0)                 ); // Zero-length vector.
		TEST2(V, Vector_Reflect,            V, RV(-9, 9, 0), V, RV(-9, 9, 0)                 ); // Non-zero W component.
		TEST2(V, Vector_Reflect,            V, RV(-9, 9, 0), V, RN( 0, 0, 0)                 ); // Non-zero W component, zero-length vector.
		TEST2(V, Vector_Reflect,            V, RN(-9, 9, 0), V, gc_xAxis                     ); // Non-zero W component, zero-length vector.
		TEST0(M, Matrix_Zero                                                                 );
		TEST0(M, Matrix_Identity                                                             );
		TEST3(M, Matrix_Create_Translation, F, RF(-9, 9, 0), F, RF(-9, 9, 0), F, RF(-9, 9, 0));
		TEST3(M, Matrix_Create_Scale,       F, RF(-9, 9, 0), F, RF(-9, 9, 0), F, RF(-9, 9, 0));
		TEST3(M, Matrix_Create_Scale,       F, RF(-9, 9, 0), F, RF(-9, 9, 0), F, RF(-9, 9, 0));
		TEST1(M, Matrix_Create_Rotation_X,  F, RF(-6, 360, 4)                                  );
		TEST1(M, Matrix_Create_Rotation_X,  F, RF(-6, 360, 4)                                  );
		TEST1(M, Matrix_Create_Rotation_X,  F, RF(-6, 360, 4)                                  );
		TEST1(M, Matrix_Create_Rotation_Y,  F, RF(-6, 360, 4)                                  );
		TEST1(M, Matrix_Create_Rotation_Y,  F, RF(-6, 360, 4)                                  );
		TEST1(M, Matrix_Create_Rotation_Y,  F, RF(-6, 360, 4)                                  );
		TEST1(M, Matrix_Create_Rotation_Z,  F, RF(-6, 360, 4)                                  );
		TEST1(M, Matrix_Create_Rotation_Z,  F, RF(-6, 360, 4)                                  );
		TEST1(M, Matrix_Create_Rotation_Z,  F, RF(-6, 360, 4)                                  );
		TEST2(M, Matrix_Matrix_Add,         M, RM(-9, 9, 0), M, RM(-9, 9, 0)                 );
		TEST2(M, Matrix_Matrix_Add,         M, RM(-9, 9, 0), M, RM(-9, 9, 0)                 );
		TEST2(M, Matrix_Matrix_Sub,         M, RM(-9, 9, 0), M, RM(-9, 9, 0)                 );
		TEST2(M, Matrix_Matrix_Sub,         M, RM(-9, 9, 0), M, RM(-9, 9, 0)                 );
		TEST2(M, Matrix_Scalar_Multiply,    M, RM(-9, 9, 0), F, RF(-9, 9, 0)                 );
		TEST2(M, Matrix_Scalar_Multiply,    M, RM(-9, 9, 0), F, RF(-9, 9, 0)                 );
		TEST1(M, Matrix_Negate,             M, RM(-9, 9, 0)                                  );
		TEST1(M, Matrix_Negate,             M, RM(-9, 9, 0)                                  );
		TEST1(M, Matrix_Transpose,          M, RM(-9, 9, 0)                                  );
		TEST1(M, Matrix_Transpose,          M, RM(-9, 9, 0)                                  );
		TEST2(V, Matrix_Vector_Multiply,    M, RM(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Matrix_Vector_Multiply,    M, RM(-9, 9, 0), V, RV(-9, 9, 0)                 );
		TEST2(V, Vector_Matrix_Multiply,    V, RV(-9, 9, 0), M, RM(-9, 9, 0)                 );
		TEST2(V, Vector_Matrix_Multiply,    V, RV(-9, 9, 0), M, RM(-9, 9, 0)                 );
		TEST2(M, Matrix_Matrix_Multiply,    M, RM(-9, 9, 0), M, RM(-9, 9, 0)                 );
		TEST2(M, Matrix_Matrix_Multiply,    M, RM(-9, 9, 0), M, RM(-9, 9, 0)                 );
		TEST2(M, Matrix_Matrix_Multiply,    M, RM(-9, 9, 0), M, RM(-9, 9, 0)                 );
	} // End LAB2

	if (Switch == LAB3 || Switch == ALLLABS)
	{	// Begin LAB3
		TMATRIX _m = { 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6, 4, 5, 6, 7, };
		TEST1(F, Matrix_Determinant,        M, RM(-9, 9, 0)                                  );
		TEST1(F, Matrix_Determinant,        M, RM(-9, 9, 0)                                  );
		TEST1(F, Matrix_Determinant,        M, RM(-9, 9, 0)                                  );
		TEST1(F, Matrix_Determinant,        M, _m                                            ); // Singular matrix.
		TEST1(M, Matrix_Inverse,            M, RM(-9, 9, 0)                                  );
		TEST1(M, Matrix_Inverse,            M, RM(-9, 9, 0)                                  );
		TEST1(M, Matrix_Inverse,            M, RM(-9, 9, 0)                                  );
		TEST1(M, Matrix_Inverse,            M, _m                                            ); // Singular matrix.
	} // End LAB3

	
	// Finished.
	std::cout << std::endl;
	std::cout << "End" << std::endl;

	// BYE-BYE
	//std::cout << "\n\nPress Enter to exit";
	//getchar();
	return 0;
}