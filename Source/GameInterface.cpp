#include "GameInterface.h"


GameInterface::GameInterface():Entity()
{
	quadCount = 0;
	buttonCount = 0;
	mouseMenuCount = 0;
}

GameInterface::~GameInterface()
{
	glDeleteLists(1,256*fontsCount);
}
void GameInterface::InitializeGuis(int guisCount, Texture texture[MAX_GUI_TEXTURES])
{

	this->guisCount = guisCount;
	for (int i = 0; i<guisCount; i++)
	{	
		this->GuiElement[i] = texture[i];
	}

	// this should be loaded from xml File
	//buttons
	button[0].position.X = game.Variables.ScreenWidth - 40;
	button[0].position.Y = 5;
	button[0].relativeScrPos.X = true;
	button[0].size.X = 35;
	button[0].size.Y = 27;
	button[0].text = "B1";

	button[1].position.X = game.Variables.ScreenWidth - 80;
	button[1].position.Y = 5;
	button[1].relativeScrPos.X = true;
	button[1].size.X = 35;
	button[1].size.Y = 27;
	button[1].text = "B2";

	button[2].position.X = game.Variables.ScreenWidth - 120;
	button[2].position.Y = 5;
	button[2].relativeScrPos.X = true;
	button[2].size.X = 35;
	button[2].size.Y = 27;
	button[2].text = "B3";

	button[3].position.X = game.Variables.ScreenWidth - 160;
	button[3].position.Y = 5;
	button[3].relativeScrPos.X = true;
	button[3].size.X = 35;
	button[3].size.Y = 27;
	button[3].text = "B4";
	buttonCount = 4;

	// cursor
	cursor.position.X = - (GuiElement[4].TileHeight/2);
	cursor.position.Y = - (GuiElement[4].TileWidth/2);
	cursor.size.X = GuiElement[4].Height;
	cursor.size.Y = GuiElement[4].Width;
	cursor.relativeMousepos.X = true;
	cursor.relativeMousepos.Y = true;
	cursor.isTextured = true;
	cursor.texture = GuiElement[4];

	// top bar
	quad[0].position.X = 0;
	quad[0].position.Y = 0;
	quad[0].size.X = game.Variables.ScreenWidth;
	quad[0].size.Y = 40;
	quad[0].relativeScrSize.X = true;
	quad[0].color.r = 0.2f;
	quad[0].color.g = 0.2f;
	quad[0].color.b = 0.2f;
	quad[0].color.a = 1.0f;
	quadCount++;

	quad[1].position.X = game.Variables.ScreenWidth - 190;
	quad[1].position.Y = game.Variables.ScreenHeight - 300;
	quad[1].relativeScrPos.X = true;
	quad[1].relativeScrPos.Y = true;
	quad[1].size.X = 180;
	quad[1].size.Y = 290;
	quad[1].color.r = 0.0f;
	quad[1].color.g = 0.0f;
	quad[1].color.b = 0.0f;
	quad[1].color.a = 0.5f;
	quadCount++;

	quad[2].position.X = game.Variables.ScreenWidth - 190;
	quad[2].position.Y = game.Variables.ScreenHeight - 300;
	quad[2].relativeScrPos.X = true;
	quad[2].relativeScrPos.Y = true;
	quad[2].size.X = 180;
	quad[2].size.Y = 290;
	quad[2].color.a = 0.1f;
	quad[2].isTextured = true;
	quad[2].texture = GuiElement[0];
	quad[2].textureCoordinates.X = (float)quad[2].size.X / quad[2].texture.Width;
	quad[2].textureCoordinates.Y = (float)quad[2].size.Y / quad[2].texture.Height;
	quadCount++;

	// pos x,y
	quad[3].position.X = 10;
	quad[3].position.Y = 10;
	quad[3].size.X = 80;
	quad[3].size.Y = 29;
	quad[3].relativeMousepos.X = true;
	quad[3].relativeMousepos.Y = true;
	quad[3].color.a = 0.5f;
	quad[3].color.r = 1.0f;
	quad[3].color.g = .0f;
	quad[3].color.b = .0f;

	// menu button
	mouseMenu[0].position.X = -32;
	mouseMenu[0].position.Y = -28;
	mouseMenu[0].size.X = 64;
	mouseMenu[0].size.Y = 55;
	mouseMenu[0].isTextured = true;
	mouseMenu[0].texture = GuiElement[5];
	mouseMenu[0].relativeMousepos.X = true;
	mouseMenu[0].relativeMousepos.Y = true;
	mouseMenu[0].textureCoordinates.X = (float)mouseMenu[0].size.X / mouseMenu[0].texture.Width;
	mouseMenu[0].textureCoordinates.Y = (float)mouseMenu[0].size.Y / mouseMenu[0].texture.Height;
	mouseMenuCount++;

	mouseMenu[1].position.X = -82;
	mouseMenu[1].position.Y = -56;
	mouseMenu[1].size.X = 64;
	mouseMenu[1].size.Y = 55;
	mouseMenu[1].isTextured = true;
	mouseMenu[1].isInteractive = true;
	mouseMenu[1].texture = GuiElement[6];
	mouseMenu[1].relativeMousepos.X = true;
	mouseMenu[1].relativeMousepos.Y = true;
	mouseMenu[1].textureCoordinates.X = (float)mouseMenu[1].size.X / mouseMenu[1].texture.Width;
	mouseMenu[1].textureCoordinates.Y = (float)mouseMenu[1].size.Y / mouseMenu[1].texture.Height;
	mouseMenuCount++;

	mouseMenu[2].position.X = -32;
	mouseMenu[2].position.Y = -84;
	mouseMenu[2].size.X = 64;
	mouseMenu[2].size.Y = 55;
	mouseMenu[2].isTextured = true;
	mouseMenu[2].isInteractive = true;
	mouseMenu[2].texture = GuiElement[7];
	mouseMenu[2].relativeMousepos.X = true;
	mouseMenu[2].relativeMousepos.Y = true;
	mouseMenu[2].textureCoordinates.X = (float)mouseMenu[2].size.X / mouseMenu[2].texture.Width;
	mouseMenu[2].textureCoordinates.Y = (float)mouseMenu[2].size.Y / mouseMenu[2].texture.Height;
	mouseMenuCount++;

	mouseMenu[3].position.X = 18;
	mouseMenu[3].position.Y = -56;
	mouseMenu[3].size.X = 64;
	mouseMenu[3].size.Y = 55;
	mouseMenu[3].isTextured = true;
	mouseMenu[3].isInteractive = true;
	mouseMenu[3].texture = GuiElement[8];
	mouseMenu[3].relativeMousepos.X = true;
	mouseMenu[3].relativeMousepos.Y = true;
	mouseMenu[3].textureCoordinates.X = (float)mouseMenu[3].size.X / mouseMenu[3].texture.Width;
	mouseMenu[3].textureCoordinates.Y = (float)mouseMenu[3].size.Y / mouseMenu[3].texture.Height;
	mouseMenuCount++;

	mouseMenu[4].position.X = 18;
	mouseMenu[4].position.Y = 0;
	mouseMenu[4].size.X = 64;
	mouseMenu[4].size.Y = 55;
	mouseMenu[4].isTextured = true;
	mouseMenu[4].isInteractive = true;
	mouseMenu[4].texture = GuiElement[9];
	mouseMenu[4].relativeMousepos.X = true;
	mouseMenu[4].relativeMousepos.Y = true;
	mouseMenu[4].textureCoordinates.X = (float)mouseMenu[4].size.X / mouseMenu[4].texture.Width;
	mouseMenu[4].textureCoordinates.Y = (float)mouseMenu[4].size.Y / mouseMenu[4].texture.Height;
	mouseMenuCount++;

	mouseMenu[5].position.X = -32;
	mouseMenu[5].position.Y = 28;
	mouseMenu[5].size.X = 64;
	mouseMenu[5].size.Y = 55;
	mouseMenu[5].isTextured = true;
	mouseMenu[5].isInteractive = true;
	mouseMenu[5].texture = GuiElement[10];
	mouseMenu[5].relativeMousepos.X = true;
	mouseMenu[5].relativeMousepos.Y = true;
	mouseMenu[5].textureCoordinates.X = (float)mouseMenu[5].size.X / mouseMenu[5].texture.Width;
	mouseMenu[5].textureCoordinates.Y = (float)mouseMenu[5].size.Y / mouseMenu[5].texture.Height;
	mouseMenuCount++;

	mouseMenu[6].position.X = - 82;
	mouseMenu[6].position.Y = 0;
	mouseMenu[6].size.X = 64;
	mouseMenu[6].size.Y = 55;
	mouseMenu[6].isTextured = true;
	mouseMenu[6].isInteractive = true;
	mouseMenu[6].texture = GuiElement[11];
	mouseMenu[6].relativeMousepos.X = true;
	mouseMenu[6].relativeMousepos.Y = true;
	mouseMenu[6].textureCoordinates.X = (float)mouseMenu[6].size.X / mouseMenu[6].texture.Width;
	mouseMenu[6].textureCoordinates.Y = (float)mouseMenu[6].size.Y / mouseMenu[6].texture.Height;
	mouseMenuCount++;

}

