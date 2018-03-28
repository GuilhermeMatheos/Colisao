#include "stdafx.h"
#include "Veiculos.h"
#include "Random.h"


Veiculos::Veiculos(int x, int y)
{
	/* cria o veículo na posicao (x,y)
	   com velocidade nula */
	this->x = x;
	this->y = y;
	v = 0;
}


Veiculos::~Veiculos()
{
}


void Veiculos::setVelocidade(int v)
{
	this->v = v;
}


void Veiculos::move()
{
	/* movimenta o veículo aleatoriamente
	   com velocidade v */

	Random r = Random(1, 4);
	int d = r.generate();

	if (d == 1) 
	{
		x += v;					// move direita
	}
	else if (d == 2) 
	{
		x -= v;					// move esquerda
	} 
	else if (d == 3)
	{
		y += v;					// move cima
	}
	else if (d == 4)
	{
		y -= v;					// move baixo
	}
}
