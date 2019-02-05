#pragma region project include
#include "Time.h" 
#pragma endregion

#pragma region variable
float CTime::s_deltaTime = 0.0f;
int CTime::s_fps = 0;
#pragma endregion

#pragma region public function
// update every frame
void CTime::Update()
{
	// time since application start in milliseconds
	clock_t now = clock();

	// difference to last frame
	clock_t diff = now - m_lastUpdate;

	// calculate delta time
	s_deltaTime = diff / (float)CLOCKS_PER_SEC;

	// set last update now
	m_lastUpdate = now;

	// increase frames since last time stamp
	m_framesSinceLastTimeStamp++;

	// increase time since last time stamp
	m_timeSinceLastTimeStamp += diff;

	// if time since last time stamp lower than clocks per second return
	if (m_timeSinceLastTimeStamp <= CLOCKS_PER_SEC)
		return;

	// set fps
	s_fps = m_framesSinceLastTimeStamp;

	// reset frames since last time stamp
	m_framesSinceLastTimeStamp = 0;

	// decrease time since last time stamp
	m_timeSinceLastTimeStamp -= CLOCKS_PER_SEC;

	// reset delta time
	s_deltaTime = 0.0f;
}
#pragma endregion