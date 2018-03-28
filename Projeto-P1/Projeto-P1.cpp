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
	system("mode 127, 35");

	Carro car = Carro(2, 3, 4);
	Caminhao truck = Caminhao(5, 2, 2000);
	Moto bike = Moto(8, 2, "corrida");

	Mundo m = Mundo();
	m.printMundo();
	
	system("pause");
    return 0;
}