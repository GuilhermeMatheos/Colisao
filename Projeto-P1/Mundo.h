#pragma once
class Mundo
{
public:
	Mundo();
	~Mundo();
	void printMundo();
	void setVeiculos(Carro, Caminhao, Moto);
private:
	void setPadrao();
	void setObstaculo(int, int, int, int);
	int tamanho_x;
	int tamanho_y;
	char mapa[30][60];
};

