#include <stdio.h>
#include <iostream>
using namespace std;

// ���� ------------ �ڲ��Ƚ�����
// ���ݽṹ --------- ����
// ���ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼��������Ԫ�أ�����ÿ�ζ�����С��������ÿ��ֻ���ֳ���һ�������У���Ҫ����n-1�λ��ֲ��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(n^2)
// ����ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼����ʹ���־��ȣ�ֻ��Ҫlogn�λ��־��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(logn)��O(n),��Ҫ�ǵݹ���ɵ�ջ�ռ��ʹ��(��������left��right�Ⱦֲ�����),ȡ���ڵݹ��������
//                   һ��ΪO(logn),���ΪO(n)����������������
// �ȶ��� ---------- ���ȶ�


void print_quick(int A[], int n){
	
	printf("������������");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
	printf("\n");
}

int partition(int a[], int left, int right){
	int standard = a[right], tail = left - 1;
	for(int i = left; i <= right; i++){
		if(a[i] <= standard){
			++tail;
			swap(a[i], a[tail]);
		}
	}
	return tail;
}

void quick(int a[], int left, int right){
	if(left < right){
		int index = partition(a, left, right);
		quick(a, left, index - 1);
		quick(a, index+1, right);
	}

}
void quickSort(int a[], int n){
	quick(a, 0, n-1);
	print_quick(a, n);
}	



