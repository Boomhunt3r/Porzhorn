#pragma once

#pragma region system include
#include <time.h> 
#pragma endregion

/// <summary>
/// time class
/// </summary>
class CTime
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CTime() {}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get time since last frame
	/// </summary>
	/// <returns>time since last frame</returns>
	static inline float GetDeltaTime() { return s_deltaTime > 1 ? 0.0f : s_deltaTime; }

	/// <summary>
	/// get frames per second
	/// </summary>
	/// <returns>frames per second</returns>
	static inline int GetFPS() { return s_fps; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// update every frame
	/// </summary>
	void Update();
#pragma endregion

private:
#pragma region private priitive variable
	/// <summary>
	/// frames per second
	/// </summary>
	static int s_fps;

	/// <summary>
	/// time since last frame
	/// </summary>
	static float s_deltaTime;

	/// <summary>
	/// frames since last time stamp
	/// </summary>
	int m_framesSinceLastTimeStamp;

	/// <summary>
	/// last updated time point
	/// </summary>
	clock_t m_lastUpdate;

	/// <summary>
	/// time since last time stamp
	/// </summary>
	clock_t m_timeSinceLastTimeStamp;
#pragma endregion
};