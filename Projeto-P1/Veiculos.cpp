#include "stdafx.h"
#include "Veiculos.h"
#include "Random.h"

Veiculos::Veiculos(int x, int y)
{
	this->x = x;
	this->y = y;
}


Veiculos::~Veiculos()
{
}


void Veiculos::move()
{
	Random r = Random(1, 4);
	int d = r.generate();

	if (d == 1) {
		///move para direita
	}
}
