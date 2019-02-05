#pragma once

#pragma region project include
#include "Text.h" 
#pragma endregion

/// <summary>
/// fps text class
/// </summary>
class GTextFPS : public CText
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pText">text value</param>
	/// <param name="_pFont">font</param>
	/// <param name="_rect">rect</param>
	/// <param name="_color">color</param>
	GTextFPS(const char* _pText, CFont* _pFont, SRect _rect = SRect(), SColor _color = SColor())
		: CText(_pText, _pFont, _rect, _color) {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	void Render() override;
#pragma endregion
};