
#include"Game.h"
//#include"Game3DModel.h"

 static cGame* game;

 Planes ground;
 Cube   box1, box2;
 Pillar pillar1,pillar2,pillar3 ,pillar4, pillar5;






cGame::cGame():cGameWindows()
{
   
 
}




cGame::~cGame()
{
	delete game ;
}



bool SetupMatrices()
{
   
	D3DXVECTOR3 position(0.0f,0.0f,-100.0f);
	D3DXVECTOR3 target(0.0f,0.0f,0.0f);
	D3DXVECTOR3 up(0.0f,1.0f,0.0f);
	D3DXMatrixLookAtLH(&game->viewMatrix,&position,&target,&up);
	Device->SetTransform(D3DTS_VIEW,&game->viewMatrix);
	D3DXMatrixPerspectiveFovLH(&game->projectionMatrix,D3DX_PI/2.0f ,(float)WIDTH /(float)HEIGHT ,1.0f,1000.0f);
	Device->SetTransform(D3DTS_PROJECTION,&game->projectionMatrix);
	return true;
}



bool cGame::InitializeGame()
{
    // Iniatialize lights
	InitializeLight();
	// Initialize world and view  matrices
	SetupMatrices();
   
	 // set the ground position at the origin O(0,0,0)
	ground.position=D3DXVECTOR3(0.0F,0.0F,0.0F);
	// create the ground by calling CreatePlane(theDevice,textureFilename);
	// theDevice is Device and textureFilename is "desert.bmp"
	ground.CreatePlane(Device,"desert.bmp");
	 // create box 1  by calling CreateCube(..,..), with texture filename being crate.jpg
	box1.CreateCube(Device, "crate.jpg");
	// set box 1  position at (-30,20,-30)
	box1.position = D3DXVECTOR3(-30.0f, 20.0f, -30.0f);
	// set box 1 constant velocity to (20,10,10) m/s
	box1.velocity = D3DXVECTOR3(20.0f, 10.0f, 10.0f);
	// create box 2 , with texture filename being crate.jpg
	box2.CreateCube(Device, "crate.jpg");
	// set box 2  position at (10,5,-15)
	box2.position = D3DXVECTOR3(10.0f, 5.0f, -15.0f);
	// set box 2 constant velocity to (0,5,0) m/s
	box2.velocity = D3DXVECTOR3(0.0f, 5.0f, 0.0f);
	// create  pillar 1 with  position (-5,0,-1) and  orientation of 90 degree
	pillar1.CreatePillar(Device, -5, 0, -1, D3DX_PI / 2);
	// create  pillar 2 with position at (14,0,5) and with an orientation of 90 degree
	pillar2.CreatePillar(Device, 14, 0, 5, D3DX_PI / 2);
	// create  pillar with position at (-30,0,25) and with an orientation of 180 degree
	pillar3.CreatePillar(Device, -30, 0, 25, D3DX_PI);
	// create  pillar with position at (-75,0,-30) and with an orientation of -45 degree 
	pillar4.CreatePillar(Device, -75, 0, -30, -D3DX_PI / 4);
	// create  pillar with position at (25,0,-25) and with an orientation of 90 degree
	pillar5.CreatePillar(Device, 25, 0, -25, D3DX_PI / 2);

	return true;
}



bool cGame::ShutDownD3D()
{
		
	if(Device!=NULL)
	{
		Device->Release();
		Device=NULL;
	    
	}
	if(D3D!=NULL)
	{
		D3D->Release();
        D3D=NULL;
	}

	
		return true;
}

//end of shutdownD3D()



void cGame::UpdateGame(float dt)
{
    // update box 1 by calling update(dt)
	box1.Update(dt);
	//update box 2 by calling update(dt)
	box2.Update(dt);
}



bool RenderFrame()
{
 	// render ground
	ground.Render(Device);

	// render box1  and box 2 by calling Render(theDevice)
	box1.Render(Device);
	box2.Render(Device);
	//render the 5 pillars (1 to 5)by calling Render(theDevice)
	pillar1.Render(Device);
	pillar2.Render(Device);
	pillar3.Render(Device);
	pillar4.Render(Device);
	pillar5.Render(Device);

	return true;
}




