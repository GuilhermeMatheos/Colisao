#include "stdafx.h"
#include "Veiculos.h"
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"
#include "Mundo.h"
#include "Hardware.h"


Mundo::Mundo()
{
	/*	Cria um mapa padrão com 40 linhas e 120 colunas
		e obstáculos	*/
	tamanho_x = 40;
	tamanho_y = 120;
	numObstaculo = 0;
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


void Mundo::setVeiculos(vector<Carro> &car, vector<Caminhao> &truck, vector<Moto> &bike)
{
	// Determina posição dos veículos

	int i;

	for (i = 0; i < car.size(); i++)
	{
		map[car[i].getX()][car[i].getY()] = '%';
	}

	for (i = 0; i < truck.size(); i++)
	{
		map[truck[i].getX()][truck[i].getY()] = '@';
	}

	for (i = 0; i < bike.size(); i++)
	{
		map[bike[i].getX()][bike[i].getY()] = '+';
	}
}


void Mundo::movimenta(vector<Carro> &car, vector<Caminhao> &truck, vector<Moto> &bike)
{
	int i;
	
	// carro
	for (i = 0; i < car.size(); i++)
	{
		// movimenta
		car[i].move();
		
		// ao colidir com parede aparece na borda oposta
		if (car[i].getX() <= 0)
		{
			car[i].setX(get_tamanho_x() - 2);
		}
		else if (car[i].getX() >= get_tamanho_x() - 1)
		{
			car[i].setX(1);
		}

		if (car[i].getY() <= 0)
		{
			car[i].setY(get_tamanho_y() - 2);
		}
		else if (car[i].getY() >= get_tamanho_y() - 1)
		{
			car[i].setY(1);
		}
	}

	// caminhao
	for (i = 0; i < truck.size(); i++)
	{
		// movimenta
		truck[i].move();

		// ao colidir com parede aparece na borda oposta
		if (truck[i].getX() <= 0)
		{
			truck[i].setX(get_tamanho_x() - 2);
		}
		else if (truck[i].getX() >= get_tamanho_x() - 1)
		{
			truck[i].setX(1);
		}

		if (truck[i].getY() <= 0)
		{
			truck[i].setY(get_tamanho_y() - 2);
		}
		else if (truck[i].getY() >= get_tamanho_y() - 1)
		{
			truck[i].setY(1);
		}
	}

	// moto
	for (i = 0; i < bike.size(); i++)
	{
		// movimenta
		bike[i].move();

		// ao colidir com parede aparece na borda oposta
		if (bike[i].getX() <= 0)
		{
			bike[i].setX(get_tamanho_x() - 2);
		}
		else if (bike[i].getX() >= get_tamanho_x() - 1)
		{
			bike[i].setX(1);
		}

		if (bike[i].getY() <= 0)
		{
			bike[i].setY(get_tamanho_y() - 2);
		}
		else if (bike[i].getY() >= get_tamanho_y() - 1)
		{
			bike[i].setY(1);
		}
	}
}


void Mundo::colisao(vector<Carro> &car, vector<Caminhao> &truck, vector<Moto> &bike)
{
	int i;
	int j;

	vector<Carro> copy_car = car;
	vector<Caminhao> copy_truck = truck;
	vector<Moto>copy_bike = bike;

	// bike com carro
endloop:
	for (i = 0; i < bike.size(); i++)
	{
		for (j = 0; j < car.size(); j++)
		{
			if (bike[i].getX() == car[j].getY() &&
				bike[i].getY() == car[j].getY())
			{
				bike.erase(bike.begin() + (i));
				goto endloop;
			}
		}
	}
	// bike com truck
endloop1:
	for (i = 0; i < bike.size(); i++)
	{
		for (j = 0; j < truck.size(); j++)
		{
			if (bike[i].getX() == truck[j].getY() &&
				bike[i].getY() == truck[j].getY())
			{
				bike.erase(bike.begin() + (i));
				goto endloop1;
			}
		}
	}
	// bike com bike
endloop2:
	for (i = 0; i < bike.size(); i++)
	{
		for (j = 0; j < copy_bike.size(); j++)
		{
			if (bike[i].getX() == copy_bike[j].getY() &&
				bike[i].getY() == copy_bike[j].getY())
			{
				bike.erase(bike.begin() + (i));
				goto endloop2;
			}
		}
	}
	// car com bike
endloop3:
	for (i = 0; i < car.size(); i++)
	{
		for (j = 0; j < bike.size(); j++)
		{
			if (car[i].getX() == bike[j].getY() &&
				car[i].getY() == bike[j].getY())
			{
				bike.erase(bike.begin() + (j));
				goto endloop3;
			}
		}
	}
	// car com truck
endloop4:
	for (i = 0; i < car.size(); i++)
	{
		for (j = 0; j < truck.size(); j++)
		{
			if (car[i].getX() == truck[j].getY() &&
				car[i].getY() == truck[j].getY())
			{
				car.erase(car.begin() + (i));
				goto endloop4;
			}
		}
	}
	// car com car
endloop5:
	for (i = 0; i < car.size(); i++)
	{
		for (j = 0; j < copy_car.size(); j++)
		{
			if (car[i].getX() == copy_car[j].getY() &&
				car[i].getY() == copy_car[j].getY())
			{
				car.erase(car.begin() + (i));
				goto endloop5;
			}
		}
	}
	// truck com truck
endloop6:
	for (i = 0; i < truck.size(); i++)
	{
		for (j = 0; j < copy_truck.size(); j++)
		{
			if (truck[i].getX() == copy_truck[j].getY() &&
				truck[i].getY() == copy_truck[j].getY())
			{
				truck.erase(truck.begin() + (i));
				goto endloop6;
			}
		}
	}
}


void Mundo::fabricaVeiculo(vector<Carro> &car, vector<Caminhao> &truck, vector<Moto> &bike)
{
	/* fabrica novo veículo caso este passe
	   pela zona de fábrica (2) */
	int k, i;
	
	// car
	for (k = 0; k < car.size(); k++)
	{
		for (i = 0; i < posObstaculo.size(); i++)
		{
			if (car[k].getX() >= posObstaculo[i].x && car[k].getX() < (posObstaculo[i].x + posObstaculo[i].w) &&
				car[k].getY() >= posObstaculo[i].y && car[k].getY() < (posObstaculo[i].y + posObstaculo[i].h) &&
				car[k].getFabrica())
			{
				car[k].setFabrica(false);
				Carro c = Carro(tamanho_x, tamanho_y);
				car.push_back(c);
			}
		}
	}
	
	// truck
	for (k = 0; k < truck.size(); k++)
	{
		for (i = 0; i < posObstaculo.size(); i++)
		{
			if (truck[k].getX() >= posObstaculo[i].x && truck[k].getX() < (posObstaculo[i].x + posObstaculo[i].w) &&
				truck[k].getY() >= posObstaculo[i].y && truck[k].getY() < (posObstaculo[i].y + posObstaculo[i].h) &&
				truck[k].getFabrica())
			{
				truck[k].setFabrica(false);
				Caminhao c = Caminhao(tamanho_x, tamanho_y);
				truck.push_back(c);
			}
		}
	}

	// bike
	for (k = 0; k < bike.size(); k++)
	{
		for (i = 0; i < posObstaculo.size(); i++)
		{
			if (bike[k].getX() >= posObstaculo[i].x && bike[k].getX() < (posObstaculo[i].x + posObstaculo[i].w) &&
				bike[k].getY() >= posObstaculo[i].y && bike[k].getY() < (posObstaculo[i].y + posObstaculo[i].h) &&
				bike[k].getFabrica())
			{
				bike[k].setFabrica(false);
				Moto c = Moto(tamanho_x, tamanho_y);
				bike.push_back(c);
			}
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

	// salva posicão dos obstáculos na struct RECT

	rect p;
	p.x = x;
	p.y = y;
	p.w = w;
	p.h = h;

	posObstaculo.push_back(p);
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
	setObstaculo(16, 55, 6, 12);
	//setObstaculo(5, 10, 30, 80);
	numObstaculo += 5;

	// copia para defaultMap
	for (i = 0; i < tamanho_x; i++)
	{
		for (j = 0; j < tamanho_y; j++)
		{
			defaultMap[i][j] = map[i][j];
		}
	}
}


void Mundo::printMundo(int car_size, int truck_size, int bike_size)
{
	// desenha o mundo no console

	// letras
	#define BLACK 0
	#define LETRA_VERMELHA FOREGROUND_RED
	#define LETRA_AZUL FOREGROUND_BLUE
	#define LETRA_AMARELA FOREGROUND_RED | FOREGROUND_GREEN 
	#define LETRA_ROSA FOREGROUND_RED | FOREGROUND_BLUE
	#define LETRA_BRANCA FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
	// background
	#define FUNDO_VERMELHO BACKGROUND_RED
	#define FUNDO_AZUL BACKGROUND_BLUE
	#define FUNDO_AMARELO BACKGROUND_RED | BACKGROUND_GREEN
	#define FUNDO_ROSA BACKGROUND_RED | BACKGROUND_BLUE
	#define FUNDO_BRANCO BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE


	Hardware hw = Hardware();

	hw.changeColor(BLACK);
	printf("      ");
	hw.changeColor(LETRA_AZUL | FUNDO_BRANCO);
	printf(" Carro: %d ", car_size);
	hw.changeColor(LETRA_AMARELA | FUNDO_BRANCO);
	printf("Caminhao: %d ", truck_size);
	hw.changeColor(LETRA_ROSA | FUNDO_BRANCO);
	printf("Moto: %d \n", bike_size);

	for (int i = 0; i < tamanho_x; i++)
	{
		hw.changeColor(BLACK);
		cout << "      ";

		for (int j = 0; j < tamanho_y; j++)
		{
			if (map[i][j] == '0')
			{
				hw.changeColor(BLACK);
				cout << map[i][j];
			}
			else if (map[i][j] == '2')
			{
				hw.changeColor(LETRA_VERMELHA | FUNDO_VERMELHO);
				cout << map[i][j];
			}
			else if (map[i][j] == '%')
			{
				hw.changeColor(LETRA_AZUL | FUNDO_AZUL);
				cout << map[i][j];
			}
			else if (map[i][j] == '@')
			{
				hw.changeColor(LETRA_AMARELA | FUNDO_AMARELO);
				cout << map[i][j];
			}
			else if (map[i][j] == '+')
			{
				hw.changeColor(LETRA_ROSA | FUNDO_ROSA);
				cout << map[i][j];
			}
			else if (map[i][j] == '1')
			{
				hw.changeColor(LETRA_BRANCA | FUNDO_BRANCO);
				cout << map[i][j];
			}
		}
		cout << endl;
	}

	// retorna cursor para posição inicial
	hw.setCursorPosition(0, 0);
}
