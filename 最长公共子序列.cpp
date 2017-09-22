#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/*说明:找出两个字符串的最长公共字串。子串是连续的
	动态规划方案：使用dp[i][j]表示以x[i]和y[j]结尾的最长公共子串的长度，因为子串是连续的，所以，对于x[i]与y[j]来讲，
	它们要么与之前的公共子串构成新的公共子串；要么不构成。故状态转移方程为：
	（1） X[i] == Y[j], dp[i][j] = dp[i - 1][j - 1] + 1;
   （2） X[i] != Y[j], dp[i][j] = 0
	   对于初始化，i == 0或者j == 0, 如果x[i] = y[j], dp[i][j] = 1; 否则dp[i][j] = 0;
	   */

void LCS(const string X, const string Y) {
	int m = X.size(), n = Y.size();
	if (m == 0 || n == 0)
		return;
	vector<vector<int> > dp(m, vector<int>(n, 0));
	int maxLen = 0, index = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (X[i] == Y[j]) {
				if (i > 0 && j > 0)
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = 1;
			}
			if (dp[i][j] > maxLen) {
				maxLen = dp[i][j];
				index = i - maxLen + 1;
			}
		}
	}
	if (maxLen == 0)
		return;
	cout << "最长公共字串为 ： " << X.substr(index, maxLen) << endl;
}


/*最长公共子序列
说明：相比于最长公共子串，差别在于公共子序列不要求数组中的元素连续。
接着，依然假设m[i, j]表示 X[i]结尾的子串 和Y[j]结尾的子串的 最长公共子序列的长度。那么:
若X[i] == Y[j]，dp[i,j] = dp[i-1][j-1] + 1；
若X[i] != Y[j]，dp[i,j] = Max(dp[i-1][j], dp[i][j-1])。
*/
void LCSseq(const string X, const string Y) {
	int m = X.size(), n = Y.size();
	if (m == 0 || n == 0)
		return;
	vector<vector<int> > dp(m, vector<int>(n, 0));
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (X[i] == Y[j]) {
				if (i > 0 && j > 0)
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = 1;
			}
			else {
				if (i == 0 && j == 0)
					continue;
				else if (i > 0 && j > 0)
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				else {
					if (i > 0)
						dp[i][j] = dp[i - 1][j];
					else
						dp[i][j] = dp[i][j - 1];
				}
			}			
		}
	}
	cout << "最长公共子序列长度为 ： " << dp[m - 1][n - 1] << endl;

}

int main() {
	string X = "nbibhellonjhao", Y = "nihellojd";
	LCS(X, Y);
	LCSseq(X, Y);
	system("pause");
	return 0;
}
