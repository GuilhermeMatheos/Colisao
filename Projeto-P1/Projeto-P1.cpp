// Projeto-P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Veiculos.h"
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"
#include "Mundo.h"
#include "Hardware.h"


int main()
{
	// console
	Hardware hw = Hardware();
	hw.init();

	// mundo
	Mundo m = Mundo();

	// objetos dinâmicos (heap)
	vector<Carro*> car;
	vector<Caminhao*> truck;
	vector<Moto*> bike;

	// objetos vector
	int max_x = m.get_tamanho_x();
	int max_y = m.get_tamanho_y();

	for (int i = 0; i < 10; i++)
	{
		Carro *c = new Carro(max_x, max_y);
		car.push_back(c);

		Caminhao *t = new Caminhao(max_x, max_y);
		truck.push_back(t);

		Moto *b = new Moto(max_x, max_y);
		bike.push_back(b);
	}
	
	// loop principal
	while (1)
	{
		m.resetMap();
		m.setVeiculos(car, truck, bike);
		m.printMundo(car, truck, bike);
		m.movimenta(car, truck, bike);
		
		Sleep(33);	// 30fps ou 33ms
	}

	// deleta os elementos dos vector

    return 0;
}