#pragma once
#include "Veiculos.h"
class Moto :
	public Veiculos
{
public:
	Moto(int x, int y, string tipo);
	~Moto();
private:
	string tipo;
};

