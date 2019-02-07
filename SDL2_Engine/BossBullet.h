#pragma once

#pragma region project include
#include "MoveObject.h" 
#pragma endregion

/// <summary>
/// Boss bullet class
/// </summary>
class GBossBullet : public CMoveObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width (x) and height (y) of object</param>
	GBossBullet(SVector2 _pos = SVector2(), SVector2 _size = SVector2()) : CMoveObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">absolute file path name</param>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of object</param>
	GBossBullet(const char* _pFileName, SVector2 _pos, SVector2 _size) : CMoveObject(_pFileName, _pos, _size) {}
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
};