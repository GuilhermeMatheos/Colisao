#include "stdafx.h"
#include "Carro.h"


Carro::Carro(int x, int y, int v, int num_passageiros) : Veiculos(x, y, v)
{
	this->num_passageiros = num_passageiros;
}


Carro::~Carro()
{
}
