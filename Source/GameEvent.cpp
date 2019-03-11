#include "GameEvent.h"
GameEvent::GameEvent()
{

}
GameEvent::~GameEvent()
{

}
bool GameEvent::KeyboardDown(SDL_Event &event)
{
	switch(event.key.keysym.sym)
	{
		case SDLK_1:
				game.Keys.key_1 = !game.Keys.key_1;
				printf("key_1: %i \n",game.Keys.key_1);
				game.Flags.currentFont = 0;
			break;
		case SDLK_2:
				game.Keys.key_2 = !game.Keys.key_2;
				printf("key_2: %i \n",game.Keys.key_2);
				game.Flags.currentFont = 1;
			break;
		case SDLK_3:
				game.Flags.currentFont = 2;
			break;
		case SDLK_F1:
				game.Keys.key_F1 = true;
			break;
		case SDLK_F2:
				game.Keys.key_F2 = true;
			break;
		case SDLK_F3:
				game.Keys.key_F3 = true;
			break;
		case SDLK_F4:
				game.Keys.key_F4 = true;
			break;
		case SDLK_LEFT:
				game.Keys.key_Left = true;
			break;
		case SDLK_RIGHT:
				game.Keys.key_Right = true;
			break;
		case SDLK_UP:
				game.Keys.key_Up = true;
			break;
		case SDLK_DOWN:
				game.Keys.key_Down = true;
			break;
		case SDLK_KP_MINUS:
			game.Keys.key_minus = true;
			break;
		case SDLK_KP_PLUS:
			game.Keys.key_plus = true;
			break;
		case SDLK_ESCAPE:
			return true;
			break;
	}
	return false;
}
bool GameEvent::KeyboardUp(SDL_Event &event)
{
	switch(event.key.keysym.sym)
	{
		case SDLK_1:
			break;
		case SDLK_2:
			break;
		case SDLK_3:
			break;
		case SDLK_4:
			break;
		case SDLK_F1:
				game.Keys.key_F1 = false;
			break;
		case SDLK_F2:
				game.Keys.key_F2 = false;
			break;
		case SDLK_F3:
				game.Keys.key_F3 = false;
			break;
		case SDLK_F4:
				game.Keys.key_F4 = false;
			break;
		case SDLK_LEFT:
				game.Keys.key_Left = false;
			break;
		case SDLK_RIGHT:
				game.Keys.key_Right = false;
			break;
		case SDLK_UP:
				game.Keys.key_Up = false;
			break;
		case SDLK_DOWN:
				game.Keys.key_Down = false;
			break;
		case SDLK_KP_MINUS:
			game.Keys.key_minus = false;
			break;
		case SDLK_KP_PLUS:
			game.Keys.key_plus = false;
			break;
		case SDLK_ESCAPE:
			return true;
			break;
	}
	return false;
}
void GameEvent::MouseButtonDown(SDL_Event &event)
{
	switch(event.button.button) 
	{
		case SDL_BUTTON_LEFT: 
		{
			
		 
			break;
		}
		case SDL_BUTTON_RIGHT: {
				game.Flags.mouseMenu = !game.Flags.mouseMenu;		
				game.Variables.cursorPrevX = game.Variables.cursorX;
				game.Variables.cursorPrevY = game.Variables.cursorY;
			break;
		}
		case SDL_BUTTON_MIDDLE: {
					
			break;
		}
	}
}
void GameEvent::MouseButtonUp(SDL_Event &event)
{
	switch(event.button.button) 
	{
		case SDL_BUTTON_LEFT: {
		 
			break;
		}
		case SDL_BUTTON_RIGHT: {

			break;
		}
		case SDL_BUTTON_MIDDLE: {
			break;
		}
	}
}
void GameEvent::MouseMotion(SDL_Event &event)
{
	game.Variables.cursorX = event.motion.x;
	game.Variables.cursorY = event.motion.y;
}