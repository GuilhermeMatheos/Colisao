#include "stdafx.h"
#include "Veiculos.h"
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"
#include "Mundo.h"

#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15


Mundo::Mundo()
{
	/*	Cria um mapa padrão com 30 linhas e 60 colunas
		e obstáculos	*/

	tamanho_x = 30;
	tamanho_y = 60;
	setMundo();
}


Mundo::~Mundo()
{
}


void Mundo::setMundo()
{
	/*	Determina o mundo padrão com 
		bordas (1)	*/

	int i;
	int j;

	// mapa vazio (0)
	for (i = 0; i < tamanho_x; i++)
		for (j = 0; j < tamanho_y; j++)
			mapa[i][j] = '0';

	// bordas (1)
	for (i = 0; i < tamanho_x; i++)
	{
		for (j = 0; j < tamanho_y; j++)
		{
			if (i == 0)								// primeira linha
				mapa[i][j] = '1';					
			if (i == (tamanho_x - 1))				// ultima linha
				mapa[i][j] = '1';
			if (j == 0)								// coluna esquerda
				mapa[i][j] = '1';
			if (j == (tamanho_y - 1))				// coluna direita
				mapa[i][j] = '1';
		}
	}

	// obstáculos (2)
	setObstaculo(3, 3, 3, 4);
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
						mapa[i + k][j + l] = '2';
				}
			}
		}
	}
}


void Mundo::setCursorPosition(int x, int y)
{
	/* Determina posição do cursor 
	   x é coluna, y é linha. A origem (0,0) 
	   é o canto superior esquerdo.	*/
	
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}


void Mundo::setVeiculos(Carro car, Caminhao truck, Moto bike)
{
	// Determina posição dos veículos

	if ((car.getX() >= 0 && car.getX() <= tamanho_x) &&
		(car.getY() >= 0 && car.getY() <= tamanho_y))
	{
		mapa[car.getX()][car.getY()] = '%';
	}
	
	if ((truck.getX() >= 0 && truck.getX() <= tamanho_x) &&
		(truck.getY() >= 0 && truck.getY() <= tamanho_y))
	{
		mapa[truck.getX()][truck.getY()] = '@';
	}

	if ((bike.getX() >= 0 && bike.getX() <= tamanho_x) &&
		(bike.getY() >= 0 && bike.getY() <= tamanho_y))
	{
		mapa[bike.getX()][bike.getY()] = '*';
	}
}


void Mundo::printMundo()
{
	// desenha o mundo no console

	cout << "     Mundo    \n" << endl;

	for (int i = 0; i < tamanho_x; i++)
	{
		cout << "    ";

		for (int j = 0; j < tamanho_y; j++) 
		{
			if (mapa[i][j] == '0')
			{
				// determina cor do texto no console, e imprime char
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
				cout << mapa[i][j] << " ";
			}
			else if (mapa[i][j] == '2')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << mapa[i][j] << " ";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARKGRAY);
				cout << mapa[i][j] << " ";
			}
		}
		cout << endl;
	}

	// retorna cursor para poisção inicial
	setCursorPosition(0, 0);
}