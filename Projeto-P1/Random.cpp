#include "stdafx.h"
#include "Random.h"
#include <random>
#include <time.h>


Random::Random(int a, int b)
{
	this->a = a;
	this->b = b;
}


Random::~Random()
{
}


int Random::generate()
{
	std::mt19937 mt(time(nullptr)); // shitty seeding, less shitty generator
	int x = std::uniform_int_distribution<int>(a, b)(mt); // good uniform distribution
	//std::shuffle(vec.begin(), vec.end(), mt);
	return x;
}