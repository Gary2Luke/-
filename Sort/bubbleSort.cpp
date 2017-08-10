#include <stdio.h>
#include <iostream>
using namespace std;

void print_bubble(int a[], int n){	
	printf("Ã°ÅÝÅÅÐò½á¹û£º");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
	printf("\n");
}


void bubbleSort(int a[], int len){
	for(int i = 0; i < len - 1; i++){
		for(int j = 0; j < len - i - 1; j++){
			if(a[j] > a[j+1]){
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
	print_bubble(a, len);
}

