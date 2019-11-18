#include <Windows.h>
#include <iostream>
#include <thread>
#define width 8
#define height 20
using namespace std;
int matrix[8][20];
void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawPoint(int x, int y) {
	if (y < 20 && y >= 0) {
		matrix[x][y] = 1;
	}
}
void resetBoard() {
	for (int j = 0;j < height;j++) {
		for (int i = 1; i < width - 1;i++) {
			matrix[i][j] = 0;
		}
	}
}
class EnemyRide {
public:
	EnemyRide() {
		xPos = 5;
		yPos = -3;
	}
	int xPos;
	int yPos;
	void appear() {
		if (yPos == 20) {
			int randomNo = rand() % 2;
			if (randomNo == 0) {
				xPos = 2;
			}
			else {
				xPos = 5;
			}
			yPos = -3;
		}
	}void draw() {
		drawPoint(xPos, yPos);
		drawPoint(xPos - 1, yPos + 1);
		drawPoint(xPos + 1, yPos + 1);
		drawPoint(xPos, yPos + 1);
		drawPoint(xPos, yPos + 2);
		drawPoint(xPos - 1, yPos + 3);
		drawPoint(xPos + 1, yPos + 3);
		drawPoint(xPos, yPos + 3);
	}
	void move() {
		yPos++;
	}
};
class ride {
public:
	int xPos;
	int yPos;
	ride() {
		xPos = 2;
		yPos = 16;
	}
	void draw() {
		drawPoint(xPos, yPos);
		drawPoint(xPos - 1, yPos + 1);
		drawPoint(xPos + 1, yPos + 1);
		drawPoint(xPos, yPos + 1);
		drawPoint(xPos, yPos + 2);
		drawPoint(xPos - 1, yPos + 3);
		drawPoint(xPos + 1, yPos + 3);
		drawPoint(xPos, yPos + 3);
	}
	void moveLeft() {
		xPos = 2;
	}void moveRight() {
		xPos = 5;
	}void checkCollusion(EnemyRide* ride, bool* running) {
		if (ride->xPos == xPos & ride->yPos > 13) {
			*running = false;
		}
	}
};

void keyListener(ride* r) {
	while (true) {
		if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)) {
			r->moveLeft();
		}
		else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0)) {
			r->moveRight();
		}
	}
}

void initializeMap() {
	ride userRide = ride();
	EnemyRide enemyRide = EnemyRide();
	thread secondThread(keyListener, &userRide);
	//Map engine loop..
	bool isRunning = true;
	int score = 0;
	while (isRunning) {
		resetBoard();
		enemyRide.appear();
		enemyRide.draw();
		enemyRide.move();
		userRide.draw();
		userRide.checkCollusion(&enemyRide, &isRunning);
		for (int j = 0;j < height;j++) {
			for (int i = 0; i < width; i++)
			{
				if (i == 0 || i == 7) {
					gotoXY(i, j);
					cout << "0";
				}
				else if (matrix[i][j] == 1) {
					gotoXY(i, j);
					cout << "0";
				}
				else if(enemyRide.yPos == 20){
					score += 10;
				}
				else {
					gotoXY(i, j);
					cout << " ";
				}
			}
		} Sleep(10);
		gotoXY(10, 10);
		cout << "Score:" << score/111 << endl;
	} 
	system("cls");
	Sleep(1000);
	gotoXY(8, 8);
	cout << "Game Over" << endl;
	gotoXY(8, 9);
	cout << "Score : " << score/111 << endl;
	secondThread.detach();
}
int main() {
	srand(time(NULL));
	initializeMap();
	getchar();
	return 0;
}