#pragma region project include
#include "Mouse.h"
#include "Input.h"
#pragma endregion

#pragma region public override function
// update every frame
void CMouse::Update(float _deltaSeconds)
{
	// set position of mouse
	m_position.X = CInput::GetMousePos().X - m_center.X * m_rect.w;
	m_position.Y = CInput::GetMousePos().Y - m_center.Y * m_rect.h;

	// update parent
	CTexturedObject::Update(_deltaSeconds);
}

// render every frame
void CMouse::Render()
{
	// if mouse visible render
	if(m_visible)
		CTexturedObject::Render();
}
#pragma endregion