void GameInterface::RepositionGuis()
{

	button[0].position.X = game.Variables.ScreenWidth- 40;
	button[1].position.X = game.Variables.ScreenWidth- 80;
	button[2].position.X = game.Variables.ScreenWidth- 120;
	button[3].position.X = game.Variables.ScreenWidth- 160;

	quad[0].size.X = game.Variables.ScreenWidth;
	quad[0].size.Y = 40;

	quad[1].position.X = game.Variables.ScreenWidth - 190;
	quad[1].position.Y = game.Variables.ScreenHeight - 300;

	quad[2].position.X = game.Variables.ScreenWidth - 190;
	quad[2].position.Y = game.Variables.ScreenHeight - 300;

}

void GameInterface::InitializeFonts( int fontsCount, Texture texture[MAX_FONT_TEXTURES] )
{
	this->fontsCount = fontsCount;
	for (int i = 0; i<fontsCount; i++)
	{	
		this->Font[i] = texture[i];
		CreateFontList(i);
	}
}

void GameInterface::Render()
{

	for ( int i=0; i<quadCount; i++ )
		RenderGuiElement( quad[i] );

	for ( int i=0; i<buttonCount; i++ )
		RenderButton( button[i] );
	
	drawString(10,10,"Basic Game Interface");	
	RenderTextBlock();

	if(game.Flags.mouseMenu)
	{
		for ( int i=0; i<mouseMenuCount; i++ )
			RenderGuiElement( mouseMenu[i] );
	}
	else
	{
		buffer << game.Variables.cursorX;
		drawString( game.Variables.cursorX + 10, game.Variables.cursorY + 10, "X: " +buffer.str());	buffer.str("");
		buffer << game.Variables.cursorY;
		drawString( game.Variables.cursorX + 10, game.Variables.cursorY + 23, "Y: " + buffer.str());	buffer.str("");
	}
	RenderCursor( cursor );

}

