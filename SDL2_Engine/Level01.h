#pragma once

#pragma region project include
#include "TexturedObject.h" 
#pragma endregion

/// <summary>
/// world class
/// </summary>
class GLevel01 : public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">absolute file path name</param>
	GLevel01(const char* _pFileName)
		: CTexturedObject(_pFileName, SVector2(), SVector2()) {}

	/// <summary>
	/// destructor
	/// </summary>
	~GLevel01() {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize world
	/// </summary>
	void Init() override;
#pragma endregion
};