#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
	int a[9] = {4, 2, 3, 6, 5, 4, 7, 2, 9};
	vector<int> nums;
	for(int i = 0; i < 9; i++)
		nums.push_back(a[i]);
	int n = nums.size();
	for(int i = 0; i < n; i++)
		cout << nums[i] << " ";
	cout << endl;
	stack<int> s;
	vector<int> res(n, -1);
	for(int i = 0; i < n; i++){
		while(!s.empty() && a[i] > a[s.top()]){
			res[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	for(int i = 0; i < n; i++)
		cout << res[i] << " ";

	system("pause");
	return 0;

}
