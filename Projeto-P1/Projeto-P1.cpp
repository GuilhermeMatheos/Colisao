// Projeto-P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Veiculos.h"
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"
#include "Mundo.h"


int main()
{
	Mundo m = Mundo();

	while (1)
	{

		// redimensiona console
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		MoveWindow(console, r.left, r.top, 1100, 600, TRUE); // 1100 width, 600 height

		// impede que usuario redimensione console
		HWND consoleWindow = GetConsoleWindow();
		SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);	

		Carro car = Carro(15, 3);
		Caminhao truck = Caminhao(5, 2);
		Moto bike = Moto(8, 2);

		m.setVeiculos(car, truck, bike);
		m.printMundo();

		Sleep(500);
	}

    return 0;
}