#pragma once

#pragma region project include
#include "MoveObject.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Animation.h"
#include "TexturedObject.h"
#pragma endregion

/// <summary>
/// move enemy class
/// </summary>
class GBoss : public CMoveObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width (x) and height (y) of object</param>
	GBoss(SVector2 _pos = SVector2(), SVector2 _size = SVector2()) : CMoveObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">absolute file path name</param>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of object</param>
	GBoss(const char* _pFileName, SVector2 _pos, SVector2 _size) : CMoveObject(_pFileName, _pos, _size) {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~GBoss()
	{
		// set current animation to null pointer
		m_pCurrentAnim = nullptr;

		// delete Move animation and pointer
		delete m_pMoveAnim;
		// delete Shoot animation and pointer
		delete m_pShootAnim;
	}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize move enemy
	/// </summary>
	virtual void Init() override;

	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaSeconds">time since last frame</param>
	virtual void Update(float _deltaSeconds) override;

	/// <summary>
	/// render every frame
	/// </summary>
	virtual void Render() override;
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// take damage
	/// </summary>
	/// <param name="_damage">damage</param>
	void TakeDamage(float _damage)
	{
		// decrease health and if under 0
		if ((m_health -= _damage) <= 0.0f)
		{
			Death();
			// remove me
			CTM->RemoveObject(this);
		}
	}
#pragma endregion

#pragma region public function
	/// <summary>
	/// Random Event
	/// </summary>
	void REvent();

	/// <summary>
	/// Shoot function from Random Event
	/// </summary>
	void Shoot();

	/// <summary>
	/// Death function
	/// </summary>
	void Death();

#pragma endregion

public:
#pragma region private primitive variable
	/// <summary>
	/// health of Boss
	/// </summary>
	float m_health;
#pragma endregion
private:
#pragma region private pointer
	/// <summary>
	/// Current Animation
	/// </summary>
	CAnimation* m_pCurrentAnim;

	/// <summary>
	/// Move Animatiom
	/// </summary>
	CAnimation* m_pMoveAnim;

	/// <summary>
	/// shoot animation
	/// </summary>
	CAnimation* m_pShootAnim;
#pragma endregion

};