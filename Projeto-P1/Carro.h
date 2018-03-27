#pragma once
#include "Veiculos.h"
class Carro :
	public Veiculos
{
public:
	Carro(int, int, int, int);
	~Carro();
private:
	int num_passageiros;
};

