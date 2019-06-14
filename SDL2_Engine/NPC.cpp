#pragma region project include
#include "NPC.h"
#include "Config.h"
#include "Macro.h"
#include "Game.h"
#include "Player.h"
#include "Animation.h"
#include "Text.h"
#pragma endregion

#pragma region public function
// initialize NPC
void GNPC::Init()
{
	// initiaize ilde animation
	m_pIdleAnim = new CAnimation(SVector2(0.0f, NpcIdlePositionY),
		SVector2(NpcIdleWidth, NpcIdleHeight), 4);
	m_pIdleAnim->SetAnimationTime(1.5f);

	// set Current Animation to Idle
	m_pCurrentAnim = m_pIdleAnim;
}

#pragma region public override function
// update every frame
void GNPC::Update(float _deltaSeconds)
{
	// update parent
	CTexturedObject::Update(_deltaSeconds);

	// update current animation
	m_pCurrentAnim->Update(_deltaSeconds);

	// set src rect
	m_srcRect = SRect(
		SVector2(m_pCurrentAnim->GetCurrentTexturePosition().X, m_pCurrentAnim->GetCurrentTexturePosition().Y),
		m_pCurrentAnim->GetSize()
	);
}

// render every frame
void GNPC::Render()
{
	// render parent
	CTexturedObject::Render();
}
#pragma endregion