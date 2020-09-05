#include "myVector.h"

template <typename T>
myVector<T>::myVector(int n) : numAllocated(n), arr(new T[n]), numUsed(0) {}

template <typename T>
void myVector<T>::add(T data)
{
	if (numUsed >= numAllocated) {
		cout << "Out of space." << endl;
		return;
	}
	if (numUsed == numAllocated) {
		T* old = arr;
		arr = new T[numAllocated = numAllocated * 2];
		copy(old, old + numUsed, arr);
		delete[] old;
	}
	arr[numUsed++] = data;
}

template <typename T>
int myVector<T>::size()
{
	return numUsed;
}

template <typename T>
void myVector<T>::print() {
	for (int i = 0; i < numUsed; i++) {
		cout << arr[i] << " ";
	} cout << endl;
}

template <typename T>
void myVector<T>::getElement(int num) {
	int max = size();
	if (num < 0 || num > max) {
		cout << "Out of space." << endl;
	}
	else {
		cout << arr[num] << endl;
	}
}
template <typename T>
myVector<T>::~myVector() {

}
template <typename T>
void myVector<T>::remove(T s) {
	int i;
	for (i = 0; i < numUsed; i++) {
		if (arr[i] == s) {
			break;
		}
	}
	numUsed -= 1;
	if (i < numUsed) {
		for (int j = i; j < numUsed; j++) {
			arr[j] = arr[j + 1];
		}
	}
}
int main()
{
	int vector_size;
	cin >> vector_size;
	myVector <char> vec(vector_size);

	char temp;
	for (int i = 0; i < vector_size; i++)
	{
		cin >> temp;
		vec.add(temp);
	}

	vec.add('c');


	vec.print();

	vec.getElement(-1);
	vec.getElement(vec.size() + 2);


	cin >> vector_size;
	myVector <int> vec2(vector_size);
	int temp2;
	for (int i = 0; i < vector_size; i++)
	{
		cin >> temp2;
		vec2.add(temp2);
	}

	vec2.print();

	vec2.remove(2);

	cout << "After element-wise deletion:" << endl;
	vec2.print();
	return 0;
}
