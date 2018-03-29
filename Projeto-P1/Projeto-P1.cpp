// Projeto-P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Random.h"
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
		//system("color 2");
		system("mode 127, 35");

		Carro car = Carro(15, 3, 4);
		Caminhao truck = Caminhao(5, 2, 2000);
		Moto bike = Moto(8, 2, "corrida");

		m.setVeiculos(car, truck, bike);
		m.printMundo();

		Sleep(60);
	}

    return 0;
}