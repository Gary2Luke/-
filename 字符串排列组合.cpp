#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*字符串排列*/
void Permutation(string &str, int start){
	if(start == str.size() - 1){
		cout << str << " ";
		return;
	}
	for(int i = start; i < str.size(); i++){
		if(i != start && str[i] == str[start])
			continue;
		swap(str[i], str[start]);	
		Permutation(str, start+1);
		swap(str[i], str[start]);	
	}
}

/*字符串组合，字符串组合只适用于字符串各个元素不相等时的情况*/
void Help(string &str, vector<char> &tmp, int len, int index){
	if(len == 0){
		for(int i = 0; i < tmp.size(); i++)
			cout << tmp[i];
		cout << " ";
		return;
	}
	if(index == str.size())
		return;
	tmp.push_back(str[index]);
	Help(str, tmp, len-1, index+1);
	tmp.pop_back();
	Help(str, tmp, len, index+1);

}

void Combination(string &str){
	vector<char> tmp;
	for(int i = 1; i <= str.size(); i++)
		Help(str, tmp, i, 0);
}
int main(){
	string str = "abc";
	//Permutation(str, 0);
	Combination(str);
	system("pause");
	return 0;
}
