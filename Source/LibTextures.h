#ifndef LibTextures_H
#define LibTextures_H
#include "Texture.h"
#include "SDL.h"
#include "SDL_image.h"			// pozwala wszytywaæ tekstury z biblioteki SDL_image
#include "SDL_opengl.h"
#include "Globals.h"
#include "Entity.h"
#include <vector>
using std::vector;

enum EntityType {
	type_Gui, 
	type_Font, 
	type_Other,
	type_Bg,
	type_Logo,
};				
	
	

class LibTextures
{


public:
	Texture  gui[MAX_GUI_TEXTURES];		
	GLuint textureGUI[MAX_GUI_TEXTURES];		
	SDL_Surface* surfaceGUI[MAX_GUI_TEXTURES];		
	EntityType type;
   int count;		//  Textures Count
   Uint32 rmask, gmask, bmask, amask;							// Bit Masks for Texture
		SDL_PixelFormat *fmt;										// Pixel Format]
		SDL_Color *color;											// Color Variable
		GLenum textureFormat;		
								// Texture Format for OpenGL
			char fileName[255];																					// Texture Filename
																				// Textures Groups
		SDL_Surface* SurfaceSDL;																			// SDL Texture Surface
		SDL_Surface* SurfaceGL;																				// Prepared Surface for OpenGL
public:
	Texture AT(int index);
	LibTextures();
	~LibTextures();
   	void Initialize();
		void LoadTextureStructure(EntityType type, char *filename, int tilesX, int tilesY);				// Creates Textures Structure
		void FillStructure(Texture &tmpStruct, int tilesX, int tilesY, int id);								// Creates Textures Structure
		void BuildTexturesHandles();																		// Creates OpenGL Textures Handles
		void BuildTexturesHandle(Texture &tmpStruct, GLuint &textureTmp );									// Prepare OpenGL Handle
		void LoadTextureToGPU(Texture &tempTexture, SDL_Surface* &Surface, bool store);						// Loads Textures to GPU
	char * EnumToStr(EntityType typeEnum);
	int GetPowerOfTwo (int x);	
	
};


#endif