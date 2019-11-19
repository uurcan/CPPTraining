#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;
#define row 20
#define column 20
#define max 20

bool gameOver;
int x, y, baitx, baity, score;
int tailX[100], tailY[100];
int sizeTail;

enum Direction
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};
Direction direct;

void Start()
{
	gameOver = false;
	direct = STOP;
	x = 1;
	y = 1;
	baitx = rand() % row;
	baity = rand() % column;
	score = 0;
}
void Map()
{
	system("cls");
	for (int i = 0; i < row + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "x";
			}
			else if (i == baitx && j == baity)
			{
				cout << "o";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < sizeTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "x";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == row - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < column + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "puan " << score << endl;
}

void Map2()
{
	system("cls");

	for (int i = 0; i < max + 2; i++)
	{
		cout << "#";
	}
	for (int i = 0; i < max; i++)
	{
		cout << endl;
		for (int j = 0; j < max; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "x";
			}
			else if (i == baitx && j == baity)
			{
				cout << "o";
			}
			else if ((i == 8 && j == 8) || (i == 8 && j == 8 + 1) || (i == 8 + 1 && j == 8) ||
				(i == 8 + 1 && j == 8 + 1) || (i == 8 && j == 8 + 2) || (i == 8 + 1 && j == 8 + 2) ||
				(i == 8 + 2 && j == 8) || (i == 8 + 2 && j == 8 + 1) || (i == 8 + 2 && j == 8 + 2) ||(i==7 && j==7)
				|| (i==7 && j==8) || (i == 7 && j ==9) ||(i == 7 && j == 10) ||(i == 8 && j == 7) ||(i == 9 && j ==7)
				|| (i == 10 && j == 7) ||(i == 7 && j == 11) || (i == 8 && j == 11) || (i == 9 && j == 11) || (i == 10 && j == 11))
				cout << "#";
			else {
				bool print = false;
				for (int k = 0; k < sizeTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "x";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == max - 1)
			{
				cout << "#";
			}
		}
	}
	cout << endl;
	for (int i = 0; i < max + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "puan " << score + 50 << endl;
}
void Map3()
{
	system("cls");

	for (int i = 0; i < max + 2; i++)
	{
		cout << "#";
	}
	for (int i = 0; i < max; i++)
	{
		cout << endl;
		for (int j = 0; j < max; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "x";
			}
			else if (i == baitx && j == baity)
			{
				cout << "o";
			}

			else if ((i == 3 && j == 4) || (i == 4 && j == 5) || (i == 5 && j == 6) ||
				(i == 5 && j == 12 + 1) || (i == 4 && j == 13 + 1) || (i == 3 && j == 14 + 1) ||
				(i == 15 && j == 6) || (i == 16 && j == 5) || (i == 17 && j == 4) ||
				(i == 15 && j == 13) || (i == 16 && j == 14) || (i == 17 && j == 15) || (i == 10 && j == 10))
				cout << "#";
			else {
				bool print = false;
				for (int k = 0; k < sizeTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "x";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == max - 1)
			{
				cout << "#";
			}
		}
	}
	cout << endl;
	for (int i = 0; i < max + 2; i++)
	{
		cout << "#";
	}
	cout << endl;

	cout << "puan: " << score + 100 << endl;
}
void Map4()
{
	system("cls");
	for (int i = 0; i < max + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "x";
			}
			else if (i == baitx && j == baity)
			{
				cout << "o";
			}
			else if (i == 2 && j == 9 || i == 3 && j == 9 || i == 4 && j == 9 || i == 5 && j == 9 || i == 6 && j == 9
				|| i == 7 && j == 9 || i == 8 && j == 9 || i == 9 && j == 9 || i == 10 && j == 9 || i == 11 && j == 9
				|| i == 12 && j == 9 || i == 13 && j == 9 || i == 14 && j == 9 || i == 15 && j == 9
				|| i == 16 && j == 9 || i == 9 && j == 4 || i == 9 && j == 5 || i == 9 && j == 6 || i == 9 && j == 7
				|| i == 9 && j == 8 || i == 9 && j == 10 || i == 9 && j == 11 || i == 9 && j == 12 || i == 9 && j == 13
				|| i == 9 && j == 14 || i == 9 && j == 15)
				cout << "#";
			else {
				bool print = false;
				for (int k = 0; k < sizeTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "x";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == row - 1)
			{
				cout << "#";
			}
		}
		
		cout << endl;
	}
	for (int i = 0; i < column + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	
	cout << "puan: " << score << endl;

}
void Move() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			direct = LEFT;
			break;
		case 'd':
			direct = RIGHT;
			break;
		case 'w':
			direct = UP;
			break;
		case 's':
			direct = DOWN;
			break;
		case 'q':
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	int prevX, prevy;
	prevX = tailX[0];
	prevy = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < sizeTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevy;
		prevX = prev2X;
		prevy = prev2Y;
	}
	switch (direct)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}
	if (x == baity && y == baitx)
	{
		sizeTail++;
		score += 10;
		baitx = rand() % row;
		baity = rand() % column;
	}
}