void GameInterface::drawString(int x, int y, const std::string &text)
{
	glPushMatrix(); 
		glBindTexture(GL_TEXTURE_2D,Font[game.Flags.currentFont].handle);
		glTranslatef(static_cast<GLfloat>(x),static_cast<GLfloat>(y),0.0f);

		glListBase(game.Flags.currentFont*256);
		glCallLists(static_cast<GLsizei>(text.length()),GL_UNSIGNED_BYTE,text.c_str());
	glPopMatrix();
}

void GameInterface::RenderButton( Button &button )
{

	glDisable(GL_TEXTURE_2D);
	
	if( HoverOnButton(button) )
		glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	else
		if (button.toggle)
			glColor4f(0.3f, 0.7f, 0.3f, 1.0f);
		else
			glColor4f(0.7f, 0.3f, 0.3f, 1.0f);

	glPushMatrix(); 
		glTranslated ( button.position.X, button.position.Y, 0.0f);

		glBegin( GL_QUADS );	
			glVertex2i( 0, 0 );																//Bottom-left vertex (corner)
			glVertex2i( button.size.X , 0 );												//Bottom-right vertex (corner)
			glVertex2i( button.size.X, button.size.Y );										//Top-right vertex (corner)
			glVertex2i( 0, button.size.Y);													//Top-left vertex (corner)
		glEnd();

		glColor4f(0.7f, 0.7f, 0.7f, 1.0f);

		glBegin( GL_LINE_LOOP );	
			glVertex2i( 0, 0 );																//Bottom-left vertex (corner)
			glVertex2i( button.size.X , 0 );												//Bottom-right vertex (corner)
			glVertex2i( button.size.X, button.size.Y );										//Top-right vertex (corner)
			glVertex2i( 0, button.size.Y);													//Top-left vertex (corner)
		glEnd();

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);

	drawString(5, 5, button.text);

	glPopMatrix();
}

