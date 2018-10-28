
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
  static float angle=0.0f;
  float scalingFactor; // scaling factor
  D3DXMATRIX scale; // scaling matrix 
  D3DXMATRIX translate;   // translation matrix
  // create an alternate scaling factor
  scalingFactor = (3 + cos(angle)) / (1 + cos(sin(angle)));

  // increment the angle of rotation by the time step dt
  angle = angle + dt;
  // if angle is greater or equal to 6.28(2PI) then reset to 0 
  if (angle >= (2 * D3DX_PI))
	  angle = 0;
  // create the scaling matrix  by calling 
  //D3DXMatrixScaling(D3XDMATRIX* M,float factor,..factor,..factor) factor is scalingFactor
  D3DXMatrixScaling(&scale, scalingFactor, scalingFactor, scalingFactor);
  // create the translation matrix  by calling D3DXMatrixTranslation(D3DXMATRIX* M,float x,..y,..z)
  // this helps to set the box position in the world
  D3DXMatrixTranslation(&translate, position.x, position.y, position.z);
  // create the world matrix  by concatenating the matrices in the following order :
  // scale, then translation(written from left to the right) 
  worldMatrix = scale * translate;
}
  
