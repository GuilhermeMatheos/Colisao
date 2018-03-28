#include "stdafx.h"
#include "Caminhao.h"


Caminhao::Caminhao(int x, int y, int capacidade_carga) : Veiculos(x, y, 1)
{
	this->capacidade_carga = capacidade_carga;
}


Caminhao::~Caminhao()
{
}
