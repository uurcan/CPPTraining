#include <iostream>
using namespace std;

class Base {
private:
	int number;
public:
	Base() {
	}
	Base(int num) {
		number = num;
	}
	virtual int getNumber() {
		return this->number;
	}
	void print(){
		cout << getNumber() << endl;
	}
	void message(){
		cout << "Base" << endl;
	}
};

class Derived : public Base{
private:
	int num1, num2;
public:
	Derived(int a, int b) : Base(b) {
		this->num1 = a;
		this->num2 = b;
	}
	virtual int getNum1() { return num1; }
	virtual int getNum2() { return num2; }
	void message() {
		cout << "Derived" << endl;
	}
};
int main()
{
	int i, j, k;

	cin >> i >> j >> k;

	Base* p;
	Base a(i);
	Base* b = &a;
	Derived c(j, k);
	Derived* d = &c;
	p = d;
	p->print();
	p->message();
	b->print();
	b->message();
	c.message();

	return 0;
}


