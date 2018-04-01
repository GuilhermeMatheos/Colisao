#pragma once
class Hardware
{
public:
	Hardware();
	~Hardware();
	void init();
	void changeColor(int);
	void setCursorPosition(int, int);
private:
	int x, y;
	int w, h;
};

