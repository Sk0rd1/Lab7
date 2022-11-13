#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
	int x;
	int y;
};

class ChessFigure
{
public:
	virtual void check(Point figure, Point king)
	{
		cout << "GG";
	}
};

class Elephant : public ChessFigure
{
public:
	void check(Point figure, Point king) override
	{
		bool test = false;

		for (int i = 0; i < 15; i++)
			if (figure.x - 7 + i == king.x && figure.y - 7 + i == king.y || figure.x - 7 + i == king.x && figure.y + 7 - i == king.y)
				test = true;

		if (test) cout << " Shah";
		else cout << " Nothing";
	}
};

class Horse : public ChessFigure
{
public:
	void check(Point figure, Point king) override
	{
		bool test = false;

		if (abs(figure.x - king.x) == 2 && abs(figure.y - king.y) == 1 || abs(figure.x - king.x) == 1 && abs(figure.y - king.y) == 2)
			test = true;

		if (test) cout << " Shah";
		else cout << " Nothing";
	}
};

class Queen : public ChessFigure
{
public:
	void check(Point figure, Point king) override
	{
		bool test = false;

		for (int i = 0; i < 15; i++)
			if (figure.x - 7 + i == king.x && figure.y - 7 + i == king.y || figure.x - 7 + i == king.x && figure.y + 7 - i == king.y)
				test = true;

		if (figure.x == king.x || figure.y == king.y)
			test = true;

		if (test) cout << " Shah";
		else cout << " Nothing";
	}
};

class Tour : public ChessFigure
{
public:
	void check(Point figure, Point king) override
	{
		bool test = false;

		if (figure.x == king.x || figure.y == king.y)
			test = true;

		if (test) cout << " Shah";
		else cout << " Nothing";
	}
};

int main()
{
	Point figure;
	Point king;
	char res;
	cout << " [1] - Elephant\n [2] - Horse\n [3] - Queen\n [4] - Tour\n Input number: ";
	int number;
	cin >> number;
	cout << " Input coordinates of the king: ";
	getchar();
	res = getchar();
	king.x = (int)res - 96;
	king.y = getchar() - 48;
	cout << " Input coordinates of the figure: ";
	getchar();
	res = getchar();
	figure.x = (int)res - 96;
	figure.y = getchar() - 48;

	ChessFigure* Audit = nullptr;

	if (number == 1)
	{
		Elephant test;
		Audit = &test;
	}
	else if (number == 2)
	{
		Horse test;
		Audit = &test;
	}
	else if (number == 3)
	{
		Queen test;
		Audit = &test;
	}
	else if (number == 4)
	{
		Tour test;
		Audit = &test;
	}

	Audit->check(figure, king);
}