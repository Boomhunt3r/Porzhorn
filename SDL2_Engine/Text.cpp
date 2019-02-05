#pragma region project include
#include "Text.h"
#include "Engine.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture.h"
#pragma endregion

#pragma region constructor
// constructor
CText::CText(const char* _pText, CFont* _pFont, SRect _rect, SColor _color)
	: CTexturedObject(nullptr, SVector2(), SVector2())
{
	m_pText = _pText;
	m_pFont = _pFont;
	m_rect = _rect;
	m_color = _color;

	// load text
	Load();
}
#pragma endregion

#pragma region destructor
// destructor
CText::~CText()
{
	SDL_FreeSurface(m_pSurface);
}
#pragma endregion

#pragma region public override function
// update every frame
void CText::Update(float _deltaTime)
{

}

// render every frame
void CText::Render()
{
	CTexturedObject::Render();
}
#pragma endregion

#pragma region private function
// load text
void CText::Load()
{
	// free surface
	SDL_FreeSurface(m_pSurface);

	// update surface
	m_pSurface = TTF_RenderText_Solid(m_pFont->GetFont(), m_pText, m_color);

	// if texture valid destroy old texture
	SDL_DestroyTexture(m_pTexture->GetSDLTexture());

	// create texture
	m_pTexture->SetSDLTexture(SDL_CreateTextureFromSurface(RENDERER->GetSDLRenderer(), m_pSurface));
}
#pragma endregion