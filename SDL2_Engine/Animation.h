#pragma once

#pragma region project include
#include "Vector2.h"
#pragma endregion

/// <summary>
/// animation class
/// </summary>
class CAnimation
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_startPos">start position of animation in texture</param>
	/// <param name="_size">size of single frame in animation (x = width, y = height)</param>
	/// <param name="_count">frames count of animation</param>
	CAnimation(SVector2 _startPos, SVector2 _size, int _count)
	{
		m_startPos = _startPos;
		m_size = _size;
		m_count = _count;
	}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get size
	/// </summary>
	/// <returns>size</returns>
	inline SVector2 GetSize() { return m_size; }

	/// <summary>
	/// get animation time
	/// </summary>
	/// <returns>animation time</returns>
	inline float GetAnimationTime() { return m_animationTime; }

	/// <summary>
	/// get animation percentage
	/// </summary>
	/// <returns>animation percentage</returns>
	inline float GetAnimationPercentage() { return m_current / m_count * 100.0f; }

	/// <summary>
	/// set animation time
	/// </summary>
	/// <param name="_time">time to set</param>
	inline void SetAnimationTime(float _time) { m_animationTime = _time; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaSeconds">time since last frame</param>
	void Update(float _deltaSeconds);

	/// <summary>
	/// get current position in texture
	/// </summary>
	/// <returns>current position of frame in texture</returns>
	SVector2 GetCurrentTexturePosition();
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// current frame
	/// </summary>
	int m_current = 1;

	/// <summary>
	/// frames count of animation
	/// </summary>
	int m_count;

	/// <summary>
	/// animation time until full animation played
	/// </summary>
	float m_animationTime;

	/// <summary>
	/// current time
	/// </summary>
	float m_time = 0.0f;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// start position of animation in texture
	/// </summary>
	SVector2 m_startPos;

	/// <summary>
	/// size of single frame in animation (x = width, y = height)
	/// </summary>
	SVector2 m_size;
#pragma endregion
};