#pragma once
#include "Veiculos.h"
class Caminhao :
	public Veiculos
{
public:
	Caminhao(int x, int y, int v, int capacidade_carga);
	~Caminhao();
private:
	int capacidade_carga;
};
