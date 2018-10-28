

#include <d3dx9.h>
#include <iostream>
using namespace std;


void Menu()
{   
	cout<<"==================DirectX Math Library==================="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"=            Linear Algebra: Vectors Algebra            ="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"=            This is a small program to get you         ="<<endl;
	cout<<"=            used to DirectX Vector Math Library        ="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"=                                                       ="<<endl;
	cout<<"========================================================="<<endl;
    cout<<"\n\n";
}

// Overload the  "<<" operators so that we can use cout to 
// output D3DXVECTOR3 objects.

ostream& operator<<(ostream& os, D3DXVECTOR3& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}


int main()
{
	Menu();
	// Using constructor D3DXVECTOR3(FLOAT x, FLOAT y, FLOAT z), define a vector V1=(1,0,1);
       D3DXVECTOR3 V1;
       V1=D3DXVECTOR3(1,0,1);
	 // Using constructor D3DXVECTOR3(FLOAT x, FLOAT y, FLOAT z), define a vector of type D3DXVECTOR3, and set V2=(2,-1,5);
	 // this will be in ;code V2=D3DXVECTOR3(FLOAT x, FLOAT y, FLOAT z) where x=2,y=-1,z=5
        D3DXVECTOR3 V2; 
		V2 = D3DXVECTOR3(2, -1, 5);


	// Using constructor D3DXVECTOR3(CONST FLOAT *) to defione V3=(-2,1,-3); An array is used in this case.
	float x[3] = {-2.0f, 1.0f, -3.0f};
	D3DXVECTOR3 V3(x);
    
	// Using constructor, D3DXVECTOR3() {} to define the following vectors:
	D3DXVECTOR3 a, b, c, d, e;  

	// Vector addition: D3DXVECTOR3 operator +       : compute vector a by adding  V1 and V2

	a = V1 + V2;

	// Vector subtraction: D3DXVECTOR3 operator -    : compute vector b by subtracting  V1 and V2
	b = V1 - V2;

	// Scalar multiplication: D3DXVECTOR3 operator * : compute vector c by multiplying V1 by 10

	c = V1 * 10;

	//  compute the length or norm of  V1 , ||V1|| , using D3DXVec3Length()
	float length;
	length = D3DXVec3Length(&V1);

	//  compute the normalized vector d of V1 that d = u / ||u|| using D3DXVec3Normalize()

	D3DXVec3Normalize(&d , &V1);

	//  compute the dot product of  V1 and V2  that is  s = u dot v using D3DXVec3Dot()
	float s;
	s = D3DXVec3Dot(&V1, &V2);

	//  compute the cross product e of  V1 and V2  that is e = V1 x V2 using D3DXVec3Cross()

	D3DXVec3Cross(&e, &V1, &V2);


	cout << "The component of vector V1 are           = " << V1 << endl;
	cout << "The component of vector V2 are           = " << V2 << endl;
	cout << "The component of vector V3 are           = " << V3 << endl;
	cout << "The sum of u and v , a=V1+V2 , is        = " << a << endl;
	cout << "The difference of V1 and V2,b=V1-V2 , is = " << b << endl;
	cout << "The scalar multiplication of V1 by 10 is = " << c << endl;
	cout << "The normalize vector of V1 is            = " << d << endl;
	cout << "The cross product of V1 and V2,V1xV2,is  = " << e << endl;
	cout << "The length or norm of V1 is ||V1||       = " << length << endl;
	cout << "V1 dot V2  is                            = " << s << endl;
    cout<<"\n\nPress Enter to exit";
	getchar();

	return 0;
}