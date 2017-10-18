#include<iostream>
#include<vector>
#include<string>

using namespace std;

void Permutation(string &str, int start) {
	if (start == str.size() - 1) {
		cout << str << " ";
		return;
	}
	for (int i = start; i < str.size(); i++) {
		if (i != start && str[i] == str[start]) {
			continue;
		}
		else {
			swap(str[i], str[start]);
			Permutation(str, start + 1);
			swap(str[i], str[start]);
		}
	}
}

void Combine(string& str, vector<char>& tmp, int len, int start) {
	if (len == 0) {
		for (int i = 0; i < tmp.size(); i++)
			cout << tmp[i];
		cout << " ";
		return;
	}
	for (int i = start; i < str.size(); i++) {
		tmp.push_back(str[i]);
		Combine(str, tmp, len - 1, i + 1);
		tmp.pop_back();
	}
}

void Combination(string &str) {
	vector<char> tmp;
	for (int i = 1; i <= str.size(); i++)
		Combine(str, tmp, i, 0);
}

int main() {
	string str = "abcd";
	cout << "字符串" << str << "的排列为 : " << endl;
	Permutation(str, 0);
	cout << endl;
	cout << "字符串" << str << "的组合为 : " << endl;
	Combination(str);
	cout << endl;
	system("pause");
	return 0;
}
