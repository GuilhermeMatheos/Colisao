#pragma once
class Hardware
{
public:
	Hardware();
	~Hardware();
	void init(int, int);
	void changeColor(int);
	void setCursorPosition(int, int);
};

