#pragma region project include
#include "Bullet.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "MoveEnemy.h"
#include "Config.h"
#include "Macro.h"
#include "Input.h"
#include "Boss.h"
#pragma endregion

#pragma region public override function
// update every frame
float timer = 0.0f;

void GBullet::Update(float _deltaSeconds)
{
	timer += 1.0f;

	if (m_pColTarget)
	{
		CTM->RemoveObject(this);

		if (m_pColTarget->GetTag() == "Enemy")
			((GMoveEnemy*)m_pColTarget)->TakeDamage(BULLET_DAMAGE);

		if (m_pColTarget->GetTag() == "Boss")
			((GBoss*)m_pColTarget)->TakeDamage(BULLET_DAMAGE);
	}


	if (timer * _deltaSeconds >= BULLET_LENGTH)
	{
		LOG(timer * _deltaSeconds);
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