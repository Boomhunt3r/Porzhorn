#pragma region project include
#include "Font.h"
#include "Helper.h"
#pragma endregion

#pragma region constructor
// constructor
CFont::CFont(const char* _pFileName, int _size)
{
	// get absolute asset pasth
	std::string file = GetAssetPath(_pFileName, 4);

	// set file name
	m_pFile = file.c_str();

	// set size
	m_size = _size;

	// open font
	m_pFont = TTF_OpenFont(m_pFile, _size);
}
#pragma endregion

#pragma region destructor
// destructor
CFont::~CFont()
{
	TTF_CloseFont(m_pFont);
}
#pragma endregion