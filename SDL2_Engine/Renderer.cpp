#pragma region system include
#include <SDL.h> 
#pragma endregion

#pragma region project include
#include "Renderer.h"
#include "Rect.h"
#include "Texture.h"
#include "Macro.h"
#pragma endregion

#pragma region constructor
// constructor
CRenderer::CRenderer(SDL_Window * _pWindow)
{
	// initialize renderer nullptr
	m_pRenderer = nullptr;

	// create renderer
	m_pRenderer = SDL_CreateRenderer(
		_pWindow,						// window reference
		0,								// index
		SDL_RENDERER_PRESENTVSYNC |		// flags
		SDL_RENDERER_ACCELERATED
	);
}
#pragma endregion

#pragma region destructor
// destructor
CRenderer::~CRenderer()
{
	// if renderer valid destroy renderer
	if (m_pRenderer)
		SDL_DestroyRenderer(m_pRenderer);
}
#pragma endregion

#pragma region public function
// clear screen
void CRenderer::ClearScreen()
{
	SDL_RenderClear(m_pRenderer);
}

// render texture
void CRenderer::RenderTexture(CTexture * _pTexture, SRect* _pDestRect, SRect* _pSrcRect,
	float _angle, SVector2 _mirror, bool _inWorld)
{
	// if texture null return
	if (!_pTexture)
		return;

	// set rotation point
	SDL_Point rotationPoint;
	rotationPoint.x = _pDestRect->w / 2;
	rotationPoint.y = _pDestRect->h / 2;

	// flip texture
	SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;

	// if mirror x not 0 set flip horizontal
	if (_mirror.X && !_mirror.Y)
		flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;

	// if mirror y not 0 set flip vertical
	else if (_mirror.Y && !_mirror.X)
		flip = SDL_RendererFlip::SDL_FLIP_VERTICAL;

	// if width or height of source 0
	if (_pSrcRect->w == 0 || _pSrcRect->h == 0)
		// set source rect nullptr
		_pSrcRect = nullptr;

	SRect rect = *_pDestRect;

	// if texture is rendered in world
	if (_inWorld)
	{
		// set x and y position of destination rect depending on camera position
		rect.x -= m_camera.X - SCREEN_WIDTH / 2;
		rect.y -= m_camera.Y - SCREEN_HEIGHT / 2;
		rect.w *= m_zoom;
		rect.h *= m_zoom;
		rect.w++;
		rect.h++;
	}

	// if destination rect not in screen space return
	if (rect.x < -32.0f
		|| rect.x > SCREEN_WIDTH
		|| rect.y < -32.0f
		|| rect.y > SCREEN_HEIGHT)
		return;

	// render texture
	SDL_RenderCopyEx(
		m_pRenderer,					// sdl renderer reference
		_pTexture->GetSDLTexture(),		// sdl texture reference
		_pSrcRect,						// source rect
		&rect,							// destination rect
		_angle,							// angle of texture
		&rotationPoint,					// center of rotation
		flip							// mirror
	);
}

// present rendered screen
void CRenderer::Present()
{
	SDL_RenderPresent(m_pRenderer);
}
#pragma endregion