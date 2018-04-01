#pragma once
class Mundo
{
public:
	Mundo();
	~Mundo();
	int get_tamanho_x();
	int get_tamanho_y();
	void resetMap();
	void setVeiculos(vector<Carro>&, vector<Caminhao>&, vector<Moto>&);
	void movimenta(vector<Carro>&, vector<Caminhao>&, vector<Moto>&);
	void colisao(vector<Carro>&, vector<Caminhao>&, vector<Moto>&);
	void printMundo(int, int, int);
private:
	int tamanho_x;
	int tamanho_y;
	char map[40][120];
	char defaultMap[40][120];
	void setMundo();
	void setObstaculo(int, int, int, int);
};

