#include "stdafx.h"
#include "Carro.h"


Carro::Carro(int x, int y) : Veiculos(x, y)
{
	num_passageiros = 4;
	setVelocidade(2);
	this->num_passageiros = num_passageiros;
}


Carro::~Carro()
{
}
