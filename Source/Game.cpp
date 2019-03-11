#include "Game.h"




GameObject::GameObject()
{
	// ustawiwnia okna
	game.Variables.ScreenWidth	= 1000;
	game.Variables.ScreenHeight	= 600;	
	game.Variables.MapWidth	= 5000;
	game.Variables.MapHeight	= 3000;
	ScreenBPP		= 32;

	//ScreenFlags		= SDL_FULLSCREEN | SDL_GL_DOUBLEBUFFER | SDL_OPENGL;				//FullScreen
	ScreenFlags		= SDL_HWSURFACE| SDL_RESIZABLE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL;

	// zmienne synchronizacji 
	FramePerSecond	= 60;
	SomeTimeControlVariable = 1000 / FramePerSecond;
	thisTime		= 0;
	lastTime		= 0;
	deltaTime		= 0;
	frameTime		= 0;
	frameStartTime	= 0;
	done = false;								// Zakoncz program na wartosc true
	resize = false;
	SDL_Init(SDL_INIT_EVERYTHING);				// Inicjalizacja SDL

	TTF_Init();
	SDL_WM_SetCaption("Basic SDL/OpenGL Game Egine", NULL);
	SDL_ShowCursor(0);

	screen = SDL_SetVideoMode( game.Variables.ScreenWidth, game.Variables.ScreenHeight, ScreenBPP, ScreenFlags);
	srand ( SDL_GetTicks() );
}

GameObject::~GameObject()
{

	delete gameInput;
	SDL_Quit();
}

void GameObject::OnExecute()
{


	gameInput = new GameEvent();

	while(!done)
	{

		frameStartTime = SDL_GetTicks();		
		OnThink();


		// synchronizacja klatek animacji
		thisTime = SDL_GetTicks();
		frameTime = (thisTime - frameStartTime);
		//delta_time = (time_now - time_prev) / 1000.0f;
		deltaTime = (thisTime - lastTime) / 1000.0f;
		lastTime = thisTime;
		if( frameTime < SomeTimeControlVariable )					// ograniczenie maxFPS
		{
			SDL_Delay( SomeTimeControlVariable - frameTime );
		}
	}

}

void GameObject::OnThink()
{
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
			done = true;
		if(event.type == SDL_VIDEORESIZE )
		{
			game.Variables.ScreenWidth = event.resize.w;
			game.Variables.ScreenHeight = event.resize.h;
			GlResize();
		}		
		if(event.type == SDL_KEYDOWN)
			done = gameInput->KeyboardDown(event);

		if(event.type == SDL_KEYUP)
			done = gameInput->KeyboardUp(event);

		if (event.type == SDL_MOUSEBUTTONDOWN) 
			gameInput->MouseButtonDown(event);

		if (event.type == SDL_MOUSEBUTTONUP) {
			gameInput->MouseButtonUp(event);

		}

		if(event.type == SDL_MOUSEMOTION)
			gameInput->MouseMotion(event);

	}
}


void GameObject::InitOpengl()
{
	// OpenGl starting definition 
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,        8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,      8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,       8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,      8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,      16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,     32);

	SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,		8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,		8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  0);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  0);



	glViewport( 0, 0, game.Variables.ScreenWidth, game.Variables.ScreenHeight );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho( 0, game.Variables.ScreenWidth, game.Variables.ScreenHeight, 0, -1, 1 );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glDisable( GL_DEPTH_TEST );
	glDisable( GL_LIGHTING );
	glDisable( GL_DITHER );

	glBlendFunc( GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );



	glEnable( GL_BLEND );
	glEnable( GL_TEXTURE_2D );		

	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );							// clean screen color with given color
	glColor4f	( 1.0f, 1.0f, 1.0f, 1.0f );							// select drawing color

}

void GameObject::GlResize()
{
	glViewport( 0, 0, game.Variables.ScreenWidth, game.Variables.ScreenHeight );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho( 0, game.Variables.ScreenWidth, game.Variables.ScreenHeight, 0, -1, 1 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();


}