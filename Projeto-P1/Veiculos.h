#pragma once
class Veiculos
{
public:
	Veiculos(int x, int y);
	~Veiculos();
	int getX();
	int getY();
	int getV();
	void setVelocidade(int v);
	void move();
protected:
	int x;
	int y;
	int v;
	bool fabrica;
	string cor;
};

