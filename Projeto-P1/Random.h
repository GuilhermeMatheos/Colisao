#pragma once
class Random
{
public:
	Random(int, int);
	~Random();
	int generate();
private:
	int a, b;
};

