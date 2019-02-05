#pragma region project include
#include "Input.h" 
#pragma endregion

// static variables has to be initialized
#pragma region variable
bool CInput::s_keyWasDown[];
bool CInput::s_keyIsDown[];
bool CInput::s_mouseWasDown[];
bool CInput::s_mouseIsDown[];
SVector2 CInput::s_mousePos;
#pragma endregion

#pragma region public function
// handle sdl event
void CInput::ParseEvent(SDL_Event _event)
{
	// if key is in range set true or false depending on sdl event
	if (_event.key.keysym.scancode < 256)
		s_keyIsDown[_event.key.keysym.scancode] = _event.type == SDL_KEYDOWN;
}

// handle sdl mouse event
void CInput::ParseMouseEvent(SDL_Event _event)
{
	// mouse moved
	if (_event.type == SDL_MOUSEMOTION)
	{
		// set mouse position
		s_mousePos.X = _event.motion.x;
		s_mousePos.Y = _event.motion.y;
	}

	// mouse clicked
	else
	{
		// set mouse button down
		s_mouseIsDown[_event.button.button - 1] = _event.type == SDL_MOUSEBUTTONDOWN;
	}
}

// refresh state
void CInput::RefreshState()
{
	// set key was down
	for (int i = 0; i < 256; i++)
		s_keyWasDown[i] = s_keyIsDown[i];

	// set mouse was down
	for (int i = 0; i < 3; i++)
		s_mouseWasDown[i] = s_mouseIsDown[i];
}

// get key pressed
bool CInput::GetKey(SDL_Scancode _key)
{
	return s_keyIsDown[_key];
}

// get key pressed this frame
bool CInput::GetKeyDown(SDL_Scancode _key)
{
	return s_keyIsDown[_key] && !s_keyWasDown[_key];
}

// get key released this frame
bool CInput::GetKeyUp(SDL_Scancode _key)
{
	return !s_keyIsDown[_key] && s_keyWasDown[_key];
}

// get mouse button pressed
bool CInput::GetMouseButton(int _number)
{
	return s_mouseIsDown[_number];
}

// get mouse button pressed down this frame
bool CInput::GetMouseButtonDown(int _number)
{
	return s_mouseIsDown[_number] && !s_mouseWasDown[_number];
}

// get mouse button released this frame
bool CInput::GetMouseButtonUp(int _number)
{
	return !s_mouseIsDown[_number] && s_mouseWasDown[_number];
}
#pragma endregion