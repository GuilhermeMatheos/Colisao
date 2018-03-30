#pragma once
#include "Veiculos.h"
class Moto :
	public Veiculos
{
public:
	Moto(int x, int y);
	~Moto();
private:
	string tipo;
};

