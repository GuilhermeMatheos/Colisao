#pragma once
class Mundo
{
public:
	Mundo();
	~Mundo();
	void printMundo();
private:
	void setPadrao();
	void setObstaculo(int, int, int, int);
	int tamanho_x;
	int tamanho_y;
	int mapa[30][60];
};