void GameInterface::RenderQuad( Quad &quad )
{
	glDisable(GL_TEXTURE_2D);
	glBegin( GL_QUADS );	
		glVertex2i( 0, 0 );															//Bottom-left vertex (corner)
		glVertex2i( quad.size.X, 0 );												//Bottom-right vertex (corner)
		glVertex2i( quad.size.X, quad.size.Y );										//Top-right vertex (corner)
		glVertex2i( 0, quad.size.Y);												//Top-left vertex (corner)
	glEnd();

	glColor4f(0.7f, 0.7f, 0.7f, 1.0f);

	glBegin( GL_LINE_LOOP );	
		glVertex2i( 0, 0 );															//Bottom-left vertex (corner)
		glVertex2i( quad.size.X , 0 );												//Bottom-right vertex (corner)
		glVertex2i( quad.size.X, quad.size.Y );										//Top-right vertex (corner)
		glVertex2i( 0, quad.size.Y);												//Top-left vertex (corner)
	glEnd();
	glEnable(GL_TEXTURE_2D);	
}

void GameInterface::RenderTexturedQuad( Quad &quad )
{
	glBindTexture(GL_TEXTURE_2D,quad.texture.handle);
	glBegin( GL_QUADS );	
		glTexCoord2d(	0, 0 );
			glVertex2i( 0, 0 );																		//Bottom-left vertex (corner)
		glTexCoord2d(	quad.textureCoordinates.X, 0 );
			glVertex2i( quad.size.X, 0 );															//Bottom-right vertex (corner)
 		glTexCoord2d(	quad.textureCoordinates.X, quad.textureCoordinates.Y);
			glVertex2i( quad.size.X, quad.size.Y );													//Top-right vertex (corner)
 		glTexCoord2d(	0, quad.textureCoordinates.Y );
			glVertex2i( 0, quad.size.Y);															//Top-left vertex (corner)
	glEnd();	
}

void GameInterface::TranslateRelative(Quad &quad)
{
	glTranslated( (quad.relativeMousepos.X * game.Variables.cursorX) + quad.position.X, (quad.relativeMousepos.Y * game.Variables.cursorY) + quad.position.Y, 0.0f);
}

void GameInterface::TranslateRelativeLastPosition(Quad &quad)
{
	glTranslated( (quad.relativeMousepos.X * game.Variables.cursorPrevX) + quad.position.X, (quad.relativeMousepos.Y * game.Variables.cursorPrevY) + quad.position.Y, 0.0f);
}

