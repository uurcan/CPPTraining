#include <iostream>
using namespace std;

class Rational {	
public:
	int numerator;
	int denominator;
	void reduction(void);
	Rational() {
		numerator = 1;
		denominator = 1;
		cout << "Constructor is called." << endl;
	}; 

	Rational(int n, int d) {
		numerator = n;
		denominator = d;
		reduction();

		cout << "Constructor is called." << endl;
	}; 

	Rational(const Rational& r) {
		numerator = r.numerator;
		denominator = r.denominator;
		cout << "Copy constructor is called." << endl;
	}; 

	Rational add(const Rational&);
	Rational multiply(const Rational&);
	void print();

};

Rational Rational::add(const Rational& r)
{
	return Rational((numerator * r.denominator) + (r.numerator * denominator),denominator * r.denominator);
}

Rational Rational::multiply(const Rational& r)
{
	return Rational((r.numerator * numerator), (r.denominator * denominator));
}
void Rational::print()
{
	cout << numerator << "/" << denominator << endl;
}
void Rational::reduction(void)
{
	int largest = numerator > denominator ? numerator : denominator;
	int gcd = 0; 

	for (int loop = 2; loop <= largest; ++loop)
		if (numerator % loop == 0 && denominator % loop == 0)
			gcd = loop;

	if (gcd != 0) {
		numerator /= gcd;
		denominator /= gcd;
	}
}
Rational addGlobal(const Rational& r1, const Rational& r2) {
	return Rational((r1.numerator * r2.denominator + r1.denominator * r2.numerator), (r1.denominator * r2.denominator));

}
Rational multiplyGlobal(const Rational& r1, const Rational& r2) {
	return Rational((r1.numerator * r2.numerator), (r1.denominator * r2.denominator));
}

int main()
{
	int a, b, c, d;

	cin >> a >> b;

	cin >> c >> d;

	Rational r1(a, b);

	r1.print();

	Rational r2(r1);

	r2.print();

	Rational r3(c, d);

	r3.print();

	Rational r4, r5, r6, r7;

	r4 = r3.add(r1);

	r5 = addGlobal(r3, r4);

	r6 = r2.multiply(r3);

	r7 = multiplyGlobal(r2, r6);

	r4.print();
	r5.print();
	r6.print();
	r7.print();

	return 0;
}



