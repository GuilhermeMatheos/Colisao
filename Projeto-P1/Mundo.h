#pragma once
class Mundo
{
public:
	Mundo();
	~Mundo();
	void setPadrao();
	void printMundo();
private:
	int tamanho_x;
	int tamanho_y;
	int mapa[30][60];
};

