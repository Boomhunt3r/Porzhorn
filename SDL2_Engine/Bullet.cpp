#pragma region project include
#include "Bullet.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "MoveEnemy.h"
#include "Config.h"
#include "Macro.h"
#include "Input.h"
#pragma endregion

#pragma region public override function
// update every frame
float timer = 0.0f;

void GBullet::Update(float _deltaSeconds)
{
	timer += 1.0f;

	LOG(timer);

	if (m_pColTarget && (m_pColTarget->GetColType() != ECollisionType::COL))
	{
		CTM->RemoveObject(this);

		if (m_pColTarget->GetTag() == "Enemy")
			((GMoveEnemy*)m_pColTarget)->TakeDamage(BULLET_DAMAGE);
	}

	if (timer >= 3)
	{
		CTM->RemoveObject(this);
		timer = 0.0f;
	}

	CMoveObject::Update(_deltaSeconds);

}

// render every frame
void GBullet::Render()
{
	CMoveObject::Render();
}
#pragma endregion