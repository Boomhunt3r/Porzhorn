#pragma once

#pragma region project include
#include "Vector2.h"
#pragma endregion

#pragma region forward decleration
struct SRect;
class CTexture;
class SDL_Window;
class SDL_Renderer;
#pragma endregion

/// <summary>
/// class to render images
/// </summary>
class CRenderer
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pWindow">sdl window reference</param>
	CRenderer(SDL_Window* _pWindow);
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	~CRenderer();
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get zoom value
	/// </summary>
	/// <returns>zoom value</returns>
	inline float GetZoom() { return m_zoom; }

	/// <summary>
	/// set zoom value
	/// </summary>
	/// <param name="_value">value to set</param>
	inline void SetZoom(float _value) { m_zoom = _value; }

	/// <summary>
	/// get sdl renderer
	/// </summary>
	/// <returns>sdl renderer reference</returns>
	inline SDL_Renderer* GetSDLRenderer() { return m_pRenderer; }

	/// <summary>
	/// get camera position
	/// </summary>
	/// <returns>camera position</returns>
	inline SVector2 GetCamera() { return m_camera; }

	/// <summary>
	/// set camera position
	/// </summary>
	/// <param name="_pos">position to set</param>
	inline void SetCamera(SVector2 _pos) { m_camera = _pos; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// clear screen
	/// </summary>
	void ClearScreen();

	/// <summary>
	/// render texture
	/// </summary>
	/// <param name="_pTexture">texture</param>
	/// <param name="_pDestRect">destination rect</param>
	/// <param name="_pSrcRect">source rect</param>
	/// <param name="_angle">angle</param>
	/// <param name="_mirror">mirror (x != 0 mirror horizontal, y != 0 mirror vertical)</param>
	/// <param name="_inWorld">texture rendered in world</param>
	void RenderTexture(CTexture* _pTexture, SRect* _pDestRect = nullptr, 
		SRect* _pSrcRect = nullptr, float _angle = 0.0f, SVector2 _mirror = SVector2(),
		bool _inWorld = true);

	/// <summary>
	/// present rendered screen
	/// </summary>
	void Present();
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// zoom value
	/// </summary>
	float m_zoom = 1.0f;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// camera position
	/// </summary>
	SVector2 m_camera;
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// sdl renderer
	/// </summary>
	SDL_Renderer* m_pRenderer;
#pragma endregion
};