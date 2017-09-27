#include <iostream>
#include <vector>

using namespace std;

/*一维数组的最大和*/
int maxSubArray(vector<int> &nums){
	int n = nums.size(), temp_sum = 0, res = nums[0];
	for(int i = 0; i < n; i++){
		temp_sum += nums[i];
		res = max(res, temp_sum);
		temp_sum = max(temp_sum, 0);
	}
	return res;
}

/*二维数组的最大和
我们由第i行到第j行，然后求出每一列的从i到j的和，转化为一维数组，然后求这个数组的最大和
*/
int maxSubMatrix(vector<vector<int> > &nums){
	int rows = nums.size(), cols = nums[0].size();
	int res = nums[0][0];
	vector<int> sumOfCol(cols, 0);	//从i到j的每一列的和
	for(int i = 0; i < rows; i++){
		for(int m = 0; m < cols; m++)  //每次移动i的时候清除
			sumOfCol[m] = 0;

		for(int j = i; j < rows; j++){
			for(int k = 0; k < cols; k++){
				sumOfCol[k] += nums[j][k];
			}
			res = max(res, maxSubArray(sumOfCol));	//检查并更新最大值
		}
	}
	return res;
}

int main(){
	int a[4][4] = {{0, -2, -7, 0}, {9, 2, -6, 2}, {-4, 1, -4, 1}, {-1, 8, 0, -2}};
	vector<vector<int> > nums(4, vector<int>(4, 0));
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			nums[i][j] = a[i][j];

	int res = maxSubMatrix(nums);
	cout << res << endl;
	system("pause");
	return 0;
}
