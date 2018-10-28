

#include <d3dx9.h>
#include <iostream>
using namespace std;


void Menu()
{   
	cout<<"==================DirectX Math Library==================="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"=            Linear Algebra: Matrices Algebra           ="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"=            This is a small program to get you         ="<<endl;
	cout<<"=            used to DirectX Matrix Math Library        ="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"========================================================="<<endl;
    cout<<"\n\n";
}


// Overload the  "<<" operators so that we can use cout to 
// output D3DXVECTOR3 and D3DXMATRIX objects.

ostream& operator<<(ostream& os, D3DXVECTOR4& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ","<<v.w<<")";
	return os;
}

ostream& operator<<(ostream& os, D3DXMATRIX& m)
{
	for(int i = 0; i <4; ++i)
	{
		for(int j = 0; j <4; ++j)
			os <<"\t"<< m(i, j) << "  ";
		os << endl;
	}
	return os;
}


int main()
{
	Menu();

	D3DXMATRIX I;
	// create the identity matrix I using D3DXMatrixIdentity()

	D3DXMatrixIdentity(&I);

	// define 2 matrices A and B  of type D3DXMATRIX
     D3DXMATRIX A, B, C,D,M,S;
	// create a matrix A with entry values: 1,2,3,
	//                                      2,0,5
	//										1,1,3
	
      A=D3DXMATRIX(1.0F,2.0F,3.0F,0.0F,
		           2.0F,0.0F,5.0F,0.0F,
				   1.0F,1.0F,3.0F,0.0F,
				   0.0F,0.0F,0.0F,1.0F);


	// create a matrix B with entry values: 2,3,1,
	//                                      5,1,2
	//										1,0,-3

	  B = D3DXMATRIX(2.0F, 3.0F, 1.0F, 0.0F,
					5.0F, 1.0F, 2.0F, 0.0F,
					1.0F, 0.0F, -3.0F, 0.0F,
					0.0F, 0.0F, 0.0F, 1.0F);
    


	// add A and B ; S=A+B;

	  S = A + B;


	// Subtract A and B : D=A-B

	  D = A - B;

	 // Multiply A and B: M=A*B

	  D3DXMatrixMultiply(&M, &A, &B);

	 D3DXMATRIX transpose_Of_A;
	// Find the transpose of A that is transpose

	 D3DXMatrixTranspose(&transpose_Of_A, &A);

     FLOAT det;
	// find the determinant of A that is det
	 det = D3DXMatrixDeterminant(&A);

	 D3DXMATRIX InvA;
	 // Compute the inverse of A that is InvA
	 D3DXMatrixInverse(&InvA, &det, &A);

	 D3DXVECTOR4  V,P;
	 V = D3DXVECTOR4(1, 2, 3, 1);
	 // Compute the image of the vector V(1,2,3,1) by the matrix A, that  is P=A*V
	 D3DXVec4Transform(&P, &V, &transpose_Of_A);
	/* P.x = (A._11 * V.x) + (A._12 * V.y) + (A._13 * V.z) + (A._14 * V.w);
	 P.y = (A._21 * V.x) + (A._22 * V.y) + (A._23 * V.z) + (A._24 * V.w);
	 P.z = (A._31 * V.x) + (A._32 * V.y) + (A._33 * V.z) + (A._34 * V.w);
	 P.w = (A._41 * V.x) + (A._42 * V.y) + (A._43 * V.z) + (A._44 * V.w); */


	cout << "I = "               << endl << I << endl;
	cout << "A = "               << endl << A << endl;
	cout << "B = "               << endl << B << endl;
	cout << "A+B = "             << endl << S << endl;
	cout << "A-B = "             << endl << D << endl;
	cout << "A*B = "             << endl << M << endl;
	cout << "Transpose(A)= " << endl << transpose_Of_A << endl;
	cout << "Determinant of A  :"<< endl <<det <<endl;
	cout << "Inverse of A  is "  << endl << InvA << endl;
    cout << "P=A*V	  is       " << P <<endl;

	cout << "\n\nPress Enter to exit";
	getchar();
	return 0;
}
