#include "stdafx.h"
#include "Veiculos.h"
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"
#include "Mundo.h"


Mundo::Mundo()
{
	/*	Cria um mapa padrão com 30 linhas e 60 colunas
		e obstáculos	*/

	tamanho_x = 30;
	tamanho_y = 60;

	setPadrao();
	setObstaculo(3, 3, 3, 4);
}


Mundo::~Mundo()
{
}


void Mundo::setPadrao()
{
	/*	Determina o mundo padrão com 
		bordas (1)	*/

	int i;
	int j;

	// mapa vazio (0)
	for (i = 0; i < tamanho_x; i++)
		for (j = 0; j < tamanho_y; j++)
			mapa[i][j] = 0;

	// bordas (1)
	for (i = 0; i < tamanho_x; i++)
	{
		for (j = 0; j < tamanho_y; j++)
		{
			// primeira linha com 1
			if (i == 0)
				mapa[i][j] = 1;
			// ultima linha com 1
			if (i == (tamanho_x - 1))
				mapa[i][j] = 1;
			// coluna esquerda com 1
			if (j == 0)
				mapa[i][j] = 1;
			// coluna direita com 1
			if (j == (tamanho_y - 1))
				mapa[i][j] = 1;
		}
	}
}

void Mundo::setObstaculo(int x, int y, int w, int h) 
{
	/*	Determina obstáculos (2) 
		Posicao obstáculo = x, y
	    Tamanho dos obstaculos = w, h	*/


	for (int i = 0; i < tamanho_x; i++)
	{
		for (int j = 0; j < tamanho_y; j++)
		{
			// obstáculo 1 na posição x, y com tamanho w1, h1
			if (i == x && j == y)
			{
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 4; l++)
						mapa[i + k][j + l] = 2;
				}
			}
		}
	}
}

void Mundo::setVeiculos(Carro car, Caminhao truck, Moto bike)
{
	mapa[car.getX()][car.getY()] = 3;
	mapa[truck.getX()][truck.getY()] = 4;
	mapa[bike.getX()][bike.getY()] = 5;
}

void Mundo::printMundo()
{
	// desenha o mundo no console

	cout << "     Mundo    \n" << endl;

	for (int i = 0; i < tamanho_x; i++)
	{
		cout << "    ";

		for (int j = 0; j < tamanho_y; j++)
			cout << mapa[i][j] << " ";

		cout << endl;
	}

	cout << endl;
}