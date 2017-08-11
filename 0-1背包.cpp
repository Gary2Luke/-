#include <iostream>
#include <math.h>
using namespace std;
 
 //物品数据结构
 typedef struct commodity
 {
	int value;  //价值
    int weight; //重量
  }commodity;

 const int N = 3;  //物品个数
 const int W = 50; //背包的容量
 
 //初始物品信息
 commodity goods[N+1]={{0,0},{60,10},{100,20},{120,30}};
 int select[N+1][W+1];		//最优解,select[i][j]中，j为背包容量， 选择一个给定物品i
 int main(){

//背包容量为0时，最大价值为0
for(int i = 0; i <= N; i++)
	 select[i][0] = 0;
 
 //初始没有物品时候，背包的价值为0
 for(int j = 0; j <= W; j++)
	 select[0][j] = 0;

 for(int i = 0; i <= N; i++){
	 for(int j = 0; j <= W; j++){
		 if(goods[i].weight <= j){	//当前物品i的重量小于等于w，进行选择
			select[i][j] = max(select[i-1][j], select[i-1][j-goods[i].weight] + goods[i].value);
		 }
		 else	//当前物品i的重量大于w，不选择
			 select[i][j] = select[i-1][j];
	 }
 }

 cout << "最佳结果为 ： " << select[N][W] << endl;


 //输出所选择的物品列表：
 int remainspace = W;
 for(int i =N; i >= 1; i--){
	 if(remainspace >= goods[i].weight){
		 if(select[i][remainspace] =  select[i-1][remainspace-goods[i].weight] + goods[i].value){
			cout << "item" << i << "is selected !" << endl;
			remainspace -= goods[i].weight;
		 }
	 }
 }

 system("pause");
 return 0;
 }
