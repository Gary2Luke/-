#include <stdio.h>
#include <iostream>
using namespace std;

void print_merge(int a[], int n){	
	printf("¹é²¢ÅÅÐò½á¹û£º");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
	printf("\n");
}

void mergeSortIteration(int arr[], int tmp[], int left, int right) {
	int* a = arr;
	int* b = tmp;
	int seg, start;
	int len = right - left + 1;
	for (seg = 1; seg < len; seg += seg) {
		for (start = 0; start < len; start += seg + seg) {
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int* temp = a;
		a = b;
		b = temp;
	}
	
	if (a != arr) {
		int i;
		for (i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	
}



void merge(int a[], int tmp[], int left, int mid, int right){
	int i = left, j = mid + 1, k = left;
	while(i <= mid && j <= right){
		tmp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
	}
	while(i <= mid)
		tmp[k++] = a[i++];
	while(j <= right)
		tmp[k++] = a[j++];

	for(k = left; k <= right; k++)
		a[k] = tmp[k];

}

void mergeSortRecursion(int a[], int tmp[], int left, int right){
	if(left == right)
		return;
	int mid = left + (right - left) / 2;
	mergeSortRecursion(a, tmp, left, mid);
	mergeSortRecursion(a, tmp, mid+1, right);
	merge(a, tmp, left, mid, right);
}

void mergeSort(int a[], int n){
	int tmp[10];
	mergeSortRecursion(a, tmp, 0, n-1);
	//mergeSortIteration(a, tmp, 0, n-1);
	print_merge(a, n);
}

