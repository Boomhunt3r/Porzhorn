#pragma once

#pragma region system include
#include <SDL_ttf.h>
#include <SDL_image.h>
#pragma endregion

#pragma region project include
#include "TexturedObject.h"
#include "Color.h"
#pragma endregion

#pragma region forward decleration
class CFont;
#pragma endregion

/// <summary>
/// class fot text objects
/// </summary>
class CText : public CTexturedObject
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
	CText(const char* _pText, CFont* _pFont, SRect _rect = SRect(), SColor _color = SColor());
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	~CText();
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

#pragma region public inline function
	/// <summary>
	/// get text
	/// </summary>
	/// <returns>text</returns>
	inline const char* GetText() {  }

	/// <summary>
	/// set text
	/// </summary>
	/// <param name="_pText">text to set</param>
	inline void SetText(const char* _pText)
	{
		// set text
		m_pText = _pText;

		// load text
		Load();
	}

	/// <summary>
	/// get color of text
	/// </summary>
	/// <returns>color of text</returns>
	inline SColor GetColor() {  }

	/// <summary>
	/// set color of text
	/// </summary>
	/// <param name="_color">color to set</param>
	inline void SetColor(SColor _color)
	{
		// set color
		m_color = _color;

		// load text
		Load();
	}

	/// <summary>
	/// get font
	/// </summary>
	/// <returns>font</returns>
	inline CFont* GetFont() {  }

	/// <summary>
	/// set font
	/// </summary>
	/// <param name="_pFont">font to set</param>
	inline void SetFont(CFont* _pFont)
	{
		// set font
		m_pFont = _pFont;

		// load text
		Load();
	}
#pragma endregion

protected:
#pragma region protected primitive variable
	/// <summary>
	/// text value
	/// </summary>
	const char* m_pText;
#pragma endregion

#pragma region protected variable
	/// <summary>
	/// color of text
	/// </summary>
	SColor m_color;

	/// <summary>
	/// font
	/// </summary>
	CFont* m_pFont = nullptr;

	/// <summary>
	/// sdl surface
	/// </summary>
	SDL_Surface* m_pSurface = nullptr;
#pragma endregion

#pragma region private function
	/// <summary>
	/// load text
	/// </summary>
	inline void Load();
#pragma endregion
};