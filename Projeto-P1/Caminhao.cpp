#include "stdafx.h"
#include "Caminhao.h"


Caminhao::Caminhao(int x, int y, int v, int capacidade_carga) : Veiculos(x, y, v)
{
	this->capacidade_carga = capacidade_carga;
}


Caminhao::~Caminhao()
{
}
