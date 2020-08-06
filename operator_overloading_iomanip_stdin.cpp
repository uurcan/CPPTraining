#include <iostream>
using namespace std;

#include <iomanip>
using namespace std;


tm when;

class Time {
private:
	int hour, minute, second;
public:
	Time() { hour = 23; minute = 59; second = 59; }
	Time(const Time& t) {
		hour = t.hour;
		minute = t.minute;
		second = t.second;
	}
	friend ostream& operator<<(ostream& os, const Time& x);
	Time& operator++(); //prefix increment
	Time& operator--(); //prefix decrement
	Time operator++(int); //postfix increment
	Time operator--(int); //postfix decrement
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }

	friend istream& operator >> (istream& is, Time& t) {
		cin >> t.hour >> t.minute >> t.second;
		return is;
	}

	Time& operator +=(int n) {
		second += n;
		checkHour();
		return *this;
	}
	Time& operator -=(int n) {
		second -= n;
		checkHour();
		return *this;
	}

	void checkHour() {
		if (second >= 60) {
			minute += 1;
			second -= 60;
		}

		if (minute >= 60) {
			hour += 1;
			minute -= 60;
		}

		if (hour >= 24) {
			hour -= 24;
		}

		if (second < 0) {
			minute -= 1;
			second = (60 + second);
		}
		if (minute < 0) {
			hour -= 1;
			minute = 59;
		}
		if (hour < 0) {
			minute = 59;
			hour = 23;
		}
	}
};
Time &Time::operator++() {//prefix
	++second;
	checkHour();
	return *this;
}
Time& Time::operator--() {//prefix
	--second;
	checkHour();
	return *this;
}
Time Time::operator++(int)//postfix
{
	Time temp = *this;
	second++;
	return temp;
}
Time Time::operator--(int)//postfix
{
	Time temp = *this;
	second--;
	return temp;
}
ostream& operator << (ostream& os, const Time& t) {
	os << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.minute << ":" << setw(2) << t.second;
	return os;
}

int main()
{
	Time t1;

	cin >> t1;

	cout << t1 << endl;

	Time t2(t1);

	cout << t2 << endl;

	t2 -= 15;

	cout << t2 << endl;

	cout << --t2 << endl;

	cout << t2-- << endl;

	cout << t2 << endl;


	t2 += 40;

	cout << t2 << endl;

	cout << ++t2 << endl;

	cout << t2++ << endl;

	cout << t2 << endl;

	return 0;
}