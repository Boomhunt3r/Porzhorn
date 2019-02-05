#pragma once

#pragma region project include
#include "Vector2.h"
#pragma endregion

#pragma region forward decleration
class SDL_Window;
class SDL_Surface;
class CRenderer;
class CTexture;
class CScene;
class CTime;
class CContentManagement;
class CTextureManagement;
class CMouse;
#pragma endregion

#pragma region macro
#define ENGINE CEngine::Get()
#define RENDERER ENGINE->GetRenderer()
#define CTM ENGINE->GetCTM()
#define TM ENGINE->GetTM()
#pragma endregion

/// <summary>
/// core engine class
/// </summary>
class CEngine
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CEngine() {}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get engine
	/// </summary>
	/// <returns>engine reference</returns>
	inline static CEngine* Get()
	{
		// create engine if not exists
		static CEngine* pEngine = new CEngine();

		// return engine
		return pEngine;
	}

	/// <summary>
	/// get renderer
	/// </summary>
	/// <returns>renderer reference</returns>
	inline CRenderer* GetRenderer() { return m_pRenderer; }

	/// <summary>
	/// get content management system
	/// </summary>
	/// <returns>content management system</returns>
	inline CContentManagement* GetCTM() { return m_pCTM; }

	/// <summary>
	/// get texture management system
	/// </summary>
	/// <returns>texture management system</returns>
	inline CTextureManagement* GetTM() { return m_pTM; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize engine
	/// </summary>
	/// <returns>initialize code</returns>
	int Init();

	/// <summary>
	/// change current scene
	/// </summary>
	/// <param name="_pScene">new scene</param>
	void ChangeScene(CScene* _pScene);
	
	/// <summary>
	/// run engine
	/// </summary>
	void Run();

	/// <summary>
	/// clean up engine
	/// </summary>
	void Clean();

	/// <summary>
	/// set mouse visible
	/// </summary>
	/// <param name="_visible">visible</param>
	void SetMouseVisible(bool _visible);

	/// <summary>
	/// set center of mouse
	/// </summary>
	/// <param name="_center">center of mouse</param>
	void SetMouseCenter(SVector2 _center);

	/// <summary>
	/// set mouse texture
	/// </summary>
	/// <param name="_pTexture">texture to set</param>
	void SetMouseTexture(CTexture* _pTexture);
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// engine is running
	/// </summary>
	bool m_isRunning = true;
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// sdl window reference
	/// </summary>
	SDL_Window* m_pWindow;

	/// <summary>
	/// sdl surface reference
	/// </summary>
	SDL_Surface* m_pSurface;

	/// <summary>
	/// renderer reference
	/// </summary>
	CRenderer* m_pRenderer;

	/// <summary>
	/// current scene reference
	/// </summary>
	CScene* m_pScene;

	/// <summary>
	/// time reference
	/// </summary>
	CTime* m_pTime;

	/// <summary>
	/// content management system reference
	/// </summary>
	CContentManagement* m_pCTM;

	/// <summary>
	/// texture management system reference
	/// </summary>
	CTextureManagement* m_pTM;

	/// <summary>
	/// mouse
	/// </summary>
	CMouse* m_pMouse;
#pragma endregion

#pragma region private function
	/// <summary>
	/// update every frame
	/// </summary>
	void Update();

	/// <summary>
	/// render every frame
	/// </summary>
	void Render();
#pragma endregion
};