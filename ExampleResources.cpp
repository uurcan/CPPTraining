#include <Windows.h>
#include <iostream>
#include <thread>
using namespace std;
void delayCommand() {
	int delay = 1000;
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
		Sleep(delay);
	}
}
void gotoXYEx(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void coordUsage(){
		//gotoXY(4,4);
		cout << "Right here ..";
		Sleep(2000);
		//gotoXY(5, 7);
		cout << "Right there..";
}
void secondThreadFunction() {
	for (int i = 0; i < 5; i++) {
		cout << "This comes from the second thread.." << endl;
		Sleep(2000);
	}
}
void mainThread() {
	std::thread secondThread(secondThreadFunction);
	for (int i = 0; i < 5; i++)
	{
		cout << "Function called from the main thread " << endl;
		Sleep(1000);
	}
	secondThread.join();
}
void getScannerState() {
	int flag = 0;
	char* charSequence;
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)) {
			cout << "Left" << endl;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0)) {
			cout << "Right" << endl;
		}
	}
}
