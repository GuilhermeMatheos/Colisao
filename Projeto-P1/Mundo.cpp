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
	/*	Cria um mapa padr�o com 40 linhas e 120 colunas
		e obst�culos	*/

	tamanho_x = 40;
	tamanho_y = 120;
	setMundo();
}


Mundo::~Mundo()
{
}


int Mundo::get_tamanho_x()
{
	// retorma tamanho x sem incluir a borda
	return tamanho_x-2;
}


int Mundo::get_tamanho_y()
{
	// retorma tamanho y sem incluir a borda
	return tamanho_y-2;
}


void Mundo::resetMap()
{
	// reseta o mundo

	for (int i = 0; i < tamanho_x; i++)
	{
		for (int j = 0; j < tamanho_y; j++)
		{
			map[i][j] = defaultMap[i][j];
		}
	}
}


void Mundo::setVeiculos(Carro *car, Caminhao *truck, Moto *bike)
{
	// Determina posi��o dos ve�culos

	if ((car->getX() >= 0 && car->getX() <= get_tamanho_x()) &&
		(car->getY() >= 0 && car->getY() <= get_tamanho_y()))
	{
		map[car->getX()][car->getY()] = '%';
	}

	if ((truck->getX() >= 0 && truck->getX() <= get_tamanho_x()) &&
		(truck->getY() >= 0 && truck->getY() <= get_tamanho_y()))
	{
		map[truck->getX()][truck->getY()] = '@';
	}

	if ((bike->getX() >= 0 && bike->getX() <= get_tamanho_x()) &&
		(bike->getY() >= 0 && bike->getY() <= get_tamanho_y()))
	{
		map[bike->getX()][bike->getY()] = '+';
	}
}


void Mundo::movimenta(Carro *car, Caminhao *truck, Moto *bike)
{
	car->move();
	truck->move();
	bike->move();


	// carro
	if (car->getX() <= 0)
	{
		car->setX(get_tamanho_x());
	}
	else if (car->getX() >= get_tamanho_x())
	{
		car->setX(1);
	}

	if (car->getY() >= get_tamanho_y())
	{
		car->setY(get_tamanho_y());
	}
	else if (car->getY() >= get_tamanho_y())
	{
		car->setY(1);
	}

	// caminh�o
	if (truck->getX() <= 0)
	{
		truck->setX(get_tamanho_x());
	}
	else if (truck->getX() >= get_tamanho_x())
	{
		truck->setX(1);
	}

	if (truck->getY() <= 0)
	{
		truck->setY(get_tamanho_y());
	}
	else if (truck->getY() >= get_tamanho_y())
	{
		truck->setY(1);
	}

	// bike
	if (bike->getX() <= 0)
	{
		bike->setX(get_tamanho_x());
	}
	else if (bike->getX() >= get_tamanho_x())
	{
		bike->setX(1);
	}

	if (bike->getY() <= 0)
	{
		bike->setY(get_tamanho_y());
	}
	else if (bike->getY() >= get_tamanho_y())
	{
		bike->setY(1);
	}
}


void Mundo::printMundo()
{
	// desenha o mundo no console

	cout << "     Mundo    \n" << endl;

	for (int i = 0; i < tamanho_x; i++)
	{
		cout << "      ";

		for (int j = 0; j < tamanho_y; j++)
		{
			if (map[i][j] == '0')
			{
				// determina cor do texto no console, e imprime char
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK);
				cout << map[i][j];
			}
			else if (map[i][j] == '2')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << map[i][j];
			}
			else if (map[i][j] == '%')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
				cout << map[i][j];
			}
			else if (map[i][j] == '@')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
				cout << map[i][j];
			}
			else if (map[i][j] == '+')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MAGENTA);
				cout << map[i][j];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARKGRAY);
				cout << map[i][j];
			}
		}
		cout << endl;
	}

	// retorna cursor para pois��o inicial
	setCursorPosition(0, 0);
}


void Mundo::setMundo()
{
	/*	Determina o mundo padr�o com 
		bordas (1)	*/

	int i;
	int j;

	// mapa vazio (0)
	for (i = 0; i < tamanho_x; i++)
		for (j = 0; j < tamanho_y; j++)
			map[i][j] = '0';

	// bordas (1)
	for (i = 0; i < tamanho_x; i++)
	{
		for (j = 0; j < tamanho_y; j++)
		{
			if (i == 0)								// primeira linha
				map[i][j] = '1';					
			if (i == (tamanho_x - 1))				// ultima linha
				map[i][j] = '1';
			if (j == 0)								// coluna esquerda
				map[i][j] = '1';
			if (j == (tamanho_y - 1))				// coluna direita
				map[i][j] = '1';
		}
	}

	// obst�culos (2)
	setObstaculo(5, 12, 5, 10);
	setObstaculo(5, 98, 5, 10);
	setObstaculo(30, 12, 5, 10);
	setObstaculo(30, 98, 5, 10);
	setObstaculo(16, 50, 6, 18);

	// copia para defaultMap
	for (i = 0; i < tamanho_x; i++)
	{
		for (j = 0; j < tamanho_y; j++)
		{
			defaultMap[i][j] = map[i][j];
		}
	}
}


void Mundo::setObstaculo(int x, int y, int w, int h) 
{
	/*	Determina obst�culos (2) 
		Posicao obst�culo = x, y
	    Tamanho dos obstaculos = w, h	*/

	for (int i = 0; i < tamanho_x; i++)
	{
		for (int j = 0; j < tamanho_y; j++)
		{
			// obst�culo 1 na posi��o x, y com tamanho w1, h1
			if (i == x && j == y)
			{
				for (int k = 0; k < w; k++)
				{
					for (int l = 0; l < h; l++)
						map[i + k][j + l] = '2';
				}
			}
		}
	}
}


void Mundo::setCursorPosition(int x, int y)
{
	/* Determina posi��o do cursor 
	   x � coluna, y � linha. A origem (0,0) 
	   � o canto superior esquerdo.	*/
	
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}
