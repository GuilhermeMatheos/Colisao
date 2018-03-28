#include "stdafx.h"
#include "Moto.h"


Moto::Moto(int x, int y, string tipo) : Veiculos(x, y, 3)
{
	this->tipo = tipo;
}


Moto::~Moto()
{
}
