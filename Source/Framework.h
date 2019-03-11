#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include "SDL.h"				// pozwala urzywaæ SDL
#include "Texture.h"			// struktura textury
#include "SDL_opengl.h"			// pozwala urzywaæ OpenGL
#include "Globals.h"

 class Framework
{
public:
	Framework();
	~Framework();
public:
	 void RenderSquare( float pos_x, float pos_y,float size, float rotation = 0, float scale = 1.0f, float depth = 5.0f, float red = 0.5f, float green = 0.5f, float blue = 0.5f );
	 
	 void RenderBox( float pos_x, float pos_y,int TileWidth,int TileHeight, float rotation = 0, float scale = 1.0f, float red = 0.5f, float green = 0.5f, float blue = 0.5f,float alpha =  0.8f);

	  void RenderBoundingBox(int TileWidth,int TileHeight, float red = 1.0f, float green = 1.0f, float blue = 1.0f,float alpha =  0.8f);

};
#endif

