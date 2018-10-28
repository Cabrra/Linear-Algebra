
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

  cubeMesh->CloneMeshFVF( NULL,FVF,theDevice,&cubeMesh);
  int numberOfVertices=cubeMesh->GetNumVertices()/4;
  cubeMesh->GetVertexBuffer(&buffer);
  CubeVertex* vertex=NULL;

  buffer->Lock(0,0,(void**)&vertex,0);
  for(DWORD i=0;i<numberOfVertices;i++)
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
	D3DXMATRIX translate; // box translation matrix
    // update the cube position:  new Position=old Position + velocity*dt
	position = position + velocity * dt;
	// create the translation matrix that locate the box in world space
    //  by calling D3DXMatrixTranslation(D3DXMATRIX *M,float x,..y,..z)
	D3DXMatrixTranslation(&worldMatrix, position.x, position.y, position.z);
	// set the world matrix equale to the the translation matrix (translate)

}
    