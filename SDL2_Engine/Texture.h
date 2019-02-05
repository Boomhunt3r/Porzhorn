#pragma once

#pragma region forward decleration
class SDL_Texture;
#pragma endregion

/// <summary>
/// texture class
/// </summary>
class CTexture
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pFileName">relative file path</param>
	CTexture(const char* _pFileName);
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	~CTexture();
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get sdl texture
	/// </summary>
	/// <returns>sdl texture</returns>
	inline SDL_Texture* GetSDLTexture() { return m_pTexture; }

	/// <summary>
	/// set sdl texture
	/// </summary>
	/// <param name="_pTexture">texture to set</param>
	inline void SetSDLTexture(SDL_Texture* _pTexture) { m_pTexture = _pTexture; }
#pragma endregion

private:
#pragma region private pointer
	/// <summary>
	/// sdl texture
	/// </summary>
	SDL_Texture* m_pTexture;
#pragma endregion
};