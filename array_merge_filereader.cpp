#include <iostream>
#include <fstream>

using namespace std;

ofstream outfile("output1.txt");
ifstream fileReader;

void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void swap(double* xp, double* yp) {
	double temp = *xp;
	*xp = *yp;
	*yp = temp;
}
int* sortArray(int* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}	
	}
	return array;
}
double* sortArray(double* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
	return array;
}
void printArrayElements(int* a1, int aCount1) {
	for (int i = 0; i < aCount1; i++) {
		outfile << a1[i] << " ";
	} outfile << endl;
}

void printArrayElements(double* a1, int aCount1) {
	for (int i = 0; i < aCount1; i++) {
		outfile << a1[i] << " ";
	} outfile << endl;
}

void inputArrayElements(int* a1, int aCount1) {
	int num;
	for (int i = 0; i < aCount1; i++) {//input read function
		fileReader >> a1[i];
	}
}

void inputArrayElements(double* a1, int aCount1) {
	double num;
	for (int i = 0; i < aCount1; i++) {//input read function
		fileReader >> a1[i];
	}
}
int* merge(int* a1, int aCount1, int* a2, int aCount2) {
	int* container = new int[aCount1+aCount2];
	int j, k;
	for (int i = 0; i < aCount1; i++)
	{
		container[i] = a1[i];
	}
	for (j =0,k = aCount1; j<aCount2 && k<aCount1+aCount2;j++,k++ )
	{
		container[k] = a2[j];
	}
	int* sorted = sortArray(container, aCount1 + aCount2);
	return sorted;
}
double* merge(double* a1, int aCount1, double* a2, int aCount2) {
	double* container = new double[aCount1 + aCount2];
	int j, k;
	for (int i = 0; i < aCount1; i++)
	{
		container[i] = a1[i];
	}
	for (j = 0, k = aCount1; j < aCount2 && k < aCount1 + aCount2; j++, k++)
	{
		container[k] = a2[j];
	}
	double* sorted = sortArray(container, aCount1 + aCount2);
	return sorted;
}

int main()
{
	fileReader.open("input1.txt");

	int aCount1, bCount1;
	int aCount2, bCount2;

	fileReader >> aCount1 >> aCount2;

	int* a1 = new int[aCount1];
	int* a2 = new int[aCount2];

	inputArrayElements(a1, aCount1);
	inputArrayElements(a2, aCount2);

	fileReader >> bCount1 >> bCount2;

	double* b1 = new double[bCount1];
	double* b2 = new double[bCount2];

	inputArrayElements(b1, bCount1);
	inputArrayElements(b2, bCount2);

	int* newI = merge(a1, aCount1, a2, aCount2);
	double* newD = merge(b1, bCount1, b2, bCount2);

	printArrayElements(newI, aCount1 + aCount2);
	printArrayElements(newD, bCount1 + bCount2);

	outfile.close();
	fileReader.close();
	return 0;
}
