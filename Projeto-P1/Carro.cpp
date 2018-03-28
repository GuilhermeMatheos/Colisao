#include "stdafx.h"
#include "Carro.h"


Carro::Carro(int x, int y, int num_passageiros) : Veiculos(x, y, 2)
{
	this->num_passageiros = num_passageiros;
}


Carro::~Carro()
{
}
