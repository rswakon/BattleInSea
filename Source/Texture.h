#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL.h"
#include "SDL_opengl.h"
const int MAX_ASTEROID_TEXTURES		= 10;
const int MAX_SHIP_TEXTURES			= 10;
const int MAX_EXPLOSION_TEXTURES	= 20;
const int MAX_GUI_TEXTURES			= 20;
const int MAX_BG_TEXTURES			= 10;
const int MAX_FONT_TEXTURES			= 10;


class Texture
{
public:
	char filename[1024];
	int id;
	int Width;
	int Height;
	int Tiles;
	int TilesX;
	int TilesY;
	int TileWidth;
	int TileHeight;
	float glTileWidth;
	float glTileHeight;
	GLuint handle;

	Texture()
	{
		sprintf_s(filename, 1024, "none");
		id		= 0;
		Width	= 0;
		Height	= 0;
		Tiles	= 0;
		TilesX	= 0;
		TilesY	= 0;
		TileWidth = 0;
		TileHeight = 0;
		glTileWidth = 0.f;
		glTileHeight = 0.f;
		handle = 0;
	}
};

#endif