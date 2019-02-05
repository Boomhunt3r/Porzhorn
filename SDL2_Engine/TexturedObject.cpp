#pragma region project include
#include "TexturedObject.h"
#include "Renderer.h"
#include "Engine.h"
#include "TextureManagement.h"
#include "Texture.h"
#pragma endregion

#pragma region constructor
// constructor
CTexturedObject::CTexturedObject(SVector2 _pos, SVector2 _size)
{
	// set position
	m_position = _pos;

	// set rect width and height
	m_rect.w = _size.X;
	m_rect.h = _size.Y;
}

// constructor
CTexturedObject::CTexturedObject(const char * _pFileName, SVector2 _pos, SVector2 _size)
	: CTexturedObject(_pos, _size)
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
		if(_pFileName)
			TM->AddTexture(_pFileName, m_pTexture);
	}
}
#pragma endregion

#pragma region public override function
// initialize object
void CTexturedObject::Init()
{

}

// update every frame
void CTexturedObject::Update(float _deltaTime)
{
	if (m_inWorld)
	{
		m_rect.x = m_position.X * RENDERER->GetZoom();
		m_rect.y = m_position.Y * RENDERER->GetZoom();
	}
	else
	{
		m_rect.x = m_position.X;
		m_rect.y = m_position.Y;
	}
}

// render every frame
void CTexturedObject::Render()
{
	// render texture
	RENDERER->RenderTexture(m_pTexture, &m_rect, &m_srcRect, m_angle, m_mirror, m_inWorld);
}
#pragma endregion