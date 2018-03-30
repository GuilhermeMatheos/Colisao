#pragma once
class Mundo
{
public:
	Mundo();
	~Mundo();
	void setMundo();
	void setVeiculos(Carro, Caminhao, Moto);
	void printMundo();
private:
	void setObstaculo(int, int, int, int);
	void setCursorPosition(int, int);
	int tamanho_x;
	int tamanho_y;
	char mapa[40][120];
};

