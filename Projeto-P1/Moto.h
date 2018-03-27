#pragma once
#include "Veiculos.h"
class Moto :
	public Veiculos
{
public:
	Moto(int, int , int , string);
	~Moto();
private:
	string tipo;
};

