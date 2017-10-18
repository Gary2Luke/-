#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> candidates = { 1, 2, 3 };		//数组candidates没有重复的数,求选取candidates数组中元素相加等于target的组合数,元素可以选择多次
	int target = 4;
	int n = candidates.size();
	sort(candidates.begin(), candidates.end());
	vector<int> dp(target + 1, 0);
	dp[0] = 1;

	for (int k = 0; k < n; k++) {
		for (int j = candidates[k]; j <= target; j++)
			dp[j] += dp[j - candidates[k]];
	}
	cout << dp[target] << endl;
	system("pause");
	return 0;
}
	
