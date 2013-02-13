// alibrocket.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "alibrocket.h"

float MySystemInterface::GetElapsedTime()
{
	diag("\nGetElapsedTime");
	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);
	diag("-end");

	return (float)((counter.QuadPart - time_startup.QuadPart) * time_frequency);
}

void MySystemInterface::Initialize()
{
	LARGE_INTEGER time_ticks_per_second;
	QueryPerformanceFrequency(&time_ticks_per_second);
	QueryPerformanceCounter(&time_startup);

	time_frequency = 1.0 / (double) time_ticks_per_second.QuadPart;
}

RenderInterfaceDirectX* directx_renderer;
MySystemInterface system_interface;

extern "C"
{
	ALIBROCKET_API void RockInit(void)
	{
		LPDIRECT3DDEVICE9 pd3ddev = (LPDIRECT3DDEVICE9)draw_begin();
		if(pd3ddev == NULL)
			diag("\npd3ddev == NULL");
		directx_renderer = new RenderInterfaceDirectX(pd3ddev);
		Rocket::Core::SetRenderInterface(directx_renderer);
		system_interface.Initialize();
		Rocket::Core::SetSystemInterface(&system_interface);
		Rocket::Core::Initialise();

		context = Rocket::Core::CreateContext("main", Rocket::Core::Vector2i(1024, 768));
		if (context == NULL)
		{
			diag("\ncontext == NULL");
			Rocket::Core::Shutdown();
			return;
		}
		Rocket::Debugger::Initialise(context);

		Rocket::Core::String font_names[4];
		font_names[0] = "Delicious-Roman.otf";
		font_names[1] = "Delicious-Italic.otf";
		font_names[2] = "Delicious-Bold.otf";
		font_names[3] = "Delicious-BoldItalic.otf";

		for (int i = 0; i < sizeof(font_names) / sizeof(Rocket::Core::String); i++)
		{
			Rocket::Core::FontDatabase::LoadFontFace(font_names[i]);
		}

		Rocket::Core::ElementDocument* document = context->LoadDocument("demo.rml");
		if (document != NULL)
		{
			document->Show();
			document->RemoveReference();
		}
		else
		{
			diag("\ndocument == NULL");
		}
	}

	ALIBROCKET_API void RockDestroy(void)
	{
		context->RemoveReference();
		Rocket::Core::Shutdown();
	}

	ALIBROCKET_API void RockUpdate(void)
	{
		//diag("\nRockUpdate");
		LPDIRECT3DDEVICE9 g_pd3dDevice = (LPDIRECT3DDEVICE9)draw_begin();
		
		D3DXMATRIX projection;
		D3DXMatrixOrthoOffCenterLH(&projection, 0, 1024, 768, 0, -1, 1);
		g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &projection);

		g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

		// Enable alpha-blending for Rocket.
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		// Set up the texture stage states for the diffuse texture.
		g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
		g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
		g_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
		g_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);

		g_pd3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
		g_pd3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);

		// Disable lighting for Rocket.
		g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		context->Update();
		context->Render();
	}
}