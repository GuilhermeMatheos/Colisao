#pragma once
class Veiculos
{
public:
	Veiculos(int x, int y, int v);
	~Veiculos();
	void move();
protected:
	int x;
	int y;
	int v;
	bool fabrica;
	string cor;
};

