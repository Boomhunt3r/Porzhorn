#pragma once

#pragma region project include
#include "MoveObject.h" 
#pragma endregion

/// <summary>
/// player class
/// </summary>
class GPlayer :	public CMoveObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width (x) and height (y) of object</param>
	GPlayer(SVector2 _pos = SVector2(), SVector2 _size = SVector2()) : CMoveObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">absolute file path name</param>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of object</param>
	GPlayer(const char* _pFileName, SVector2 _pos = SVector2(), SVector2 _size = SVector2()) : CMoveObject(_pFileName, _pos, _size) {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~GPlayer() {}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// set camera max position
	/// </summary>
	/// <param name="_pos"> left and right min and max value of camera position</param>
	void SetCameraMaxPosition(SVector2 _pos) { m_cameraMaxValue = _pos; }
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize object
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
	void Render() override;
#pragma endregion

#pragma region private primitive variable
	/// <summary>
	/// speed for gravity
	/// </summary>
	float m_fallSpeed;

	/// <summary>
	/// jump speed
	/// </summary>
	float m_jumpSpeed;

	/// <summary>
	/// left and right min and max value of camera position
	/// x = right
	/// y = down
	/// </summary>
	SVector2 m_cameraMaxValue;
#pragma endregion
};