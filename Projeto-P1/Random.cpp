#include "stdafx.h"
#include "Random.h"
#include <random>
#include <time.h>


Random::Random(int a, int b)
{
	// cria o objeto Random com intervalo (a,b)
	this->a = a;
	this->b = b;
}


Random::~Random()
{
}


int Random::generate()
{
	// gera um número aleatório no intervalo (a,b)

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(1, 4); // define the range

	int x = distr(eng);

	return x;
}