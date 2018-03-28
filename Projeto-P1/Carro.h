#pragma once
#include "Veiculos.h"
class Carro :
	public Veiculos
{
public:
	Carro(int x, int y, int v, int num_passageiros);
	~Carro();
private:
	int num_passageiros;
};

