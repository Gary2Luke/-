#include <stdio.h>
#include <iostream>
using namespace std;

void print_insert(int a[], int n){	
	printf("²åÈëÅÅĞò½á¹û£º");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
	printf("\n");
}



void insertSort(int a[], int n){
	for(int i = 1; i < n; i++){
		int get = a[i], j = i - 1;
		while(j >= 0 && a[j] > get){
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = get;
	}
	print_insert(a, n);
}

