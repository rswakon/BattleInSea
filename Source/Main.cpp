#include "Game.h"

#pragma comment( lib, "SDL.lib" )							// Search For SDL.lib While Linking
#pragma comment( lib, "SDLmain.lib" )						// Search For SDLmain.lib Library While Linking
#pragma comment( lib, "SDL_image.lib" )						// Search For SDL_image.lib While Linking
#pragma comment( lib, "SDL_ttf.lib" )						// Search For SDL_ttf.lib Library While Linking
#pragma comment( lib, "opengl32.lib" )						// Search For OpenGL32.lib While Linking
#pragma comment( lib, "glu32.lib" )							// Search For GLu32.lib While Linking
#pragma comment( lib, "winmm.lib" )							// Search For WinMM Library While Linking

int main(int argc, char* args[])
{
	GameObject gameInstance;
	gameInstance.InitOpengl();
	gameInstance.OnExecute();

    return 0;
}