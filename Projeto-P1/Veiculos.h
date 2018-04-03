#pragma once
class Veiculos
{
public:
	Veiculos(int tamanho_x, int tamanho_y);
	~Veiculos();
	int getX();
	int getY();
	int getV();
	int getFabrica();
	void setX(int x);
	void setY(int y);
	void setVelocidade(int v);
	void setFabrica(int);
	void move();
protected:
	int x;
	int y;
	int v;
	int num;
	bool fabrica;
	string cor;
};

