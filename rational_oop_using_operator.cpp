#include <iostream>
#include <fstream>

using namespace std;

ofstream outfile("output1.txt");
ifstream fileReader;

class Rational
{
private:
	int n;
	int d;
public:
	void reduction(void);
	Rational() {}
	Rational(int a, int b) {
		n = a;
		d = b;
	}
	Rational(const Rational& r) {
		n = r.n;
		d = r.d;
		outfile << "Copy constructor is called." << endl;
	};

	friend istream& operator >> (istream& is, Rational& r) {
		char slash = '/';
		is >> r.n >> slash >> r.d;
		return is;
	}
	friend ostream& operator << (ostream& os, Rational& r)
	{
		r.reduction();
		os << r.n << "/" << r.d << endl;
		return os;
	}
	const Rational operator+ (const Rational& r) const {
		int t = n * r.d + d * r.n;
		int b = d * r.d;
		return Rational(t, b);
	}
	Rational operator *(Rational& s) {
		return Rational(s.n * n, s.d * d);
	}
	void print(void);

	const Rational operator++(int) {
		n += d;
		return Rational(n, d);
	}
	const Rational operator--(int) {
		n -= d;
		return Rational(n, d);
	}

};
void Rational::reduction(void)
{
	int largest = n > d ? n : d;
	int gcd = 0;

	for (int loop = 2; loop <= largest; ++loop)
		if (n % loop == 0 && d % loop == 0)
			gcd = loop;

	if (gcd != 0) {
		n /= gcd;
		d /= gcd;
	}
}
void Rational::print()
{
	outfile << n << "/" << d << endl;
}
int main()
{
	fileReader.open("input1.txt");

	Rational r1, r2;

	fileReader >> r1 >> r2;

	outfile << r1 << r2;

	Rational r3(r1);

	r3.print();

	Rational r4, r5, r6, r7;

	r4 = r2 + r3;

	r5 = r2 * r3;

	outfile << r4 << r5;

	r4++;

	outfile << r4;

	r5--;

	outfile << r5;

	outfile.close();
	fileReader.close();
	return 0;
}



