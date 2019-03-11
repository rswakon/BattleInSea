#include "LibTextures.h"
char * LibTextures::EnumToStr(EntityType typeEnum)
{
	char * tempEnumStr;
	switch(typeEnum)
	{

	case type_Gui:
		tempEnumStr = "Gui";
		break;
	case type_Bg:
		tempEnumStr = "Background";
		break;
	case type_Font:
		tempEnumStr = "Fonts";
		break;
	case type_Logo:
		tempEnumStr = "Logo";
		break;

	}
	return tempEnumStr;
}



void LibTextures::LoadTextureStructure(EntityType type, char *filename, int tilesX, int tilesY)
{
	this->type = type;
	char buffer[1024];
	if (count<MAX_GUI_TEXTURES)
	{
		sprintf_s(buffer, 1024, "images/%s/%s.png",EnumToStr(type),filename);							// generate path to texture
		strcpy_s(gui[count].filename,1024, buffer);
		FillStructure( gui[count], tilesX, tilesY, count );
		count++;
	} else {	}

}
void LibTextures::BuildTexturesHandles()
{

	float totalprogress = (float)count;
	float progress = 0;
	for(int i = 0; i<count; i++)
	{
		progress++;	printf("loading: %5.2f %% %s ",(progress * 100 / totalprogress),this->gui[i].filename);
		BuildTexturesHandle( gui[i], textureGUI[i] );
		LoadTextureToGPU( gui[i], surfaceGUI[i], false );
		 
	}

}
void LibTextures::BuildTexturesHandle( Texture &tmpStruct, GLuint &textureTmp )
{
	glGenTextures( 1, &textureTmp );
	tmpStruct.handle = textureTmp;
	glBindTexture( GL_TEXTURE_2D, tmpStruct.handle );	// select texture to operate with
}
void LibTextures::FillStructure( Texture &tmpStruct, int tilesX, int tilesY, int id )
{
	tmpStruct.id = id;
	tmpStruct.TilesX = tilesX;
	tmpStruct.TilesY = tilesY;
	tmpStruct.Tiles = tilesX * tilesY;
}

void LibTextures::Initialize()
{

}

LibTextures::LibTextures():count(0)
{

	// texture format information
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	rmask = 0xff000000;
	gmask = 0x00ff0000;
	bmask = 0x0000ff00;
	amask = 0x000000ff;
#else
	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
#endif
	GLenum textureFormat = GL_RGB;

	Initialize();
}
LibTextures::~LibTextures()
{

	glDeleteTextures(count-1,&textureGUI[MAX_GUI_TEXTURES]);

}

Texture LibTextures::AT(int index)
{

	if(index<count)
		return gui[index];
	else
		return  Texture();
}
void LibTextures::LoadTextureToGPU(Texture &tempTexture, SDL_Surface* &Surface, bool store)
{ 

	SurfaceSDL = IMG_Load(tempTexture.filename);									// load texture to SDL surface
	if(!SurfaceSDL)
	{
		SurfaceSDL = IMG_Load("images/Misc/noneTexture.png");	
		printf("Failed - file not found!\n");
	} else
		printf("OK\n");

	SurfaceGL = SDL_CreateRGBSurface(SDL_SWSURFACE,GetPowerOfTwo(SurfaceSDL->w),GetPowerOfTwo(SurfaceSDL->h),32,rmask,gmask,bmask,amask);
	SDL_FillRect(SurfaceGL, NULL, 0x00000000);

	tempTexture.Width		= SurfaceGL->w;
	tempTexture.Height		= SurfaceGL->h;
	tempTexture.TileWidth	= SurfaceSDL->w	/ tempTexture.TilesX;
	tempTexture.TileHeight	= SurfaceSDL->h	/ tempTexture.TilesY;
	tempTexture.glTileWidth	= (float)tempTexture.TileWidth  / tempTexture.Width;	// height of animation frame in OpenGL (in % that is 0 to 1)
	tempTexture.glTileHeight= (float)tempTexture.TileHeight / tempTexture.Height;	// height of animation frame in OpenGL (in % that is 0 to 1)
	SurfaceSDL = SDL_ConvertSurface(SurfaceSDL,  SurfaceGL->format, NULL);
	SDL_SetAlpha(SurfaceSDL , NULL, 0);
	SDL_BlitSurface(SurfaceSDL, NULL, SurfaceGL, NULL);


	if (SurfaceGL->format->BytesPerPixel == 4)  
	{
		if(SurfaceGL->format->Rmask==0x000000ff)
			textureFormat = GL_RGBA;
		else
			textureFormat = GL_BGRA;
	} 
	else
	{
		if(SurfaceGL->format->Rmask==0x000000ff)
			textureFormat=GL_RGB;
		else
			textureFormat=GL_BGR;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, textureFormat, SurfaceGL->w, SurfaceGL->h, 0, textureFormat, GL_UNSIGNED_BYTE, SurfaceGL->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);   //GL_LINEAR  - sposób filtrowania textur
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	 //GL_NEAREST - sposób filtrowania textur

	if (store)
		Surface = SDL_ConvertSurface(SurfaceGL, SurfaceGL->format, SurfaceGL->flags);

	SDL_FreeSurface(SurfaceGL);
	SDL_FreeSurface(SurfaceSDL);	

}

int LibTextures::GetPowerOfTwo (int x = 2) { 
	int y = 0;
	double z = 2;
	for (int i = 0; i <= 10; i++)
	{
		if ( x> pow(z,i) && x <= pow(z,(i+1)) ) 
			return y = (int)pow(z,(i+1));
	}
	return y = 2048;
}