void GameInterface::RenderGuiElement( Quad &quad )
{
	if (quad.isTextured)
	{	
		glPushMatrix();

		if ( HoverOnMouseMenu( quad ) && quad.isInteractive )
			glColor4f( 1.0f, 1.0f, 1.0f, 0.8f );
		else
			glColor4f( quad.color.r, quad.color.g, quad.color.b, quad.color.a );

		if ( game.Flags.mouseMenu )
			TranslateRelativeLastPosition( quad );
		else 
			TranslateRelative( quad );

		RenderTexturedQuad( quad );
		glPopMatrix();			
	}
	else
	{
		glPushMatrix();
		TranslateRelative(quad);
			glColor4f( quad.color.r,quad.color.g, quad.color.b, quad.color.a );
			RenderQuad( quad );	
		glPopMatrix();	
	}
	glColor4f( 1.0f, 1.0f, 1.0f, 1.0f );
}

void GameInterface::RenderGuiButton( Quad &quad )
{

}
void GameInterface::RenderCursor( Quad &quad )
{
	glPushMatrix();
		TranslateRelative( quad );
		RenderTexturedQuad( quad );
	glPopMatrix();	
}

bool GameInterface::HoverOnButton(Button &button)
{
	if (game.Variables.cursorX >= button.position.X && 
		game.Variables.cursorX <= (button.position.X+button.size.X) &&
		game.Variables.cursorY >= button.position.Y && 
		game.Variables.cursorY <= (button.position.Y+button.size.Y))
		return true;
	else
		return false;
}
bool GameInterface::HoverOnMouseMenu(Quad &quad)
{
	if (game.Variables.cursorX >= (game.Variables.cursorPrevX + quad.position.X) && 
		game.Variables.cursorX <= (game.Variables.cursorPrevX + quad.position.X + quad.size.X) &&
		game.Variables.cursorY >= (game.Variables.cursorPrevY + quad.position.Y) && 
		game.Variables.cursorY <= (game.Variables.cursorPrevY + quad.position.Y + quad.size.Y))
		return true;
	else
		return false;
}
bool GameInterface::ClickOnButtons()
{
	for (int i=0; i<buttonCount; i++){
	if (game.Variables.cursorX >= button[i].position.X && 
		game.Variables.cursorX <= (button[i].position.X+button[i].size.X) &&
		game.Variables.cursorY >= button[i].position.Y && 
		game.Variables.cursorY <= (button[i].position.Y+button[i].size.Y))
		{
			button[i].toggle = !button[i].toggle;
			game.Flags.inertiaMode = i;

			buffer << button[i].toggle;
			TextBlockAdd( "button " +  button[i].text + " : " + buffer.str()  );
			buffer.str("");
			return true;
		}
	}
	return false;
}
void GameInterface::TextBlockAdd( std::string text )
{
	if (messageList.size()>20 )
		 messageList.pop_front();
	messageList.insert(messageList.end(), text);
}
void GameInterface::RenderTextBlock()
{
	int i = 0;
	//std::cout.precision(0);
	for ( listIterator =  messageList.begin(); listIterator != messageList.end(); ++listIterator)
	{
		drawString( game.Variables.ScreenWidth - 185, game.Variables.ScreenHeight - 295 + i*13, *listIterator );
		i++;
	}
}


void GameInterface::CreateFontList(int fontIndex)
{
	float cx;
	float cy;

	listIndex = glGenLists (256);
	glPushMatrix();	
	for(int i = (256*fontIndex); i<(256 + (256)*fontIndex); i++)
	{
		cx = float(i%16)/16.0f;
		cy = float(i/16)/16.0f;
		
		glNewList(i,GL_COMPILE);

			glBegin(GL_QUADS);
				glTexCoord2f(cx,cy+0.0625f);
				glVertex2i(0,Font[fontIndex].TileHeight);
				glTexCoord2f(cx+0.0625f,cy+0.0625f);
				glVertex2i(Font[fontIndex].TileWidth,Font[fontIndex].TileHeight);
				glTexCoord2f(cx+0.0625f,cy);
				glVertex2i(Font[fontIndex].TileWidth,0);
				glTexCoord2f(cx,cy);
				glVertex2i(0,0);
			glEnd();

			glTranslated(Font[fontIndex].TileWidth-(int)(2*Font[fontIndex].TileWidth/5),0,0);
		glEndList();
	}
	glPopMatrix();
}