
#include <iostream>
using namespace std;

class Y
{
public:
	Y() {
		this->num1 = 4;
		this->num2 = 5;
		this->c1 = '*';
		this->c2 = 'a';
	}
	Y(int num1, int num2, char c1, char c2) {
		this->num1 = num1;
		this->num2 = num2;
		this->c1 = c1;
		this->c2 = c2;
	}

	void set(int a1, int b1, char c1, char c2) {
		this->num1 = a1;
		this->num2 = b1;
		this->c1 = c1;
		this->c2 = c2;
	}

	friend ostream& operator<< (ostream& out, const Y& c) {
		int k = 2 * c.num2 - 2;
		for (int i = 0; i < c.num1; i++)
		{
			for (int j = 0; j < k; j++)
				cout << " ";

			k = k - 1;

			for (int j = 0; j <= i; j++) {
				cout << c.c1 << " ";
			}

			for (int j = c.num1+1; j <= c.num1 + c.num2; j++)
			{
				if (i == 0 || i == c.num1 - 1 || j == c.num2 || j == c.num2 + c.num1)
					cout << c.c2;
				else
					cout << " ";
			}
			int a = 1;
			for (int j = c.num2 + c.num1; j < i + c.num1 + c.num2; j++)
			{
				if (i == c.num1-1 || i == j) {
					cout << " ";
				}
				else {
					cout << a++;
				}
			}
			cout << endl;
		}
		return out;
	}
private:
	int num1, num2;
	char c1, c2;
};

int main()
{
	int number1, number2;;
	char c1, c2;

	cin >> number1 >> number2;
	cin >> c1 >> c2;

	Y y1;

	cout << y1;
	cout << endl;

	Y y2(number1, number2, c1, c2);

	cout << y2;
	cout << endl;

	Y y3;

	y3.set(number1 + 2, number2 + 1, c2, c1);

	cout << y3;
	cout << endl;

	return 0;

}