bool cGame::RenderGame()
{
     bool IsRendered=true;
     

	// Clear the backbuffer to a black color
	 
         Device->Clear(0,0,D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(225,225,225) ,1.0f,0);
        // Begin the scene
	   if(SUCCEEDED(Device->BeginScene()))
        { 
           	      
			//rendering goes here
			RenderFrame();

		    // End the scene
            Device->EndScene();

		}

    	else 
	  {
	    	MessageBox(0," BeginScene()-Failed"," Rendering Error" ,MB_OK) ;
			IsRendered=false;
	  }
	
    // Present the backbuffer contents to the display
	  
       Device->Present(0,0,0,0);
	return IsRendered;
}



void cGame::Cleanup()
{
   
	
}



bool InitializeLight()
{
	D3DLIGHT9 light;
	ZeroMemory(&light,sizeof(D3DLIGHT9));
	light.Type=D3DLIGHT_DIRECTIONAL;
	D3DXVECTOR3 lightDirection;
	lightDirection=D3DXVECTOR3(0.0f,-2.0f,1.0f);
	D3DXVec3Normalize( (D3DXVECTOR3*)&light.Direction,&lightDirection);

	//set the diffuse color
	light.Diffuse.r=1.0f;
	light.Diffuse.g=1.0f;
	light.Diffuse.b=1.0f;
	light.Diffuse.a=1.0f;
	Device->SetLight(0,&light);
	Device->LightEnable(0,true);
	Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE,D3DMCS_MATERIAL);
	// Turn on  D3D lighting.
    Device->SetRenderState(D3DRS_LIGHTING,true);
	return true;
}





INT WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInst,LPSTR lpCmdLine, int nShowCmd)
{
  
 game=new cGame();
  /* Create window */
 game->CreateGameWindows(hInstance," Linear Algebra Tutorial 1  : Translations simulation");
 
 /* Setup Direct3D */
 game->InitializeD3D();

 // initialize game
 game->InitializeGame();

 /* Enter message loop */
 game->Run();
 
 /* Shutdown Direct3D */

 game->ShutDownD3D();
 
  


 return 0;
}






HRESULT cGame::InitializeD3D()
{
     HRESULT hr=0; // handle to result
	
	// create the IDirect3D object
	if(NULL==(D3D=Direct3DCreate9(D3D_SDK_VERSION)))
	{
  
      MessageBox(NULL,"DIRECT3DCREATE9-FAILED","ERROR",0);	
	  return E_FAIL;
	}
  

  // check the hardware vertex processing capabillty

  D3DCAPS9 caps;
  D3DDEVTYPE deviceType=D3DDEVTYPE_HAL;
  D3D->GetDeviceCaps(D3DADAPTER_DEFAULT,deviceType,&caps);
  
  int vp=0; //vertexProcessing
  
  if(caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)  
  {
	  vp=D3DCREATE_HARDWARE_VERTEXPROCESSING;
  }
  else
  {
	  vp=D3DCREATE_SOFTWARE_VERTEXPROCESSING;
  }

  // create Present Parameter and fill it out.
  D3DPRESENT_PARAMETERS d3dpp;
  ZeroMemory(&d3dpp,sizeof(d3dpp));
  
  d3dpp.BackBufferWidth              =WIDTH;
  d3dpp.BackBufferHeight             =HEIGHT;
  d3dpp.BackBufferFormat             =D3DFMT_A8R8G8B8;
  d3dpp.BackBufferCount              =1;
  d3dpp.AutoDepthStencilFormat       =D3DFMT_D16; // or use D3DFMT_D24S8;
  d3dpp.EnableAutoDepthStencil       =true;
  d3dpp.Flags                        =0;
  d3dpp.FullScreen_RefreshRateInHz   =D3DPRESENT_RATE_DEFAULT;
  d3dpp.hDeviceWindow                =hwnd;
  d3dpp.MultiSampleQuality           =0;
  d3dpp.MultiSampleType              =D3DMULTISAMPLE_NONE;
  d3dpp.PresentationInterval         =D3DPRESENT_INTERVAL_IMMEDIATE;
  d3dpp.SwapEffect                   =D3DSWAPEFFECT_DISCARD;
  d3dpp.Windowed                     =true;
  

  // now create the device
  hr=D3D->CreateDevice(D3DADAPTER_DEFAULT,deviceType,hwnd,vp,&d3dpp,&Device);
  if( FAILED (hr))
  {
	  	 D3D->Release();
		 MessageBox(NULL,"CreateDevice()-Failed","ERROR",NULL);
		 return E_FAIL;
	
  }
  
   if(hr==S_OK)
	   {
	      // Turn off culling, so we see the front and back of the 
          //object
        Device->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);

    }

  return hr;
}

//////////////////////////////////////////////////end of initializeD3D()////////////////////////////////////////
