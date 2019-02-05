#pragma once

#pragma region system include
#include <SDL.h> 
#pragma endregion

#pragma region project include
#include "Vector2.h"
#pragma endregion

/// <summary>
/// input class
/// </summary>
class CInput
{
public:
#pragma region public inline function
	/// <summary>
	/// get mouse position
	/// </summary>
	/// <returns>mouse position</returns>
	static inline SVector2 GetMousePos() { return s_mousePos; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// handle sdl event
	/// </summary>
	/// <param name="_event">sdl event</param>
	static void ParseEvent(SDL_Event _event);

	/// <summary>
	/// handle sdl mouse event
	/// </summary>
	/// <param name="_event">sdl event</param>
	static void ParseMouseEvent(SDL_Event _event);

	/// <summary>
	/// refresh key state
	/// </summary>
	static void RefreshState();

	/// <summary>
	/// get key pressed
	/// </summary>
	/// <param name="_key">key scancode</param>
	/// <returns>key is pressed</returns>
	static bool GetKey(SDL_Scancode _key);

	/// <summary>
	/// get key pressed this frame
	/// </summary>
	/// <param name="_key">key scancode</param>
	/// <returns>key is pressed this frame</returns>
	static bool GetKeyDown(SDL_Scancode _key);

	/// <summary>
	/// get key released this frame
	/// </summary>
	/// <param name="_key">key scancode</param>
	/// <returns>key is released this frame</returns>
	static bool GetKeyUp(SDL_Scancode _key);

	/// <summary>
	/// get mouse button pressed
	/// </summary>
	/// <param name="_number">number of mouse button</param>
	/// <returns>mouse button is pressed</returns>
	static bool GetMouseButton(int _number);

	/// <summary>
	/// get mouse button pressed down this frame
	/// </summary>
	/// <param name="_number">number of mouse button</param>
	/// <returns>mouse button is pressed down this frame</returns>
	static bool GetMouseButtonDown(int _number);

	/// <summary>
	/// get mouse button released this frame
	/// </summary>
	/// <param name="_number">number of mouse button</param>
	/// <returns>mouse button is released this frame</returns>
	static bool GetMouseButtonUp(int _number);
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// 256 keys was down last frame
	/// </summary>
	static bool s_keyWasDown[256];

	/// <summary>
	/// 256 keys is down this frame
	/// </summary>
	static bool s_keyIsDown[256];

	/// <summary>
	/// mouse keys was down last frame
	/// </summary>
	static bool s_mouseWasDown[3];

	/// <summary>
	/// mouse keys is down this frame
	/// </summary>
	static bool s_mouseIsDown[3];
#pragma endregion

#pragma region private variable
	/// <summary>
	/// position of mouse
	/// </summary>
	static SVector2 s_mousePos;
#pragma endregion
};