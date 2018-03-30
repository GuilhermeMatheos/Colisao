#pragma once
class Veiculos
{
public:
	Veiculos(int tamanho_x, int tamanho_y);
	~Veiculos();
	int getX();
	int getY();
	int getV();
	void setX(int x);
	void setY(int y);
	void setVelocidade(int v);
	void move();
protected:
	int x;
	int y;
	int v;
	bool fabrica;
	string cor;
};

