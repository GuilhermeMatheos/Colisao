// Projeto-P1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Random.hpp"


int main()
{
	Random r = Random(1, 4);
	cout << r.generate();

	system("pause");
    return 0;
}