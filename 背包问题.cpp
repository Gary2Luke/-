#include<iostream> 
#include<algorithm> 
#include<vector>
#include<stdio.h>
using namespace std;


int main() {
	int n = 4, v = 10;			//n为物品个数， v为背包容量
	vector<int> w = { 0, 2, 3, 4, 7 };	//w[i]代表第i件物品的重量,i从1到n
	vector<int> c= {0, 1, 3, 5, 9};	//c[i]代表第i件物品的价值，i从1到n
	
	vector<int> dp(v + 1, 0);	//表示价值

	/*0-1背包：每种物品只有一件，可以选择放或者不放*/	
	for (int i = 1; i <= n; i++)
		for (int j = v; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + c[i]);

	printf("0-1背包，最大价值为 ： %d\n", dp[v]);

	/*完全背包：每种物品有无限件*/
	for (int i = 1; i <= n; i++) 
		for (int j = w[i]; j <= v; j++) 
			dp[j] = max(dp[j], dp[j - w[i]] + c[i]);

	printf("完全背包，最大价值为 ： %d\n", dp[v]);

	/*多重背包问题：第i种物品最多有s[i]件
	多重背包用二维数组解决？？*/
	vector<vector<int> > f(n + 1, vector<int>(v + 1, 0));
	vector<int> s = { 0, 1, 1, 1, 0 };	//s[i]代表第i件物品的限制数量，i从1到n
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= v; j++) {
			for (int k = 0; k <= s[i]; k++) {
				if (j - k * w[i] >= 0) {
					tmp = f[i - 1][j - k*w[i]] + k*c[i];
					f[i][j] = max(f[i][j], tmp);
				}
				else
					break;
			}
		}
	}
	printf("多重背包，最大价值为 ： %d\n", f[n][v]);

	system("pause");
	return 0;
}
