#ifndef LOADER_H
#define LOADER_H

#include "math.h" 
#include "Texture.h"
#include "LibTextures.h"
#include "SDL.h"
#include "SDL_image.h"			// pozwala wszytywaæ tekstury z biblioteki SDL_image
#include "SDL_opengl.h"
#include "Globals.h"

class Loader
{
	public:
		Loader();
		~Loader();
	
	public:
		
		LibTextures * logoTexture;
		LibTextures * fontTexture;
		LibTextures * guiTexture;
		LibTextures * backgroundTexture;
		LibTextures * bomberTexture;
		LibTextures * asteroidTexture;
		LibTextures * explosionTexture;
		LibTextures * shipTexture;
		LibTextures * planeTexture;
		LibTextures * cannonTexture;

	

	public:
		void Initialize();
		void BuildTexturesHandles();	
	
		void RenderLoadingScreen( float progress );															// Render Texture Loading Screen
	
	private:
		Texture texture;
	

};

#endif