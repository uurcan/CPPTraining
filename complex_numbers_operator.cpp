#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double r = 0, double i = 0) {
		real = r;
		imag = i;
	}
	Complex operator - (Complex const& obj1) {
		Complex obj2;
		obj2.real = real - obj1.real;
		obj2.imag = imag - obj1.imag;
		return obj2;
	}
	const Complex operator* (const Complex& rhs)
	{
		Complex result;
		result.real = real * rhs.real - imag * rhs.imag;
		result.imag = real * rhs.imag + imag * rhs.real;
		return result;
	}
	friend ostream& operator<< (ostream& out, const Complex& c) {

		out  << c.real << (c.imag < 0 ? "-" : "+") << abs(c.imag) << "i" << endl;
		return out;

	}

	friend istream& operator>> (istream& in, Complex& c) {
		char splitter = 'i';
		in >> c.real >> c.imag >> splitter;
		return in;

	}
	const Complex operator+ (const Complex& rhs) {

		Complex result = *this;
		result += rhs;
		return result;

	}
	Complex& operator+= (const Complex& rhs) {

		real += rhs.real;
		imag += rhs.imag;
		return *this;

	}
private:
	double real;
	double imag;

};






int main()
{
	Complex c1;

	cin >> c1;

	Complex c2(c1);

	Complex c3;

	cin >> c3;

	Complex c4, c5;

	c4 = c2 + c3;
	c5 = c2 * c3;

	cout << c1 << c2 << c3 << c4 << c5;


	return 0;
}



