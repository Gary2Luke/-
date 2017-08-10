#include <stdio.h>
#include <iostream>
using namespace std;

void print_shell(int a[], int n){	
	printf("Ï£¶ûÅÅÐò½á¹û£º");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
	printf("\n");
}

void shellSort(int a[], int n){		
	int h = 0;
	while(h <= n){
		h = 3 * h + 1;
	}
	while(h >= 1){
		for(int i = h; i < n; i++){
			int guard = a[i], j = i - h;
			while(j >= 0 && a[j] > guard){
				a[j+h] = a[j];
				j -= h;
			}
			a[j+h] = guard;
		}
		h = (h - 1) / 3;
	}
	print_shell(a, n);
}

