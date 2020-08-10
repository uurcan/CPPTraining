
#include <iostream>
using namespace std;


void printRepetitiveElements(int set[],int n) {

	for (int i = 0; i < n; i++) {

		int count = 0;
		for (int j = 0; j < i; j++) {
			if (set[i] == set[j]) 
				count++;
		}

		if (count == 0) {
			int count = 1;
			for (int j = i + 1; j < 8; j++) {
				if (set[i] == set[j]) count++;
			}
			if(count >= 2)
				cout << set[i] << " ";
		}
	}
	cout << endl;
}
void printRepetitiveElements(double set[], int n) {
	for (int i = 0; i < n; i++) {

		int count = 0;
		for (int j = 0; j < i; j++) {
			if (set[i] == set[j])
				count++;
		}

		if (count == 0) {
			int count = 1;
			for (int j = i + 1; j < 8; j++) {
				if (set[i] == set[j]) count++;
			}
			if (count >= 2)
				cout << set[i] << " ";
		}
	}
	cout << endl;
}
void printRepetitiveElements(char set[], int n) {
	for (int i = 0; i < n; i++) {

		int count = 0;
		for (int j = 0; j < i; j++) {
			if (set[i] == set[j])
				count++;
		}

		if (count == 0) {
			int count = 1;
			for (int j = i + 1; j < 8; j++) {
				if (set[i] == set[j]) count++;
			}
			if (count >= 2)
				cout << set[i] << " ";
		}
	}
	cout << endl;
}
int main()
{
	int b1[8];
	double d1[5];
	char c1[7];

	int i = 0;


	while (i < 8)
	{
		cin >> b1[i];
		i++;
	}
	i = 0;
	while (i < 5)
	{
		cin >> d1[i];
		i++;
	}
	i = 0;
	while (i < 7)
	{
		cin >> c1[i];
		i++;
	}

	printRepetitiveElements(b1, 8);
	printRepetitiveElements(d1, 5);
	printRepetitiveElements(c1, 7);

	return 0;
}

