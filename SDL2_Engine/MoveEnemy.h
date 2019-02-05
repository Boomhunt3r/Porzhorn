#pragma once

#pragma region project include
#include "MoveObject.h"
#include "Engine.h"
#include "ContentManagement.h"
#pragma endregion

/// <summary>
/// move enemy class
/// </summary>
class GMoveEnemy : public CMoveObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width (x) and height (y) of object</param>
	GMoveEnemy(SVector2 _pos = SVector2(), SVector2 _size = SVector2()) : CMoveObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">absolute file path name</param>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of object</param>
	GMoveEnemy(const char* _pFileName, SVector2 _pos, SVector2 _size) : CMoveObject(_pFileName, _pos, _size) {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~GMoveEnemy() {}
#pragma endregion

#pragma region public override function
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
			// remove me
			CTM->RemoveObject(this);
		}
	}
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize move enemy
	/// </summary>
	void Init();
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// health of enemy
	/// </summary>
	float m_health;
#pragma endregion
};