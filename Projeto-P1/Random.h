#pragma once
class Random
{
public:
	Random(int a, int b);
	~Random();
	int generate();
private:
	int a, b;
};

