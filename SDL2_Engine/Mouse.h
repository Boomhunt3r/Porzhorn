#pragma once

#pragma region system include
#include <SDL.h>
#pragma endregion

#pragma region project include
#include "TexturedObject.h" 
#pragma endregion

/// <summary>
/// mouse class
/// </summary>
class CMouse : public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CMouse() : CTexturedObject() {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_size">width (x) and height (y) of mouse</param>
	CMouse(SVector2 _size) : CTexturedObject(SVector2(), _size) {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~CMouse() {}
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
	void Render() override;
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// set mouse visible
	/// </summary>
	/// <param name="_visible">visible</param>
	void SetVisible(bool _visible) { m_visible = _visible; }

	/// <summary>
	/// set center of mouse from texture
	/// </summary>
	/// <param name="_center">new center of mouse in percentage</param>
	void SetCenter(SVector2 _center) { m_center = _center; }
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// mouse texture visible
	/// </summary>
	bool m_visible;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// position of mouse center 
	/// in percentage from upper left
	/// upper left is 0,0
	/// lower right is 1,1
	/// </summary>
	SVector2 m_center;
#pragma endregion
};