#include <stdio.h>
#include <iostream>
using namespace std;

// 分类 ------------ 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- 每次选取的基准都是最大的元素（或者每次都是最小），导致每次只划分出了一个子序列，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
// 最优时间复杂度 ---- 每次选取的基准都能使划分均匀，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(logn)～O(n),主要是递归造成的栈空间的使用(用来保存left和right等局部变量),取决于递归树的深度
//                   一般为O(logn),最差为O(n)（基本有序的情况）
// 稳定性 ---------- 不稳定


void print_quick(int A[], int n){
	
	printf("快速排序结果：");
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



