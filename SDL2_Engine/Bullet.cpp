#pragma region project include
#include "Bullet.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "MoveEnemy.h"
#include "Config.h"
#pragma endregion

#pragma region public override function
// update every frame
void GBullet::Update(float _deltaSeconds)
{
	if (m_pColTarget && (m_pColTarget->GetColType() != ECollisionType::COL))
	{
		CTM->RemoveObject(this);

		if (m_pColTarget->GetTag() == "Enemy")
			((GMoveEnemy*)m_pColTarget)->TakeDamage(BULLET_DAMAGE);
	}

	CMoveObject::Update(_deltaSeconds);
}

// render every frame
void GBullet::Render()
{
	CMoveObject::Render();
}
#pragma endregion