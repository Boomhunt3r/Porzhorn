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
	CTexturedObject::Render();
}
#pragma endregion

#pragma region public function
// initialize move enemy
void GNPC::Init()
{
	// set tag
	m_pTag = "NPC";

	// set collision type
	m_colType = ECollisionType::COL;

}
#pragma endregion