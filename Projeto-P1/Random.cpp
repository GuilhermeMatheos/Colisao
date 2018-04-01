#include "stdafx.h"
#include "Random.h"


Random::Random()
{
}


Random::~Random()
{
}


int Random::generate(int a, int b)
{
	// gera um número aleatório no intervalo (a,b)

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(a, b); // define the range

	int x = distr(eng);

	return x;
}