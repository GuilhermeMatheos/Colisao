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
	void setFabrica(bool);
	void move();
protected:
	int x;
	int y;
	int v;
	bool fabrica;
	string cor;
};

