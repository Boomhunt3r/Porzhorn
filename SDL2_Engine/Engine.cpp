#pragma region system include
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#pragma endregion

#pragma region project include
#include "Engine.h"
#include "Renderer.h"
#include "Scene.h"
#include "Input.h"
#include "Time.h"
#include "ContentManagement.h"
#include "TextureManagement.h"
#include "Mouse.h"
#include "Macro.h"
#include "Game.h"
#pragma endregion

#pragma region public function
// initialize engine
int CEngine::Init()
{
	// initialize sdl video
	LOG_SDL_ERROR(SDL_Init(SDL_INIT_VIDEO) < 0, 101);

	// create window
	m_pWindow = SDL_CreateWindow(
		"SDL2 Engine",				// name of window
		SDL_WINDOWPOS_CENTERED,		// position x of window
		SDL_WINDOWPOS_CENTERED,		// position y
		SCREEN_WIDTH,				// width of window
		SCREEN_HEIGHT,				// height
		SDL_WINDOW_SHOWN			// flags
		);

	// if window not created
	LOG_SDL_ERROR(!m_pWindow, 102);

	// get surface from window
	m_pSurface = SDL_GetWindowSurface(m_pWindow);

	// if surface not initialized
	LOG_SDL_ERROR(!m_pSurface, 103);

	// initialize sdl font
	LOG_SDL_ERROR(TTF_Init(), 104);

	// initialize audio
	LOG_SDL_ERROR(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096), 105);

	// create renderer
	m_pRenderer = new CRenderer(m_pWindow);

	// if renderer not initialized
	if (!m_pRenderer)
	{
		LOG_ERROR("Renderer not initialized", 201);
	}

	// create time
	m_pTime = new CTime();

	// if time not initialized
	if (!m_pTime)
	{
		LOG_ERROR("Time not initialized", 202);
	}

	// create ctm
	m_pCTM = new CContentManagement();

	// if ctm not initialized
	if (!m_pCTM)
	{
		LOG_ERROR("Content Management not initialized", 203);
	}

	// create tm
	m_pTM = new CTextureManagement();

	// if tm not initialized
	if (!m_pTM)
	{
		LOG_ERROR("Texture Management not initialized", 204);
	}

	// create mouse
	m_pMouse = new CMouse(SVector2(16, 16));
	m_pMouse->SetInWorld(false);
	SDL_ShowCursor(SDL_DISABLE);

	// if mouse not initialized
	if (!m_pMouse)
	{
		LOG_ERROR("Mouse not initialized", 205);
	}

	// correct initialized
	return 0;
}

// change current scene
void CEngine::ChangeScene(CScene * _pScene)
{
	// if current scene valid delete
	if (m_pScene)
	{
		m_pScene->Clean();
		delete m_pScene;
	}

	// set current scene pointer to new scene
	m_pScene = _pScene;

	// if new current scene valid load scene
	if (m_pScene)
		m_pScene->Load();
}

// run engine
void CEngine::Run()
{
	// if engine is running
	while (m_isRunning)
	{
		// update every frame
		Update();

		// render every frame
		Render();

		// update game
		GAME->Update(CTime::GetDeltaTime());
	}
}

// clean up engine
void CEngine::Clean()
{
	// change scene to null (delete current scene)
	ChangeScene(nullptr);

	// delete mouse
	delete m_pMouse;

	// delete ctm
	delete m_pCTM;

	// delete time
	delete m_pTime;

	// delete renderer
	delete m_pRenderer;
	
	// close audio
	Mix_CloseAudio();

	// free surface
	SDL_FreeSurface(m_pSurface);

	// destroy window
	SDL_DestroyWindow(m_pWindow);

	// quit sdl
	SDL_Quit();
}

// set mouse visible
void CEngine::SetMouseVisible(bool _visible)
{
	// set mouse visible
	m_pMouse->SetVisible(_visible);
}

// set center of mouse
void CEngine::SetMouseCenter(SVector2 _center)
{
	// set mouse center
	m_pMouse->SetCenter(_center);
}

// set mouse texture
void CEngine::SetMouseTexture(CTexture* _pTexture)
{
	// set mouse texture
	m_pMouse->SetTexture(_pTexture);
}
#pragma endregion

#pragma region private function
// update every frame
void CEngine::Update()
{
	// update time
	m_pTime->Update();

	// refresh input
	CInput::RefreshState();

	// sdl event
	SDL_Event e;

	// get every thrown sdl event
	while (SDL_PollEvent(&e))
	{
		// if sdl event quit
		if (e.type == SDL_EventType::SDL_QUIT)
			// quit engine
			m_isRunning = false;

		// if sdl event key down of up
		if (e.type == SDL_EventType::SDL_KEYDOWN || e.type == SDL_EventType::SDL_KEYUP)
			// parse event to input
			CInput::ParseEvent(e);

		// parse mouse events
		else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
			CInput::ParseMouseEvent(e);
	}

	// if escape pressed set engine running false
	if (CInput::GetKeyDown(SDL_SCANCODE_ESCAPE))
		m_isRunning = false;

	// update ctm
	m_pCTM->Update(m_pTime->GetDeltaTime());

	// if scene valid update scene
	if (m_pScene)
		m_pScene->Update(m_pTime->GetDeltaTime());

	// update mouse
	m_pMouse->Update(m_pTime->GetDeltaTime());
}

// render every frame
void CEngine::Render()
{
	// clear screen
	m_pRenderer->ClearScreen();

	// if scene valid render scene
	if (m_pScene)
		m_pScene->Render();
	
	// render ctm
	m_pCTM->Render();

	// render mosue
	m_pMouse->Render();

	// present rendered scene
	m_pRenderer->Present();
}
#pragma endregion