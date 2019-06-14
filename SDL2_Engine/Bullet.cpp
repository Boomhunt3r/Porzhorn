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

// update every frame
void GBullet::Update(float _deltaSeconds)
{
	// add timer +1
	timer += 1.0f;

	// if collision target
	if (m_pColTarget)
	{
		// remove object
		CTM->RemoveObject(this);

		// if collision target has tag enemy
		if (m_pColTarget->GetTag() == "Enemy")
			((GMoveEnemy*)m_pColTarget)->TakeDamage(BULLET_DAMAGE); // do damage on target with Bullet Damage

		if (m_pColTarget->GetTag() == "Boss")
			((GBoss*)m_pColTarget)->TakeDamage(BULLET_DAMAGE);	// do damage on target with Bullet Damage
	}

	// if timer * deltaseconds higer or as bullet lenght
	if (timer * _deltaSeconds >= BULLET_LENGTH)
	{
		// remove object
		CTM->RemoveObject(this);
		// reset timer
		timer = 0.0f;
	}

	// update parent
	CMoveObject::Update(_deltaSeconds);

}

// render every frame
void GBullet::Render()
{
	// render every frame
	CMoveObject::Render();
}
#pragma endregion