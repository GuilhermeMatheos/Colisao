#pragma once
class Veiculos
{
public:
	Veiculos(int x, int y);
	~Veiculos();
	void setVelocidade(int v);
	void move();
protected:
	int x;
	int y;
	int v;
	bool fabrica;
	string cor;
};

