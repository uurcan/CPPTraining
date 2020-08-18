#include "myVector.h"

template <typename T>
class iterator {
private:
	T* ptr;

public:
	explicit iterator(): ptr(nullptr){}
	explicit iterator(T* p): ptr(p){}
	iterator begin() const;
	iterator end() const;
};

template <typename T>
myVector<T>::myVector(int n)
	: numAllocated(n), arr(new T[n]), numUsed(0)
{
}

template <typename T>
int myVector<T>::add(T data)
{
	if (numUsed == numAllocated) {
		T* old = arr;
		arr = new T[numAllocated = numAllocated * 2];
		copy(old, old + numUsed, arr);
		delete[] old;
	}
	arr[numUsed++] = data;
	return numUsed;
}


template <typename T>
T myVector<T>::pop_back()
{
	return arr[numUsed-- - 1];
}


template <typename T>
int myVector<T>::size()
{
	return numUsed;
}

template <typename T>
T& myVector<T>::operator[](int index)
{

	if (index >= numUsed) {
		cout << "Error: Array index out of bound";
		exit(0);
	}

	return *(arr + index);
}
template <typename T>
void myVector<T>::print() {
	for (int i = 0; i < numUsed; i++){
		cout << arr[i] << endl;
	}
}

template <typename T>
void myVector<T>::getElement(int num) {
	int max = size();
	if (num < 0 || num > max){
		cout << "Array out of bounds" << endl;
	} else {
		cout << arr[num] << endl;
	}
}

template <typename T>
void myVector<T>::remove(int num) {
	int[] temp;
	int number = size();
	for (int i = 0; i < numUsed; i++)
	{
		if (arr[i] == num){ 
			arr[i] = arr[i-1]
		}
	}
	temp = arr[];//todo :: burayı incele..
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
