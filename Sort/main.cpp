#include <stdio.h>
#include <iostream>
using namespace std;

void quickSort(int a[], int n);
void insertSort(int a[], int n);
void shellSort(int a[], int n);
void bubbleSort(int a[], int n);
void cockTailSort(int a[], int n);
void selectSort(int a[], int n);
void mergeSort(int a[], int n);
void heapSort(int a[], int n);
void countingSort(int a[], int n);
void radixSort(int a[], int n);
int main()
{
    int a[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };
    int n = sizeof(a) / sizeof(a[0]);
    //quickSort(a, n);
    //insertSort(a, n);
    //shellSort(a, n);
	//bubbleSort(a, n);
	//cockTailSort(a, n);
	//selectSort(a, n);
	mergeSort(a, n);
	//heapSort(a, n);
	//countingSort(a, n);
	//radixSort(a, n);
	system("pause");
    return 0;
}