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
	// redimensiona console
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1090, 745, TRUE); // 1100 width, 600 height

	// impede que usuario redimensione console
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	// instancia mundo
	Mundo m = Mundo();
	int tamanho_x = m.get_tamanho_x();
	int tamanho_y = m.get_tamanho_y();

	// intancia objetos dinâmicos (heap)
	Carro *car = new Carro(tamanho_x, tamanho_y);
	Caminhao *truck = new Caminhao(tamanho_x, tamanho_y);
	Moto *bike = new Moto(tamanho_x, tamanho_y);

	// loop principal
	while (1)
	{
		m.resetMap();
		m.setVeiculos(car, truck, bike);
		m.printMundo();
		m.movimenta(car, truck, bike);

		Sleep(14);
	}

    return 0;
}