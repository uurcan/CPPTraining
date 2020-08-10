
#include <iostream>
using namespace std;

class Shape
{

public:
	Shape() {
		a = 4;
		b = 4;
		c = '#';
	}
	Shape(int n1, int n2, char c1) {
		a = n1;
		b = n2;
		c = c1;
	}
	void printShape() {
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				if (i == 1 || i == a ||
					j == 1 || j == b)
					cout << c;
				else
					cout << " ";
			}
			for (int j = 1; j < i; j++)
			{
				if (i == a || i == j) {
					cout << " ";
				}
				else {
					cout << c;
				}
			}
			cout << endl;
		}

	}
	void set(int a1, int b1, char c1) {
		a = a1;
		b = b1;
		c = c1;
	}

	Shape& operator*(int number) {
		Shape temp = *this;
		temp.a *= number;
		temp.b *= number;
		return temp;
	}

	Shape& operator+ (const Shape& shape) {
		Shape temp = *this;
		temp.a += shape.a;
		temp.b += shape.b;
		return temp;
	}

private:
	int a;
	int b;
	char c;
};

int main()
{
	int number1, number2, number3, number4;
	char c1, c2;

	cin >> number1 >> number2 >> number3 >> number4 >> c1 >> c2;

	Shape s1;

	s1.printShape();
	cout << endl;

	Shape s2(number1, number2, c1);

	s2.printShape();
	cout << endl;

	Shape s3;

	s3.set(number3, number4, c2);

	s3.printShape();
	cout << endl;

	Shape s4;
	s4 = s2 + s3;

	s4.printShape();
	cout << endl;

	Shape s5;
	s5 = s3 * 3;

	s5.printShape();
	cout << endl;

	return 0;
}

