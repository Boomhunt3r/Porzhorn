#pragma region project include
#include "NPC.h"
#include "Config.h"
#include "Macro.h"
#include "Game.h"
#include "Player.h"
#include "Animation.h"
#include "Text.h"
#pragma endregion

#pragma region public override function
// update every frame
void GNPC::Update(float _deltaSeconds)
{
	m_NPC.SetAnimationRect(SRect(154, 245, 0, 0));

	_i = 606 / 404;

	_l += _i;

	if (_l >= 18 && _l <= 36)
	{
		m_NPC.SetAnimationRect(SRect(154, 245, 154, 0));
	}

	if (_l >= 54 && _l <= 72)
	{
		m_NPC.SetAnimationRect(SRect(154, 245, 308, 0));
	}
	if (_l >= 90 && _l <= 108)
	{
		m_NPC.SetAnimationRect(SRect(154, 245, 462, 0));
	}
	if (_l >= 136)
	{
		_l = 0;
	}
	// if Target is nullpointer
	if (m_pColTarget == nullptr)
	{
		// do nothing and continue
		// until targes is not nullptr anymore
	}

	// update parent
	CTexturedObject::Update(_deltaSeconds);
}

// render every frame
void GNPC::Render()
{
	SetSrcRect(m_NPC.GetAnimationRect());

	CTexturedObject::Render();
}
#pragma endregion

#pragma region public function
// initialize move enemy
void GNPC::Init()
{
}
#pragma endregion