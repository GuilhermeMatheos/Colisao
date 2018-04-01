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

	// tamanho tela
	int w = 1090;
	int h = 745;
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, w, h, TRUE); // w width, h height

	// screen buffer
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


void Hardware::setCursorPosition(int x, int y)
{
	/* Determina posição do cursor
	x é coluna, y é linha. A origem (0,0)
	é o canto superior esquerdo.	*/

	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}