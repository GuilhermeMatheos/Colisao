#pragma once
#include "Veiculos.h"
class Caminhao :
	public Veiculos
{
public:
	Caminhao(int x, int y);
	~Caminhao();
private:
	int capacidade_carga;
};

