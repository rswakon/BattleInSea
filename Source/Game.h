#ifndef GAME_H
#define GAME_H

#include "SDL_opengl.h"
#include "SDL_ttf.h"

#include "GameEvent.h"
#include "Globals.h"


class GameObject
{
	public:
		GameObject();
		~GameObject();

		void OnExecute();
		void OnThink();
		void InitOpengl();
		void GlResize();

	private:
		int ScreenBPP;
		int FramePerSecond;
		Uint32 ScreenFlags;

		bool done;
		bool resize;
		SDL_Event event;

		Uint32 SomeTimeControlVariable;
		Uint32 thisTime;
		Uint32 lastTime;
		//Uint32 deltaTime;
		Uint32 frameTime;
		Uint32 frameStartTime;
		float deltaTime;
		SDL_Surface* screen;
		GameEvent* gameInput;

};


#endif