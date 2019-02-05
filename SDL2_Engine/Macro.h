#pragma once

#pragma region system include
#include <iostream>
#include <string>
#pragma endregion

#pragma region macro value
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720 
#define COLLISION_CHECK_TIME 0.00001f
#pragma endregion

#pragma region macro function
#define LOG(TEXT)				\
std::cout << TEXT << std::endl;

#define LOG_ERROR(TEXT, ID)		\
LOG(TEXT)						\
return ID;

#define LOG_SDL_ERROR(CHECK, ID)				\
if(CHECK)										\
{												\
	std::cout << SDL_GetError() << std::endl;	\
	return ID;									\
}  
#pragma endregion