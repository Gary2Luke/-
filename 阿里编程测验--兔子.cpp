/**
1. 猎人把一对兔子婴儿(一公一母称为一对)放到一个荒岛上，两年之后，它们生下一对小兔，之后开始每年都会生下一对小兔。生下的小兔又会以同样的方式继续繁殖。
2. 兔子的寿命都是x(x>=3)年，并且生命的最后一年不繁殖。
3. 如果岛上的兔子多于10对，那么猎人会每年在兔子们完成繁殖或者仙逝之后，从岛上带走两对最老的兔子。
请问y年(y>=3)后荒岛上所有的兔子加起来多少岁?(注意, 在条件3执行完之后)
 
输入: 从命令行输入两行整数，第一行是x，第二行是y
输出: y年后荒岛上所有的兔子岁数的总和
**/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
	int x, y;
	cin >> x >> y;
	deque<int> dq;
	dq.push_back(0);
	int curyear = 1;
	for(curyear = 1; curyear <= y; curyear++){
		for(int i = 0; i < dq.size(); i++)		//所有兔子先涨一岁
			++dq[i];

		while(!dq.empty()){					//去掉仙逝的兔子
			if(dq.front() >= x)
				dq.pop_front();
			else
				break;
		}

		for(int i = 0; i < dq.size(); i++){		//新生小兔子
			if(dq[i] >= 2)
				dq.push_back(0);
		}

		if(dq.size() > 10){
			dq.pop_front();
			dq.pop_front();
		}

		cout << "curyear =" << curyear << endl;
		int count = 0;
		for(int i = 0; i < dq.size(); i++)
			count += dq[i] * 2;
		cout << count << endl;
	}

	int count = 0;
	for(int i = 0; i < dq.size(); i++)
		count += dq[i] * 2;
	cout << count << endl;
	system("pause");
    return 0;
}
