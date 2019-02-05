#pragma once

#pragma region system include
#include <list>
#pragma endregion

#pragma region project include
#include "TexturedObject.h" 
#pragma endregion

/// <summary>
/// moveable object class
/// </summary>
class CMoveObject : public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width (x) and height (y) of object</param>
	CMoveObject(SVector2 _pos = SVector2(), SVector2 _size = SVector2()) : CTexturedObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">absolute file path name</param>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of object</param>
	CMoveObject(const char* _pFileName, SVector2 _pos, SVector2 _size) : CTexturedObject(_pFileName, _pos, _size){}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~CMoveObject() {}
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
	/// activate gravity
	/// </summary>
	inline void ActivateGravity() { m_gravity = true; }

	/// <summary>
	/// deactivate gravity
	/// </summary>
	inline void DeactivateGravity() { m_gravity = false; }

	/// <summary>
	/// get movement speed
	/// </summary>
	/// <returns>movement speed</returns>
	inline float GetSpeed() { return m_speed; }

	/// <summary>
	/// set movement speed
	/// </summary>
	/// <param name="_speed">movement speed to set</param>
	inline void SetSpeed(float _speed) { m_speed = _speed; }

	/// <summary>
	/// get movement values
	/// </summary>
	/// <returns>movement values</returns>
	inline SVector2 GetMovement() { return m_movement; }

	/// <summary>
	/// set movement values
	/// </summary>
	/// <param name="_movement">movement values</param>
	inline void SetMovement(SVector2 _movement) { m_movement = _movement; }

	/// <summary>
	/// set fall time
	/// </summary>
	/// <param name="_fallTime">fall time to set</param>
	inline void SetFallTime(float _fallTime) { m_fallTime = _fallTime; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// fill collision list with near collidable objects
	/// </summary>
	/// <param name="_deltaSeconds">time since last frame</param>
	void SetCollisionList(float _deltaSeconds);
#pragma endregion

protected:
#pragma region protected primitive variable
	/// <summary>
	/// object moveable
	/// </summary>
	bool m_moveable = true;

	/// <summary>
	/// if gravity is active
	/// </summary>
	bool m_gravity;

	/// <summary>
	/// movement speed
	/// </summary>
	float m_speed;

	/// <summary>
	/// if glider is active
	/// </summary>
	bool m_glider;

	/// <summary>
	/// time that object is in air
	/// </summary>
	float m_fallTime;

	/// <summary>
	/// object is on ground
	/// </summary>
	bool m_grounded;

	/// <summary>
	/// timer until collision list update
	/// </summary>
	float m_colTimer;
#pragma endregion

#pragma region protected variable
	/// <summary>
	/// movement values
	/// </summary>
	SVector2 m_movement;
#pragma endregion

#pragma region protected pointer
	/// <summary>
	/// list with all collision objects in range
	/// </summary>
	std::list<CTexturedObject*> m_pCol;
#pragma endregion

private:
#pragma region private function
	/// <summary>
	/// check collision with collidable objects list
	/// </summary>
	/// <param name="_deltaSeconds">time since last frame</param>
	/// <param name="_movement">movmenet to move to</param>
	/// <param name="_speed">movement speed</param>
	/// <param name="_useGravity">if gravity movement</param>
	void CheckCollision(float _deltaSeconds, SVector2 _movement, float _speed, bool _useGravity);
#pragma endregion
};