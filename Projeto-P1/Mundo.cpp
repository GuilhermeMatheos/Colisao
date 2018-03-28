#include "stdafx.h"
#include "Mundo.h"


Mundo::Mundo()
{
	/* cria um mapa padrão com 30 linhas e 60 colunas
	   e obstáculos */

	tamanho_x = 30;
	tamanho_y = 60;

	desenhaPadrao();
}


Mundo::~Mundo()
{
}


void Mundo::desenhaPadrao()
{
	int i;
	int j;

	// desenha mundo vazio (0)
	for (i = 0; i < tamanho_x; i++)
		for (j = 0; j < tamanho_y; j++)
			mapa[i][j] = 0;

	// desenha bordas (1)
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


void Mundo::printMundo()
{
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