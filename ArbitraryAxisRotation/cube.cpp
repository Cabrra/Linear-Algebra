
#include"cube.h"
#include "commonFile.h"


Cube::Cube()
{
  cubeTexture=0;
  cubeMesh=0;
  buffer=0;
}

Cube::~Cube()
{
	SAFE_RELEASE(cubeTexture);
	SAFE_RELEASE(cubeMesh);
	SAFE_RELEASE(buffer);
}

void Cube::CreateCube(LPDIRECT3DDEVICE9 theDevice,LPCSTR textureFilename)
{
  // create the box
  D3DXCreateBox(theDevice,5.0f,5.0f,5.0f,&cubeMesh,0);
  //box texture
  D3DXCreateTextureFromFile(theDevice,textureFilename,&cubeTexture);

  cubeMesh->CloneMeshFVF(NULL,FVF,theDevice,&cubeMesh);
  int numberOfVertice=cubeMesh->GetNumVertices()/4;
  cubeMesh->GetVertexBuffer(&buffer);
  CubeVertex* vertex=NULL;
  buffer->Lock(0,0,(void**)&vertex,0);
  for(int i=0;i<numberOfVertice;i++)
  {
	  vertex[4*i].texCoord.x=0;
	  vertex[4*i].texCoord.y=0;

	  vertex[4*i+1].texCoord.x=1;
	  vertex[4*i+1].texCoord.y=0;

	  vertex[4*i+2].texCoord.x=1;
	  vertex[4*i+2].texCoord.y=1;

	  vertex[4*i+3].texCoord.x=0;
	  vertex[4*i+3].texCoord.y=1;
  }

  buffer->Unlock();

  // create the box texture state
	theDevice->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);
	theDevice->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);
	theDevice->SetSamplerState(0,D3DSAMP_MIPFILTER,D3DTEXF_POINT);
	
}

void Cube::Render(LPDIRECT3DDEVICE9 theDevice)
{
	// to render the box
    theDevice->GetTransform(D3DTS_WORLD, &saveWorldMatrix);
	theDevice->SetTransform(D3DTS_WORLD, &worldMatrix);
	theDevice->SetMaterial(&WHITEMATERIAL);
	theDevice->SetTexture(0,cubeTexture);
	cubeMesh->DrawSubset(0);
    theDevice->SetTransform(D3DTS_WORLD,&saveWorldMatrix);
}

void Cube::Update(float dt)
{
  // initial angle of rotation
  static float angle=0.0f;
  D3DXVECTOR3  v; // axis of rotation vector
  D3DXMATRIX orientation; // orientation(or rotation) matrix about the arbitray axis spanned by v
  D3DXMATRIX translate;   // translation matrix

  //TODO :
  // increment the angle of rotation by the time step dt
  angle = angle + dt;
  // if angle is greater or equal to 6.28(2PI=2*D3DX_PI) then reset it to 0 
  if (angle >= (2 * D3DX_PI))
	  angle = 0;
  // set the axis of rotation vector to  v=(5,3,-2)
  v = D3DXVECTOR3(5, 3, -2);
  // normalize the vector v by calling D3DXVec3Normalize(D3DXVECTOR3* a,D3DXVECTOR3* b)
  D3DXVec3Normalize(&v, &v);
  // create the rotation matrix of Theta degree(=angle) about v
  // by calling D3DXMatrixRotationAxis()
  D3DXMatrixRotationAxis(&orientation, &v, angle);
  // create the translation matrix  by calling D3DXMatrixTranslation()
  // this helps to set the box position in the world
  D3DXMatrixTranslation(&translate, position.x, position.y, position.z);
  // create the world matrix  by concatenating the matrices in the following order :
  // rotation about v, then translation 
  worldMatrix = orientation * translate;
}
  
