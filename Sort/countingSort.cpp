#include <stdio.h>
#include <iostream>
using namespace std;

void print_counting(int a[], int n){	
	printf("计数排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
	printf("\n");
}



void countingSort(int a[], int n){
	const int k = 10;		//基数为10
	int c[k];
	for(int i = 0; i < k; i++)
		c[i] = 0;
	for(int i = 0; i < n; i++)
		c[a[i]]++;
	for(int i = 1; i < k; i++)
		c[i] += c[i-1];
	int *b = (int *)malloc(n * sizeof(int));
	for(int i = n-1; i >= 0; i--){
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
	for(int i = 0; i < n; i++)
		a[i] = b[i];

	free(b);
	print_counting(a, n);

	
}

