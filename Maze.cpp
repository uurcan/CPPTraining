#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

char giris;
int mapArr[13][33] = {
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1 },
{ 1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1 },
{ 1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1 },
{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1 }
};
void charyaz()
{
	cout << char(175);
}

void gotoXY(int, int);
void labr();
void move();
int main()
{
	labr();
	move();
}
void labr()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 33; j++)
		{
			switch (mapArr[i][j])
			{
			case 0:
				cout << " ";
				break;

			case 1:
				cout << char(219);
				break;
			case 2:
				cout << " ";
				break;
			}
		}
		cout << " " << endl;
	}
}
void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void move()
{
	int x = 1;
	int y = 1;
	int xCln = 1;
	int yCln = 1;
	while (true)
	{
		gotoXY(xCln, yCln);
		cout << " ";

		gotoXY(x, y);
		charyaz();
		giris = _getch();
		xCln = x;
		yCln = y;

		if (giris == 'w')
		{
			y -= 1;
		}
		else if (giris == 's')
		{
			y += 1;
		}
		else if (giris == 'a')
		{
			x -= 1;
		}
		else if (giris == 'd')
		{
			x += 1;
		}
		if (mapArr[y][x] == 1)
		{
			x = xCln;
			y = yCln;
		}
		else if (mapArr[y][x] == 2)
		{
			cout << endl;
			cout << endl;
			cout << ":)" << endl;
			system("COLOR A");
			cin.get();
		}
	}
}
