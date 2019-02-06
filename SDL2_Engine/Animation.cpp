#pragma region project include
#include "Animation.h"
#include "TexturedObject.h"
#include "Renderer.h"
#include "Engine.h"
#include "TextureManagement.h"
#include "Texture.h"
#pragma endregion

CAnimation::CAnimation(SVector2 _pos, SVector2 _size)
{
	// set position
	m_position = _pos;

	// set rect width and height
	m_rect.w = _size.X;
	m_rect.h = _size.Y;
}

CAnimation::CAnimation(const char * _pFileName, SVector2 _pos, SVector2 _size)
{
	// if texture allready exists
	if (_pFileName != nullptr && TM->GetTexture(_pFileName))
	{
		// set texture reference
		m_pTexture = TM->GetTexture(_pFileName);
	}

	// if texture not exist
	else
	{
		// create texture
		m_pTexture = new CTexture(_pFileName);

		// add string texture pair to tm
		if (_pFileName)
			TM->AddTexture(_pFileName, m_pTexture);
	}
}

void CAnimation::Init()
{

}

void CAnimation::Update(float _deltaTime)
{

}

void CAnimation::Render()
{

}
