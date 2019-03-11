#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "SDL.h"
#include "Entity.h"
#include "Texture.h"
#include "SDL_opengl.h"
#include "Globals.h"
#include <string>
#include <iostream>
#include <list>
#include <sstream>

class GameInterface: public  Entity, Texture
{
	struct Color
	{
		GLfloat r;
		GLfloat g;
		GLfloat b;
		GLfloat a;
	};
	struct RelatedPosition
	{
		bool X;
		bool Y;
		RelatedPosition()
		{
			X = false;
			Y = false;
		}
	};

	struct Button
	{
		VectorI position;
		VectorI size;
		std::string text;
		RelatedPosition relativeScrPos;
		bool hover;
		bool toggle;

		Button()
		{
			position.X = 0;
			position.Y = 0;
			size.X = 10;
			size.Y = 10;
			toggle = false;
			text = "button";
		}
	};
	struct Quad
	{
		VectorI position;
		VectorI size;
		Color color;
		RelatedPosition relativeScrPos;
		RelatedPosition relativeScrSize;
		RelatedPosition relativeMousepos;

		Texture texture;
		bool isTextured;
		bool isRenderable;
		bool isContainer;
		bool isLastChild;
		bool isInteractive;
		VectorF textureCoordinates;

		Quad()
		{
			color.r = 1.0f;
			color.g = 1.0f;
			color.b = 1.0f;
			color.a = 1.0f;
			isTextured = false;
			isRenderable = true;
			isInteractive = false;
			textureCoordinates.X = 1.0f;
			textureCoordinates.Y = 1.0f;
		}
	};

	public:
		GameInterface();
		~GameInterface();



	public:		
		void InitializeFonts(int fontsCount, Texture texture[MAX_GUI_TEXTURES]);
		void InitializeGuis(int guisCount, Texture texture[MAX_GUI_TEXTURES]);
		void RepositionGuis();
		void CreateFontList     (int fontIndex);
		void drawString         (int x, int y, const std::string &text);
		void Render             ();
		void Update(float dt){}
		void RenderButton       ( Button &button );
		void RenderQuad         ( Quad &quad );
		void RenderTexturedQuad ( Quad &quad );
		void TranslateRelative  ( Quad &quad );
		void TranslateRelativeLastPosition (Quad &quad);
		void RenderGuiElement	( Quad &quad );
		void RenderGuiButton	( Quad &quad );
		void RenderCursor		( Quad &quad );
		bool HoverOnMouseMenu	( Quad &quad );
		bool ClickOnButtons     ();
		bool HoverOnButton      ( Button &button );
		void TextBlockAdd       ( std::string text );
		void RenderTextBlock    ();
		virtual void HandleCollision( Entity * entity ){}
private:

	Texture GuiElement	[MAX_GUI_TEXTURES];
	Texture Font		[MAX_FONT_TEXTURES];
	GLuint listIndex;
	int fontsCount;
	int guisCount;
	Button button[10];
	Quad quad[10];
	Quad mouseMenu[10];
	Quad cursor;
	int quadCount;
	int buttonCount;
	int mouseMenuCount;

	std::list <std::string> messageList;
	std::list <std::string>::iterator listIterator; 
	std::stringstream buffer;

};

#endif