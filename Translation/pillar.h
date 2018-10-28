#ifndef _PILLAR_H
#define _PILLAR_H

#include<d3dx9.h>
#include"commonFile.h"

class Pillar
{
private:
	 LPD3DXMESH pillarMesh;
	 
public:

	Pillar();
	~Pillar();

	void CreatePillar(LPDIRECT3DDEVICE9 theDevice,float x,float y, float z, float angle);
	void Render(LPDIRECT3DDEVICE9 theDevice);
    D3DXMATRIX saveWorldMatrix;
	D3DXMATRIX orientation;
	D3DXMATRIX worldMatrix;
	

};

#endif
