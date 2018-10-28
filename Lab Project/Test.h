// Test.h -- Produces a report testing every core function.

// NOTE: Do not modify.

#ifndef _TESTSUITE_H_
#define _TESTSUITE_H_

// Operator overloads.

inline std::ostream & operator <<(std::ostream &left, const TVECTOR &right)
{
	left << right.x << " " << right.y << " " << right.z << " " << right.w;
	return left;
}

inline std::ostream & operator <<(std::ostream &left, const TMATRIX &right)
{
	// Row-major output.
	left << right._e11 << " " << right._e12 << " " << right._e13 << " " << right._e14 << " ";
	left << right._e21 << " " << right._e22 << " " << right._e23 << " " << right._e24 << " ";
	left << right._e31 << " " << right._e32 << " " << right._e33 << " " << right._e34 << " ";
	left << right._e41 << " " << right._e42 << " " << right._e43 << " " << right._e44;
	return left;
}

// Macros.

#define TEST0(r,f)														\
	{																	\
		r z = f();														\
		std::cout << #f << " ( ) = " << #r << " " << z << std::endl;	\
	}

#define TEST1(r,f,t1,v1)												\
	{																	\
		t1 a = v1; r z = f(a);											\
		std::cout << #f << " ( " << #t1 << " " << a << " ) = " << #r	\
			<< " " << z << std::endl;									\
	}

#define TEST2(r,f,t1,v1,t2,v2)											\
	{																	\
		t1 a = v1; t2 b = v2; r z = f(a,b);								\
		std::cout << #f << " ( " << #t1 << " " << a << " " << #t2		\
			<< " " << b << " ) = " << #r << " " << z << std::endl;		\
	}

#define TEST3(r,f,t1,v1,t2,v2,t3,v3)									\
	{																	\
		t1 a = v1; t2 b = v2; t3 c = v3; r z = f(a,b,c);				\
		std::cout << #f << " ( " << #t1 << " " << a << " " << #t2		\
			<< " " << b << " " << #t3 << " " << c << " ) = " << #r		\
			<< " " << z << std::endl;									\
	}

#define TEST4(r,f,t1,v1,t2,v2,t3,v3,t4,v4)								\
	{																	\
		t1 a = v1; t2 b = v2; t3 c = v3; t4 d = v4; r z = f(a,b,c,d);	\
		std::cout << #f << " ( " << #t1 << " " << a << " " << #t2		\
			<< " " << b << " " << #t3 << " " << c << " " << #t4 << " "	\
			<< d << " ) = " << #r << " " << z << std::endl;				\
	}

#define RB()      (RandomBoolean())
#define RF(n,x,p) (RandomFloat  (n,x,p))
#define RI(n,x)   (RandomInteger(n,x))
#define RM(n,x,p) (RandomMatrix (n,x,p))
#define RN(n,x,p) (RandomNormal (n,x,p))
#define RV(n,x,p) (RandomVector (n,x,p))

#define B bool
#define F float
#define I int
#define M TMATRIX
#define V TVECTOR

// Inlines.

inline bool RandomBoolean() { return ((rand() << 1) / RAND_MAX) != 0; }
inline float RandomFloat(float min, float max, int places)
{
	float s = (float)pow((float)10, (float)places);
	return (float)floor(s * (min + (((float)rand() * (max - min)) / (float)RAND_MAX))) / s;
}
inline int RandomInteger(int min, int max)
{
	return min + ((rand() * (max - min)) / RAND_MAX);
}
inline TMATRIX RandomMatrix(float min, float max, int places)
{
	TMATRIX out;
	for (unsigned i = 0; i < 16; ++i)
		out.e[i] = RandomFloat(min, max, places);
	return out;
}
inline TVECTOR RandomNormal(float min, float max, int places)
{
	TVECTOR out;
	for (unsigned i = 0; i < 3; ++i)
		out.e[i] = RandomFloat(min, max, places);
	out.w = 0;
	return out;
}
inline TVECTOR RandomVector(float min, float max, int places)
{
	TVECTOR out;
	for (unsigned i = 0; i < 4; ++i)
		out.e[i] = RandomFloat(min, max, places);
	return out;
}

#endif /* _TESTSUITE_H_ */