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

	std::mt19937 mt(time(nullptr));								// seeding, generator
	int x = std::uniform_int_distribution<int>(a, b)(mt);		// uniform distribution
	//std::shuffle(vec.begin(), vec.end(), mt);					// shuffle vector

	return x;
}