int main()
{
	
	Start();
	while (!gameOver)
	{
		system("COLOR 6");
		Map();
		Move();
		Logic();	
		if (score >= 50)
			gameOver = true;
		for (int i = 0; i < sizeTail; i++)
		{
			if (tailX[i] == x && tailY[i] == y)
			{
				system("cls");
					system("COLOR 4");
				cout << "Kaybettiniz.. puaniniz: " << score << endl;
				Sleep(1600);
				return 0;
			}
		}
		if (x > row - 1 || x < 0 || y > column - 1 || y < 0) {
			system("cls");
					system("COLOR 4");
			cout << "Kaybettiniz.. puaniniz: " << score << endl;
			Sleep(1600);
			return 0;
		}
	}
	system("cls");
	cout << "Bolum 2 yukleniyor lutfen bekleyin..";
	Sleep(2000);
	sizeTail = 0;
	Start();
	while (!gameOver)
	{
		Map2();
		Move();
		Logic();
		system("COLOR 3");
		if (score >= 50)
			gameOver = true;
		for (int i = 0; i < sizeTail; i++)
		{
			if (tailX[i] == x && tailY[i] == y)
			{
				system("cls");
					system("COLOR 4");
				cout << "Kaybettiniz.. puaniniz: " << score << endl;
				Sleep(1600);
				return 0;
			}
		}
		if (x > row - 1 || x < 0 || y > column - 1 || y < 0) {
			system("cls");
					system("COLOR 4");
			cout << "Kaybettiniz.. puaniniz: " << score << endl;
			Sleep(1600);
			return 0;
		}
		
		if ((x == 8 && y == 8) || (x == 8 && y == 8 + 1) || (x == 8 + 1 && y == 8) ||
			(x == 8 + 1 && y == 8 + 1) || (x == 8 && y == 8 + 2) || (x == 8 + 1 && y == 8 + 2) ||
			(x == 8 + 2 && y == 8) || (x == 8 + 2 && y == 8 + 1) || (x == 8 + 2 && y == 8 + 2) || (x == 7 && y == 7)
			|| (x == 7 && y == 8) || (x == 7 && y == 9) || (x == 7 && y == 10) || (x == 8 && y == 7) || (x == 9 && y == 7)
			|| (x == 10 && y == 7) || (y == 7 && x == 11) || (y == 8 && x == 11) || (y == 9 && x == 11) || (y == 10 && x == 11))
		{
			system("cls");
					system("COLOR 4");
			cout << "Kaybettiniz.. puaniniz: " << score << endl;
			Sleep(1600);
			return 0;
		}		
	}
	system("cls");
	cout << "Bolum 3 yukleniyor lutfen bekleyin..";
	Sleep(2000);
	sizeTail = 0;
	Start();
	while (!gameOver)
	{
		Map3();
		Move();
		Logic();
		system("COLOR 2");
		if (score >= 50)
		{
			gameOver = true;
		}
			for (int i = 0; i < sizeTail; i++)
			{
				if (tailX[i] == x && tailY[i] == y)
				{
					system("cls");
					system("COLOR 4");
					cout << "Kaybettiniz.. puaniniz: " << score << endl;
					Sleep(1600);
					return 0;
				}
			}
			if (x > row - 1 || x < 0 || y > column - 1 || y < 0) {
				system("cls");
					system("COLOR 4");
				cout << "Kaybettiniz.. puaniniz: " << score << endl;
				Sleep(1600);
				return 0;
			}
			if ((y == 3 && x == 4) || (y == 4 && x == 5) || (y == 5 && x == 6) ||
				(y == 5 && x == 12 + 1) || (y == 4 && x == 13 + 1) || (y == 3 && x == 14 + 1) ||
				(y == 15 && x == 6) || (y == 16 && x == 5) || (y == 17 && x == 4) ||
				(y == 15 && x == 13) || (y == 16 && x == 14) || (y == 17 && x == 15) || (y == 10 && x == 10))
			{
				system("cls");
					system("COLOR 4");
				cout << "Kaybettiniz.. puaniniz: " << score << endl;
				Sleep(1600);
				return 0;
			}
		}
	system("cls");
	cout << "Bolum 4 yukleniyor lutfen bekleyin..";
	Sleep(2000);
	sizeTail = 0;
	Start();
	while (!gameOver)
	{
		Map4();
		Move();
		Logic();
		system("COLOR 5");
		if (score >= 50)
		{
			gameOver = true;
			system("cls");
			system("COLOR 2");
			cout << "Tebrikler.. puaniniz: " << score + 150 << endl;
			_getch();
		}
		for (int i = 0; i < sizeTail; i++)
		{
			if (tailX[i] == x && tailY[i] == y)
			{
				system("cls");
					system("COLOR 4");
				cout << "Kaybettiniz.. puaniniz: " << score << endl;
				Sleep(1600);
				return 0;
			}
		}
		if (x > row - 1 || x < 0 || y > column - 1 || y < 0) {
			system("cls");
					system("COLOR 4");
			cout << "Kaybettiniz.. puaniniz: " << score << endl;
			Sleep(1600);
			return 0;
		}
		if (y == 2 && x == 9 || y == 3 && x == 9 || y == 4 && x == 9 || y == 5 && x == 9 || y == 6 && x == 9
			|| y == 7 && x == 9 || y == 8 && x == 9 || y == 9 && x == 9 || y == 10 && x == 9 || y == 11 && x == 9
			|| y == 12 && x == 9 || y == 13 && x == 9 || y == 14 && x == 9 || y == 15 && x == 9
			|| y == 16 && x == 9 || y == 9 && x == 4 || y == 9 && x == 5 || y == 9 && x == 6 || y == 9 && x == 7
			|| y == 9 && x == 8 || y == 9 && x == 10 || y == 9 && x == 11 || y == 9 && x == 12 || y == 9 && x == 13
			|| y == 9 && x == 14 || y == 9 && x == 15)
		{
			system("cls");
					system("COLOR 4");
			cout << "Kaybettiniz.. puaniniz: " << score << endl;
			Sleep(1600);
			return 0;
		}
	}
	_getch();
}