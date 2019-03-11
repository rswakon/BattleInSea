#include "Framework.h"


Framework::Framework()
{

}

Framework::~Framework()
{

}

void Framework::RenderSquare(float pos_x, float pos_y,float size, float rotation /*= 0*/, float scale /*= 1.0f*/, float depth /*= 5.0f*/, float red /*= 0.5f*/, float green /*= 0.5f*/, float blue /*= 0.5f */)
{
	glLoadIdentity();
	glTranslatef(pos_x, pos_y, 0);	
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);	
	glScalef(scale, scale, 1.0f);

	glColor3f(red, green, blue);

	glBegin(GL_QUADS);	
	glVertex3f(-size, -size, depth);		
	glVertex3f( -size, size, depth);		
	glVertex3f( size, size, depth);	
	glVertex3f(size, -size, depth);
	glEnd();
}

void Framework::RenderBox(float pos_x, float pos_y,int TileWidth,int TileHeight, float rotation /*= 0*/, float scale /*= 1.0f*/, float red /*= 0.5f*/, float green /*= 0.5f*/, float blue /*= 0.5f*/,float alpha /*= 0.8f*/)
{
	glDisable(GL_TEXTURE_2D);
	glTranslatef(pos_x, pos_y, 0);	
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);	
	glScalef(scale, scale, 1.0f);   


	glColor4f(red, green,blue,alpha);

	glBegin( GL_LINE_LOOP );	
	glVertex2i( 0, 0 );											//Bottom-left vertex (corner)
	glVertex2i( TileWidth, 0 );							//Bottom-right vertex (corner)
	glVertex2i( TileWidth, TileHeight );		//Top-right vertex (corner)
	glVertex2i( 0, TileHeight );						//Top-left vertex (corner)
	glEnd();

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
}

void Framework::RenderBoundingBox(int TileWidth,int TileHeight, float red /*= 1.0f*/, float green /*= 1.0f*/, float blue /*= 1.0f*/,float alpha /*= 0.8f*/)
{
	glDisable(GL_TEXTURE_2D);		
	glColor4f(red, green,blue,alpha);

	glBegin( GL_LINE_LOOP );	
	glVertex2i( 0, 0 );											//Bottom-left vertex (corner)
	glVertex2i( TileWidth, 0 );							//Bottom-right vertex (corner)
	glVertex2i( TileWidth, TileHeight );		//Top-right vertex (corner)
	glVertex2i( 0, TileHeight );						//Top-left vertex (corner)
	glEnd();

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
}
