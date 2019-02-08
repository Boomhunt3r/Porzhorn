#pragma once

#pragma region project include
#include "TexturedObject.h" 
#pragma endregion

/// <summary>
/// world class
/// </summary>
class GLevel02 : public CTexturedObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">absolute file path name</param>
	GLevel02(const char* _pFileName)
		: CTexturedObject(_pFileName, SVector2(), SVector2()) {}

	/// <summary>
	/// destructor
	/// </summary>
	~GLevel02() {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize world
	/// </summary>
	void Init() override;
#pragma endregion

	inline void SetLevel(int _level) { m_level = _level; }

	inline int GetLevel() { return m_level; }

#pragma region protected variable
	/// <summary>
	/// level
	/// </summary>
protected:
	int m_level = 1;
#pragma endregion
};