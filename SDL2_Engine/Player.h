#pragma once

#pragma region project include
#include "MoveObject.h"
#include "Animation.h"
#include "Sound.h"
#pragma endregion

/// <summary>
/// player class
/// </summary>
class GPlayer : public CMoveObject
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
	virtual ~GPlayer() 
	{
		// delete Punch sound
		delete m_pPunch;
		// delete Jump Sound
		delete m_pJump;
		// delete Glide Sound
		delete m_pGlide;
		// delete Collect Sound
		delete m_pCollect;

		// set current animation to null pointer
		m_pCurrentAnim = nullptr;

		// delete IDLE animation and pointer
		delete m_pIDLEAnim;
		// delete Box animation and pointer
		delete m_pBoxAnim;
		// delete Glide animation and pointer
		delete m_pGlideAnim;
		// delete Jump animation and pointer
		delete m_pJumpAnim;
		// delete Swim animation and pointer
		delete m_pSwimAnim;
		// delete Run animation and pointer
		delete m_pRunAnim;
	}
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

#pragma region public primitave bools
	/// <summary>
	/// if player is Gliding
	/// </summary>
	bool m_isGliding;

	/// <summary>
	/// if Player has Key
	/// </summary>
	bool m_hasKey = false;

	/// <summary>
	/// 
	/// </summary>
	bool m_NPC1 = false;

	/// <summary>
	/// 
	/// </summary>
	bool m_NPC2 = false;

	/// <summary>
	/// 
	/// </summary>
	bool m_NPC3 = false;

	/// <summary>
	/// 
	/// </summary>
	bool m_Tutorial = false;

	/// <summary>
	/// if player is jumping
	/// </summary>
	bool m_isJumping = false;
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// Punch Spund
	/// </summary>
	CSound* m_pPunch;

	/// <summary>
	/// Jump Sound
	/// </summary>
	CSound* m_pJump;
	
	/// <summary>
	/// Glide Sound
	/// </summary>
	CSound* m_pGlide;

	/// <summary>
	/// collect sound
	/// </summary>
	CSound* m_pCollect;

	/// <summary>
	/// current animation
	/// </summary>
	CAnimation* m_pCurrentAnim;

	/// <summary>
	/// ilde animation
	/// </summary>
	CAnimation* m_pIDLEAnim;

	/// <summary>
	/// run animation
	/// </summary>
	CAnimation* m_pRunAnim;

	/// <summary>
	/// Box Animation
	/// </summary>
	CAnimation* m_pBoxAnim;

	/// <summary>
	/// Glide Animation
	/// </summary>
	CAnimation* m_pGlideAnim;

	/// <summary>
	/// Jump Animation
	/// </summary>
	CAnimation* m_pJumpAnim;

	/// <summary>
	/// Swim Animation
	/// </summary>
	CAnimation* m_pSwimAnim;
#pragma endregion
};