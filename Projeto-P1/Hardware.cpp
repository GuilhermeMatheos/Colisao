#include "stdafx.h"
#include "Hardware.h"


Hardware::Hardware()
{
}


Hardware::~Hardware()
{
}

void Hardware::init(int x, int y)
{
	/* Modifica parâmetros do prompt de comando (cmd):
	tamanho do ScreenBuffer e da tela */
	COORD coord;
	coord.X = x;
	coord.Y = y;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = x - 1;
	Rect.Right = y - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);

	// impede que usuario redimensione o console
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void Hardware::changeColor(int c)
{
	// determina cor do texto e background no console
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
