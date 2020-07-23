#include <iostream>
#include <fstream>

using namespace std;

class DisplayShape
{
	int width, height;
	char symbol;
public:
	DisplayShape() { 
		//Default constructor
		width = 6;
		height = 6;
		symbol = '&';
	}
	DisplayShape(int w1, int h1, char s1) { 
		//Constructor overloading with defined parameters
		width = w1;
		height = h1;
		symbol = s1;
	}
	void displayRectangle() {
		int h = height + 4;
		int w = width + 4;
		//Rectangle draw function
		for (int i = 1; i <= w; i++){
			for (int j = 1; j <= h; j++){
				if ((i == 1 || i == w || j == 1 || j == h) ||
					(i >= 3 && i <= w - 2 && j >= 3 && j <= h - 2) &&
					(i >= 3 || i == w - 2 || j >= 3 || j == h - 2)){
					cout << symbol;
				} else{
					cout << " ";
				}
			}
			cout << "\n";
		}
	}
	void displayTriangle() {
		//Triangle draw function
		for (int i = 1; i <= height; ++i) {
			width = height - i;
			while (width > 0) {
				cout << " ";
				width--;
			}
			for (int j = i; j >= 1; j--) {
				cout << symbol;
			}
			cout << "\n";
		}
	}
	void set(int w1, int h1, char s1) {
		//set function to set parameters
		width = w1;
		height = h1;
		symbol = s1;
	}
};

int main()
{
	int i1, i2, i3, i4;
	char c1, c2;

	cin >> i1 >> i2 >> c1;
	cin >> i3 >> i4 >> c2;

	DisplayShape ps1;

	ps1.displayRectangle();
	cout << endl;
	ps1.displayTriangle();
	cout << endl;

	DisplayShape ps2(i1, i2, c1);

	ps2.displayRectangle();
	cout << endl;
	ps2.displayTriangle();
	cout << endl;

	ps2.set(i3, i4, c2);

	ps2.displayRectangle();
	cout << endl;
	ps2.displayTriangle();
	cout << endl;

	return 0;
}
