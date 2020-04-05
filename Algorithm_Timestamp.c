#include <stdio.h> 
#include <time.h>   
#include <Windows.h>
#include <stdlib.h>
#define val 2048
/**
   author: ucelebi
   Sorting timestamps while compilation may be changed due to current performance of CPU.
   timestamps had defined in milliseconds
   ------------     1x20   | 1x40    | 1x80    | 1x320   | 1x720    | 1x1024   | 1x2048
   bubble sort    : 0.0070 | 0.0090  | 0.0110  | 0.2400  | 0.3300   | 0.0390   | 0.0400 
   insertion sort : 0.0000 | 0.0010  | 0.0010  | 0.0020  | 0.0040   | 0.0050   | 0.0060
   selection sort : 0.0060 | 0.0070  | 0.0070  | 0.0080  | 0.0070   | 0.0060   | 0.0070
   quick sort     : 0.0000 | 0.0000  | 0.0000  | 0.0000  | 0.0010   | 0.0010   | 0.0020
   merge sort     : 0.0000 | 0.0000  | 0.0000  | 0.0000  | 0.0000   | 0.0000   | 0.0020
  */
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		swap(&arr[min_idx], &arr[i]);
	}
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];  
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[2048], R[2048];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d %d", arr[i] , i);
	printf("\n");
}
void initSortingAlgorithmTimestamp() {
	int i;
	clock_t t1, t2;
	srand(time(NULL));
	int myArray[val];
	for (int i = 0; i < val; i++)
	{
		myArray[i] = rand() % 1000;
		printf("Random: %d\n", myArray[i]);
	}
	t1 = clock();
	int n = sizeof(myArray) / sizeof(myArray[0]);
	mergeSort(myArray,0, n-1);
	t2 = clock();
	printf("Sorted array: \n");
	float diff = ((float)(t2 - t1) / 1000000.0F) * 1000;
	printArray(myArray, n);
	printf("%f", diff); 
}

int main(){
	initSortingAlgorithmTimestamp();
	_getch();
	return 0;
}