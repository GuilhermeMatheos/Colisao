#pragma once
class Veiculos
{
public:
	Veiculos();
	~Veiculos();
	void move();
private:
	int x;
	int y;
	int v;
	bool fabrica;
	string cor;
};

