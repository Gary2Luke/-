#include <stdio.h>
#include <iostream>
using namespace std;

void print_cockTail(int a[], int n){	
	printf("鸡尾酒排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
	printf("\n");
}

void exch(int a[], int i, int j)        // 交换A[i]和A[j]
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void cockTailSort(int a[], int n){		
	int left = 0, right = n - 1;
	while(left < right){
		for(int i = 0; i < right; i++){
			if(a[i] > a[i+1])
				exch(a, i, i+1);
		}
		right--;
		for(int j = right; j > left; j--){
			if(a[j] < a[j-1])
				exch(a, j, j-1);
		}
		left++;
	}
	print_cockTail(a, n);
}

