#include "stdafx.h"
#include "Moto.h"


Moto::Moto(int x, int y, int v, string tipo) : Veiculos(x, y, v)
{
	this->tipo = tipo;
}


Moto::~Moto()
{
}
