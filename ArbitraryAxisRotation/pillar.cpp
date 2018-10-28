
#include"pillar.h"

Pillar::Pillar()
{
	pillarMesh=NULL;

}

Pillar::~Pillar()
{
	SAFE_RELEASE(pillarMesh);
	
}

void Pillar::CreatePillar(LPDIRECT3DDEVICE9 theDevice,float x,float y, float z,float angle)
{
	D3DXMATRIX scale; // scaling matrix
	D3DXMATRIX translate;// translation matrix
	// create the cylinder to build the pillar
	D3DXCreateCylinder(theDevice,0.5f,0.5f,5,20,20,&pillarMesh,0);
	// create the pillar orientation matrix
	D3DXMatrixRotationX(&orientation,angle);
	// scale the pillar by 10
	D3DXMatrixScaling(&scale,10,10,10);
	// position the pillar at (x,y,z) using the translation matrix
	D3DXMatrixTranslation(&translate,x,y,z);
	// scale then translate into worldMatrix ; worldMatrix=scaling*translation
	worldMatrix=scale*translate;
	// now rotate , scale and finally translate
	worldMatrix=orientation*worldMatrix;
}

void Pillar::Render(LPDIRECT3DDEVICE9 theDevice)
{
	theDevice->GetTransform(D3DTS_WORLD, &saveWorldMatrix);
	theDevice->SetTransform(D3DTS_WORLD, &worldMatrix);
	theDevice->SetMaterial(&BLUEMATERIAL);
	pillarMesh->DrawSubset(0);
    theDevice->SetTransform(D3DTS_WORLD,&saveWorldMatrix);
}
