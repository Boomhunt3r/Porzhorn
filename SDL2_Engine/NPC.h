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
class GNPC : public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width (x) and height (y) of object</param>
	GNPC(SVector2 _pos = SVector2(), SVector2 _size = SVector2()) : CTexturedObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">absolute file path name</param>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of object</param>
	GNPC(const char* _pFileName, SVector2 _pos, SVector2 _size) : CTexturedObject(_pFileName, _pos, _size) {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~GNPC() 
	{
		m_pCurrentAnim = nullptr;

		delete m_pIdleAnim;
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

private:
#pragma region private pointer
	/// <summary>
	/// current animation
	/// </summary>
	CAnimation* m_pCurrentAnim;

	/// <summary>
	/// ilde animation
	/// </summary>
	CAnimation* m_pIdleAnim;
#pragma endregion

};