#pragma once
#include "Veiculos.h"
class Caminhao :
	public Veiculos
{
public:
	Caminhao(int, int, int, int);
	~Caminhao();
private:
	int capacidade_carga;
};

