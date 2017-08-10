#include <stdio.h>
#include <iostream>
using namespace std;

const int dn = 3;	//排序元素为三位数及以下
const int k = 10;	//基数为10
int c[k];

void print_radix(int a[], int n){	
	printf("基数排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
	printf("\n");
}

int getdigit(int num, int d){	//得到数字num的第d位数字
	if(d <= 0)
		return num % 10;
	while(--d)
		num /= 10;
	return num % 10;
}

void countSort(int a[], int n, int d){
	for(int i = 0; i < k; i++)
		c[i] = 0;
	for(int i = 0; i < n; i++)
		c[getdigit(a[i], d)]++;
	for(int i = 1; i < k; i++)
		c[i] += c[i-1];
	int *b = (int *)malloc(n * sizeof(int));
	for(int i = n-1; i >= 0; i--){
		b[c[getdigit(a[i], d)] - 1] = a[i];
		c[getdigit(a[i], d)]--;
	}
	for(int i = 0; i < n; i++)
		a[i] = b[i];

	free(b);
}
void radixSort(int a[], int n){
	for(int d = 1; d <= dn; d++){
		countSort(a, n, d);
	}
	print_radix(a, n);
}

