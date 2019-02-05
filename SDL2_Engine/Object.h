#pragma once

#pragma region project include
#include "Vector2.h"
#include "Enum.h"
#pragma endregion

/// <summary>
/// base object class
/// </summary>
class CObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CObject() {}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get tag of object
	/// </summary>
	/// <returns>tag of object</returns>
	inline const char* GetTag() { return m_pTag; }

	/// <summary>
	/// set tag of object
	/// </summary>
	/// <param name="_pTag">tag of object</param>
	inline void SetTag(const char* _pTag) { m_pTag = _pTag; }

	/// <summary>
	/// get position of object
	/// </summary>
	/// <returns>position of object</returns>
	inline SVector2 GetPosition() { return m_position; }

	/// <summary>
	/// set position of object
	/// </summary>
	/// <param name="_pos">position to set</param>
	inline void SetPosition(SVector2 _pos) { m_position = _pos; }

	/// <summary>
	/// add vector 2 to position
	/// </summary>
	/// <param name="_vec2">vector 2 to add</param>
	inline void AddPosition(SVector2 _vec2) { m_position = m_position + _vec2; }

	/// <summary>
	/// get collision type of object
	/// </summary>
	/// <returns>collision type of object</returns>
	inline ECollisionType GetColType() { return m_colType; }

	/// <summary>
	/// set collision type of object
	/// </summary>
	/// <param name="_type">collision type to set</param>
	inline void SetColType(ECollisionType _type) { m_colType = _type; }

#pragma region public function
	/// <summary>
	/// initialize object
	/// </summary>
	virtual void Init() = 0;

	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual void Update(float _deltaTime) = 0;

	/// <summary>
	/// render every frame
	/// </summary>
	virtual void Render() = 0;
#pragma endregion

protected:
#pragma region protected primitive variable
	/// <summary>
	/// tag of object
	/// </summary>
	const char* m_pTag;
#pragma endregion

#pragma region protected variable
	/// <summary>
	/// position of object
	/// </summary>
	SVector2 m_position;

	/// <summary>
	/// collision type
	/// </summary>
	ECollisionType m_colType;
#pragma endregion
};