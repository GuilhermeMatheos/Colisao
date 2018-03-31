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
	// retorma tamanho x
	return tamanho_x;
}


int Mundo::get_tamanho_y()
{
	// retorma tamanho y
	return tamanho_y;
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


void Mundo::setVeiculos(vector<Carro*> car, vector<Caminhao*> truck, vector<Moto*> bike)
{
	// Determina posição dos veículos
	int i;

	for (i = 0; i < car.size(); i++)
	{
		if ((car[i]->getX() > 0 && car[i]->getX() < get_tamanho_x() - 1) &&
			(car[i]->getY() > 0 && car[i]->getY() < get_tamanho_y() - 1))
		{
			map[car[i]->getX()][car[i]->getY()] = '%';
		}
	}

	for (i = 0; i < truck.size(); i++)
	{
		if ((truck[i]->getX() > 0 && truck[i]->getX() < get_tamanho_x() - 1) &&
			(truck[i]->getY() > 0 && truck[i]->getY() < get_tamanho_y() - 1))
		{
			map[truck[i]->getX()][truck[i]->getY()] = '@';
		}
	}

	for (i = 0; i < bike.size(); i++)
	{
		if ((bike[i]->getX() > 0 && bike[i]->getX() < get_tamanho_x() - 1) &&
			(bike[i]->getY() > 0 && bike[i]->getY() < get_tamanho_y() - 1))
		{
			map[bike[i]->getX()][bike[i]->getY()] = '+';
		}
	}
}


void Mundo::movimenta(vector<Carro*> car, vector<Caminhao*> truck, vector<Moto*> bike)
{
	int i;

	// carro
	for (i = 0; i < car.size(); i++)
	{
		// movimenta
		car[i]->move();

		// ao colidir com parede aparece na borda oposta
		if (car[i]->getX() <= 0)
		{
			car[i]->setX(get_tamanho_x() - 2);
		}
		else if (car[i]->getX() >= get_tamanho_x() - 1)
		{
			car[i]->setX(1);
		}

		if (car[i]->getY() <= 0)
		{
			car[i]->setY(get_tamanho_y() - 2);
		}
		else if (car[i]->getY() >= get_tamanho_y() - 1)
		{
			car[i]->setY(1);
		}
	}

	// caminhao
	for (i = 0; i < truck.size(); i++)
	{
		// movimenta
		truck[i]->move();

		// ao colidir com parede aparece na borda oposta
		if (truck[i]->getX() <= 0)
		{
			truck[i]->setX(get_tamanho_x() - 2);
		}
		else if (truck[i]->getX() >= get_tamanho_x() - 1)
		{
			truck[i]->setX(1);
		}

		if (truck[i]->getY() <= 0)
		{
			truck[i]->setY(get_tamanho_y() - 2);
		}
		else if (truck[i]->getY() >= get_tamanho_y() - 1)
		{
			truck[i]->setY(1);
		}
	}

	// moto
	for (i = 0; i < bike.size(); i++)
	{
		// movimenta
		bike[i]->move();

		// ao colidir com parede aparece na borda oposta
		if (bike[i]->getX() <= 0)
		{
			bike[i]->setX(get_tamanho_x() - 2);
		}
		else if (bike[i]->getX() >= get_tamanho_x() - 1)
		{
			bike[i]->setX(1);
		}

		if (bike[i]->getY() <= 0)
		{
			bike[i]->setY(get_tamanho_y() - 2);
		}
		else if (bike[i]->getY() >= get_tamanho_y() - 1)
		{
			bike[i]->setY(1);
		}
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
				// vermelho
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
				cout << map[i][j];
			}
			else if (map[i][j] == '%')
			{
				// azul
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE);
				cout << map[i][j];
			}
			else if (map[i][j] == '@')
			{
				// amarelo
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN);
				cout << map[i][j];
			}
			else if (map[i][j] == '+')
			{
				// rosa
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_BLUE);
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
