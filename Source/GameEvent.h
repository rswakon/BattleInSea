#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include "SDL.h"
#include "Globals.h"

class GameEvent
{
	public:
		GameEvent();
		~GameEvent();

	public:		
		bool KeyboardDown(SDL_Event &event);
		bool KeyboardUp(SDL_Event &event);
		void MouseButtonDown(SDL_Event &event);
		void MouseButtonUp(SDL_Event &event);
		void MouseMotion(SDL_Event &event);
};
#endif