/*--------------------------  COMPILER DEFINES  ----------------------------*/
#ifndef __GLOBALS_H__
#define __GLOBALS_H__




struct SystemFlags
{
	int currentFont;
	bool mouseMenu;
	int inertiaMode;

	SystemFlags()
	{
		currentFont = 2;
		mouseMenu = false;
		inertiaMode = 0;
	}
};

struct SystemVariables
{
	int cursorX;
	int cursorY;
	int cursorPrevX;
	int cursorPrevY;
	int ScreenWidth;
	int ScreenHeight;
	int MapHeight;
	int MapWidth;

	SystemVariables()
	{
		cursorX			= 0;
		cursorY			= 0;
		cursorPrevX		= 0;
		cursorPrevY		= 0;
		ScreenWidth		= 0;
		ScreenHeight	= 0;
		MapHeight		=0;
		MapWidth		=0;
	}
};

struct SystemStates
{
	int X;

	SystemStates()
	{
		X = 0;
	}
};

struct SystemKeys
{
	bool key_1;
	bool key_2;

	bool key_F1;
	bool key_F2;
	bool key_F3;
	bool key_F4;

	bool key_Left;
	bool key_Right;
	bool key_Up;
	bool key_Down;
	bool key_plus;
	bool key_minus;

	SystemKeys()
	{
		key_1		= false;
		key_2		= false;

		key_F1		= false;
		key_F2		= false;
		key_F3		= false;
		key_F4		= false;

		key_Left	= false;
		key_Right	= false;
		key_Up		= false;
		key_Down	= false;
		key_plus	= false;
		key_minus	= false;
	}
};

struct Game
{
	SystemFlags Flags;
	SystemVariables Variables;
	SystemStates States;
	SystemKeys Keys;
};
extern Game game;


const  float PI = 3.1415926535898f;     // PI
const float OneRadian = 180.0f / PI;   // one radian
// Returns _degrees converted from degrees <0...360> to radians.


#endif // __GLOBALS_H__