#pragma region system include
#include <string>
#include <cstdlib>
#pragma endregion

#pragma region project include
#include "TextFPS.h"
#include "Time.h"
#pragma endregion

#pragma region public override function
// update every frame
void GTextFPS::Update(float _deltaTime)
{
	// get fps as string
	std::string fps;
	fps += std::to_string(CTime::GetFPS());

	// get char*
	m_pText = fps.c_str();

	// random color
	m_color = SColor(
		255,
		255,
		255,
		255
	);

	// load text
	Load();
}

// render every frame
void GTextFPS::Render()
{
	CText::Render();
}
#pragma endregion