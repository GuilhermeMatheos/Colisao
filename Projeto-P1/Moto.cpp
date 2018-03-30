#include "stdafx.h"
#include "Moto.h"


Moto::Moto(int x, int y) : Veiculos(x, y)
{
	tipo = "corrida";
	setVelocidade(3);
	this->tipo = tipo;
}


Moto::~Moto()
{
}
