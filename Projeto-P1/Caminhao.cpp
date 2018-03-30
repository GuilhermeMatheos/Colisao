#include "stdafx.h"
#include "Caminhao.h"


Caminhao::Caminhao(int x, int y) : Veiculos(x, y)
{
	capacidade_carga = 2000;
	setVelocidade(1);
	this->capacidade_carga = capacidade_carga;
}


Caminhao::~Caminhao()
{
}
