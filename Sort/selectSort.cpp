#include <stdio.h>
#include <iostream>
using namespace std;

void print_select(int a[], int n){	
	printf("ѡ����������");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
	printf("\n");
}



void selectSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		int min = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[min])
				min = j;
		}
		if(min != i){
			int tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
	print_select(a, n);
}