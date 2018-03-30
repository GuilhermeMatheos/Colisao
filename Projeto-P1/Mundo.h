#pragma once
class Mundo
{
public:
	Mundo();
	~Mundo();
	int get_tamanho_x();
	int get_tamanho_y();
	void resetMap();
	void setVeiculos(Carro *, Caminhao *, Moto *);
	void movimenta(Carro *, Caminhao *, Moto *);
	void printMundo();
private:
	void setMundo();
	void setObstaculo(int, int, int, int);
	void setCursorPosition(int, int);
	int tamanho_x;
	int tamanho_y;
	char map[40][120];
	char defaultMap[40][120];
};

