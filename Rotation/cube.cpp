
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
  D3DXCreateBox(theDevice,10.0f,10.0f,10.0f,&cubeMesh,0);
  //box texture
  D3DXCreateTextureFromFile(theDevice,textureFilename,&cubeTexture);
  cubeMesh->CloneMeshFVF( NULL,FVF,theDevice,&cubeMesh);
  int numberOfVertices=cubeMesh->GetNumVertices()/4;
  cubeMesh->GetVertexBuffer(&buffer);
  CubeVertex* vertex=NULL;

  buffer->Lock(0,0,(void**)&vertex,0);
  for(int i=0;i<numberOfVertices;i++)
  {
	  vertex[4*i+0].texCoord.x=0;
	  vertex[4*i+0].texCoord.y=0;

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
  //  create the matrices rotations about the X,Y and Z axis
  D3DXMATRIX rotationX; // 
  D3DXMATRIX rotationY;
  D3DXMATRIX rotationZ;
  D3DXMATRIX translate;// translation matrix

  // increment the angle of rotation by the time step dt
  angle = angle + dt;
  // if angle is greater or equal to 6.28(=2PI) then reset to 0 
  if (angle >= (2 * D3DX_PI))
	  angle = 0;
  // create the rotation matrix of Theta degree(=angle) about the Y-axis
  // by calling D3DXMatrixRotationY
  D3DXMatrixRotationY(&rotationY, angle);
  // create the rotation matrix of Theta degree(=angle) about the Z-axis
  // by calling D3DXMatrixRotationZ
  D3DXMatrixRotationZ(&rotationZ, angle);
  // create the rotation matrix of Theta degree(=angle) about the X-axis
  // by calling D3DXMatrixRotationX
  D3DXMatrixRotationX(&rotationX, angle);
  // update the cube position:  newPosition=oldPosition + velocity*dt
  position = position + velocity * dt;
  // create the translation matrix  by calling D3DXMatrixTranslation
  D3DXMatrixTranslation(&translate, position.x, position.y, position.z);
  // create the world matrix  by concatenating the matrices in the following order :
  // rotation about the z-axis,rotation about the y-axis,rotation about the x-axis
  // then a translation .

  worldMatrix = rotationX * rotationY * rotationZ * translate;
   
}
  
