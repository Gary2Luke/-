#include <stdio.h>
#include <iostream>
using namespace std;

void print_heap(int a[], int n){	
	printf("¶ÑÅÅÐò½á¹û£º");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
	printf("\n");
}


void heapify(int a[], int heapSize, int i){
	int left = 2 * i + 1, right =  2 * i + 2;
	int largest = i;
	if(left < heapSize && a[left] > a[largest])
		largest = left;
	if(right < heapSize && a[right] > a[largest])
		largest = right;
	if(i != largest){
		swap(a[largest], a[i]);
		heapify(a, heapSize, largest);
	}
}

void buildHeap(int a[], int n){
	for(int i = (n-1) / 2; i >= 0; i--)
		heapify(a, n, i);
}

void heapSort(int a[], int n){
	buildHeap(a, n);
	int heapSize = n;
	for(int i = n-1; i >= 1; i--){
		swap(a[0], a[i]);
		heapSize--;
		heapify(a, heapSize, 0);
	}
	print_heap(a, n);

	
}

