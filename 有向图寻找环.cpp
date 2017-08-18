/*利用深度优先遍历在有向图中寻找环，并且打印环中元素*/

#include <iostream>
#include <vector>

using namespace std;

void dfsVisit(vector<vector<int> >&graph, int i, vector<int>&visit, vector<int>&father){	
    int n = graph.size();
    visit[i] = 1; 
    for(int j = 0; j < n; j++){
        if(graph[i][j] == 1){
            if(visit[j] == 1){		//找到一个环
                int tmp = i;
                cout<<"cycle: ";
                while(tmp != j){                
                    cout << tmp << " ";					
                    tmp = father[tmp];
                }
                cout<<tmp<<endl;				
            }
            else if(visit[j] == 0){            
                father[j] = i;
                dfsVisit(graph, j, visit, father);
            }
        }
	}
    visit[i] = 2;		//相当于以i为根节点的这个子树已经遍历完毕，visit[i]变为2 
}
 
void dfs(vector<vector<int> >&graph){
    int n = graph.size();		//graph为有向图的邻接矩阵，n为顶点数
    vector<int> visit(n, 0);	//visit分为三种状态:未遍历的节点为0， 遍历过为1， 以该节点为根的全部节点都遍历完为2
    vector<int> father(n, -1);	// father[i] 记录遍历过程中i的父节点
    for(int i = 0; i < n; i++)
        if(visit[i] == 0)
            dfsVisit(graph, i, visit, father);
}

int main() {
	vector<vector<int> > graph(5, vector<int>(5, 0));  //创建一个5个节点的树，并初始化为0
	graph[0][1] = 1;
	graph[1][2] = 1;
	graph[2][3] = 1;
	graph[3][0] = 1;
	//graph[3][0] = 1;		//这个环中环的问题有待解决。。。。。。。

	dfs(graph);
	system("pause");
	return 0;
}
