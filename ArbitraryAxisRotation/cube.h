#ifndef _CUBE_H
#define _CUBE_H

#include<d3dx9.h>

struct CubeVertex
{
  D3DXVECTOR3 position; 
  D3DXVECTOR3 normal;
  D3DXVECTOR2 texCoord;// text coordinates
};

DWORD const FVF=D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1;

class Cube
{
private:
	    LPD3DXMESH cubeMesh;
		LPDIRECT3DTEXTURE9 cubeTexture;
		LPDIRECT3DVERTEXBUFFER9 buffer;
public:
	Cube();
	~Cube();
	void CreateCube(LPDIRECT3DDEVICE9 theDevice,LPCSTR textureFilename);
	void Update(float dt);
	void Render(LPDIRECT3DDEVICE9 theDevice);

	D3DXMATRIX worldMatrix,saveWorldMatrix;
	D3DXVECTOR3 position;
	D3DXVECTOR3 velocity;
};


#endif

