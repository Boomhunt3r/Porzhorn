#pragma once

#pragma region system include
#include <map>
#include <string>
#pragma endregion

#pragma region project include
#include "Texture.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

/// <summary>
/// class to manage textures
/// </summary>
class CTextureManagement
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CTextureManagement() {}

	/// <summary>
	/// destructor
	/// </summary>
	~CTextureManagement()
	{
		// as long as there is a texture in map left
		while (m_pTextures.size())
		{
			// delete fist texture in map
			delete m_pTextures.begin()->second;

			// remove key value pair from map
			m_pTextures.erase(m_pTextures.begin()->first);
		}
	}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// add name and texture to map
	/// </summary>
	/// <param name="_name">name of texture</param>
	/// <param name="_pTexture">texture</param>
	void AddTexture(string _name, CTexture* _pTexture)
	{
		m_pTextures.insert(pair<string, CTexture*>(_name, _pTexture));
	}

	/// <summary>
	/// get texture by string
	/// </summary>
	/// <param name="_name">name of texture</param>
	/// <returns>texture</returns>
	CTexture* GetTexture(string _name)
	{
		// texture for return
		CTexture* pTexture = nullptr;

		// if key string exists in map
		std::map<string, CTexture*>::iterator it;
		it = m_pTextures.find(_name);

		if (it != m_pTextures.end())
			pTexture = it->second;

		// return texture
		return pTexture;
	}
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// texture map
	/// </summary>
	map<string, CTexture*> m_pTextures;
#pragma endregion
};