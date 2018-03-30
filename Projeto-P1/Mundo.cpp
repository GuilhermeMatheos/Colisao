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
	/*	Cria um mapa padrão com 40 linhas e 120 colunas
		e obstáculos	*/

	tamanho_x = 40;
	tamanho_y = 120;
	setMundo();
}


Mundo::~Mundo()
{
}


int Mundo::get_tamanho_x()
{
	return tamanho_x;
}


int Mundo::get_tamanho_y()
{
	return tamanho_y;
}


void Mundo::resetMap()
{

}


void Mundo::setVeiculos(Carro *car, Caminhao *truck, Moto *bike)
{
	// Determina posição dos veículos

	if ((car->getX() >= 0 && car->getX() <= tamanho_x) &&
		(car->getY() >= 0 && car->getY() <= tamanho_y))
	{
		map[car->getX()][car->getY()] = '%';
	}

	if ((truck->getX() >= 0 && truck->getX() <= tamanho_x) &&
		(truck->getY() >= 0 && truck->getY() <= tamanho_y))
	{
		map[truck->getX()][truck->getY()] = '@';
	}

	if ((bike->getX() >= 0 && bike->getX() <= tamanho_x) &&
		(bike->getY() >= 0 && bike->getY() <= tamanho_y))
	{
		map[bike->getX()][bike->getY()] = '+';
	}
}


void Mundo::movimenta(Carro *car, Caminhao *truck, Moto *bike)
{
	car->move();
	truck->move();
	bike->move();

	if ((car->getX() <= 0 && car->getX() >= tamanho_x) &&
		(car->getY() <= 0 && car->getY() >= tamanho_y))
	{
		// move para parede oposta
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

	// retorna cursor para poisção inicial
	setCursorPosition(0, 0);
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

	// obstáculos (2)
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
	/* Determina posição do cursor 
	   x é coluna, y é linha. A origem (0,0) 
	   é o canto superior esquerdo.	*/
	
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}
