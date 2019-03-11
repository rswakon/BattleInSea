#include "Loader.h"

Loader::Loader()
{
	logoTexture = new LibTextures();
	fontTexture  = new LibTextures();
	guiTexture   = new LibTextures();
	backgroundTexture = new LibTextures();

	Initialize();
}
Loader::~Loader()
{
	delete logoTexture;

	delete fontTexture;
	delete	guiTexture ;
	delete	backgroundTexture;

}
void Loader::Initialize()
{

	// Game logo for startup loader
	logoTexture->LoadTextureStructure(type_Logo, "battleInSea-logo1", 1, 1);
	logoTexture->BuildTexturesHandles();
	texture= logoTexture->AT(0);

	// create gui textures structure
	guiTexture->LoadTextureStructure(type_Gui, "texture", 1, 1); 
	guiTexture->LoadTextureStructure(type_Gui, "Large_arrow1", 1, 1);
	guiTexture->LoadTextureStructure(type_Gui, "Large_arrow2", 1, 1);
	guiTexture->LoadTextureStructure(type_Gui, "arrow1", 1, 1);
	guiTexture->LoadTextureStructure(type_Gui, "arrow2", 1, 1);

	guiTexture->LoadTextureStructure(type_Gui, "MouseMenu1", 1, 1); 
	guiTexture->LoadTextureStructure(type_Gui, "MouseMenuComs", 1, 1); 
	guiTexture->LoadTextureStructure(type_Gui, "MouseMenuCrew", 1, 1); 
	guiTexture->LoadTextureStructure(type_Gui, "MouseMenuEngineering", 1, 1); 
	guiTexture->LoadTextureStructure(type_Gui, "MouseMenuRelay", 1, 1);
	guiTexture->LoadTextureStructure(type_Gui, "MouseMenuRelay2", 1, 1);
	guiTexture->LoadTextureStructure(type_Gui, "MouseMenuScaners", 1, 1);
	guiTexture->LoadTextureStructure(type_Gui, "MouseMenuShields", 1, 1);
	guiTexture->LoadTextureStructure(type_Gui, "MouseMenuSystems", 1, 1);
	guiTexture->LoadTextureStructure(type_Gui, "MouseMenuWeapons", 1, 1);

	// create background structure
	backgroundTexture->LoadTextureStructure(type_Bg, "background1", 1, 1); 


	// create font
	fontTexture->LoadTextureStructure(type_Font, "font1", 16, 16); 
	fontTexture->LoadTextureStructure(type_Font, "font2", 16, 16); 
	fontTexture->LoadTextureStructure(type_Font, "font3", 16, 16); 
	// create ships textures structure

	// load textures to memory 
	BuildTexturesHandles();
}

void Loader::BuildTexturesHandles()
{


	float totalprogress = (float)fontTexture->count+guiTexture->count+backgroundTexture->count+bomberTexture->count+asteroidTexture->count+explosionTexture->count+shipTexture->count+planeTexture->count+cannonTexture->count;
	float progress = 0;
	progress+=fontTexture->count;
	fontTexture->BuildTexturesHandles();
	RenderLoadingScreen( progress * 100 / totalprogress );

	progress+=guiTexture->count;
	guiTexture->BuildTexturesHandles();
	RenderLoadingScreen( progress * 100 / totalprogress );

	progress+=backgroundTexture->count;
	backgroundTexture->BuildTexturesHandles();
	RenderLoadingScreen( progress * 100 / totalprogress );


}


void Loader::RenderLoadingScreen( float progress )
{
	glPushMatrix(); 	

	glBindTexture( GL_TEXTURE_2D, texture.handle );
	glTranslated(game.Variables.ScreenWidth/2 - texture.TileWidth/2, game.Variables.ScreenHeight/2 - texture.TileHeight/2, 0.0f); 
	glBegin( GL_QUADS );	
	glTexCoord2f( 0, 0 );
	glVertex2i( 0, 0 );																	//Bottom-left vertex (corner)
	glTexCoord2f( texture.glTileWidth, 0 );
	glVertex2i( texture.TileWidth, 0 );														//Bottom-right vertex (corner)
	glTexCoord2f( texture.glTileWidth, texture.glTileHeight );
	glVertex2i( texture.TileWidth, texture.TileHeight);										//Top-right vertex (corner)
	glTexCoord2f( 0, texture.glTileHeight );
	glVertex2i( 0, texture.TileHeight );													//Top-left vertex (corner)
	glEnd();
	glPopMatrix();
	glPushMatrix(); 

	glTranslated(game.Variables.ScreenWidth/2 - 250, game.Variables.ScreenHeight/2 + texture.TileHeight/2, 0.0f);	
	glDisable(GL_TEXTURE_2D);
	glColor4f(0.3f, 0.3f, 0.3f, 0.8f);

	glBegin( GL_QUADS );	
	glVertex2i( -1, 0 );																		//Bottom-left vertex (corner)
	glVertex2i( 501, 0 );																	//Bottom-right vertex (corner)
	glVertex2i( 501, 10 );																	//Top-right vertex (corner)
	glVertex2i( -1, 10 );																	//Top-left vertex (corner)
	glEnd();

	glColor4f(1-progress/100, progress/100, 0.f, 1.0f);
	glBegin( GL_QUADS );	
	glVertex2i( 1, 1 );						
	glVertex2i( (int)progress*5, 1 );																	
	glVertex2i( (int)progress*5, 9 );	
	glVertex2i( 1, 9 );
	glEnd();

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);

	glPopMatrix();
	SDL_GL_SwapBuffers();
}


