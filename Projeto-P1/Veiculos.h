#pragma once
class Veiculos
{
public:
	Veiculos(int, int, int);
	~Veiculos();
	void move();
protected:
	int x;
	int y;
	int v;
	bool fabrica;
	string cor;
};

