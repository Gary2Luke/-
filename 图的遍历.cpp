/* C++: 邻接矩阵图 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100
class MatrixDG {
	private:
        char mVexs[MAX];    // 顶点集合
        int mVexNum;             // 顶点数
        int mEdgNum;             // 边数
        int mMatrix[MAX][MAX];   // 邻接矩阵

    public:
        // 创建图(自己输入数据)
		MatrixDG();
        // 创建图(用已提供的矩阵)
        MatrixDG(char vexs[], int vlen, char edges[][2], int elen);
		~MatrixDG();

        // 深度优先搜索遍历图
        void DFS();
        // 广度优先搜索（类似于树的层次遍历）
        void BFS();
        // 打印矩阵队列图
        void print();

	private:
        // 读取一个输入字符
        char readChar();
        // 返回ch在mMatrix矩阵中的位置
        int getPosition(char ch);        
        // 深度优先搜索遍历图的递归实现
        void DFS(int i, int *visited);

};

/* 
 * 创建图(自己输入数据)
 */
MatrixDG::MatrixDG()
{
    char c1, c2;
    int i, p1, p2;
    
    // 输入"顶点数"和"边数"
    cout << "input vertex number: ";
    cin >> mVexNum;
    cout << "input edge number: ";
    cin >> mEdgNum;
    if ( mVexNum < 1 || mEdgNum < 1 || (mEdgNum > (mVexNum * (mVexNum-1))))
    {
        cout << "input error: invalid parameters!" << endl;
        return ;
    }
    
    // 初始化"顶点"
    for (i = 0; i < mVexNum; i++)
    {
        cout << "vertex(" << i << "): ";
        mVexs[i] = readChar();
    }

    // 初始化"边"
    for (i = 0; i < mEdgNum; i++)
    {
        // 读取边的起始顶点和结束顶点
        cout << "edge(" << i << "): ";
        c1 = readChar();
        c2 = readChar();

        p1 = getPosition(c1);
        p2 = getPosition(c2);
        if (p1==-1 || p2==-1)
        {
            cout << "input error: invalid edge!" << endl;
            return ;
        }

        mMatrix[p1][p2] = 1;
    }
}

/*
 * 创建图(用已提供的矩阵)
 *
 * 参数说明：
 *     vexs  -- 顶点数组
 *     vlen  -- 顶点数组的长度
 *     edges -- 边数组
 *     elen  -- 边数组的长度
 */
MatrixDG::MatrixDG(char vexs[], int vlen, char edges[][2], int elen)
{
    int i, j, p1, p2;

    // 初始化"顶点数"和"边数"
    mVexNum = vlen;
    mEdgNum = elen;

	//将邻接矩阵初始化为0
    for(i = 0; i < mVexNum; i++)
		for(j = 0; j < mVexNum; j++)
			mMatrix[i][j] = 0;

    // 初始化"顶点"
    for (i = 0; i < mVexNum; i++)
        mVexs[i] = vexs[i];

    // 初始化"边"
    for (i = 0; i < mEdgNum; i++)
    {
        // 读取边的起始顶点和结束顶点
        p1 = getPosition(edges[i][0]);
        p2 = getPosition(edges[i][1]);

        mMatrix[p1][p2] = 1;
    }
}

/* 
 * 析构函数
 */
MatrixDG::~MatrixDG() 
{
}

/*
 * 返回ch在mMatrix矩阵中的位置
 */
int MatrixDG::getPosition(char ch)
{
    int i;
    for(i=0; i<mVexNum; i++)
        if(mVexs[i]==ch)
            return i;
    return -1;
}

/*
 * 读取一个输入字符
 */
char MatrixDG::readChar()
{
    char ch;

    do {
        cin >> ch;
    } while(!((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')));

    return ch;
}

/*
 * 深度优先搜索遍历图的递归实现
 */
void MatrixDG::DFS(int i, int *visited)
{
    int w;

    visited[i] = 1;
    cout << mVexs[i] << " ";
    // 遍历该顶点的所有邻接顶点。若是没有访问过，那么继续往下走
    for (w = 0; w <= mVexNum; w++)
    {
        if (mMatrix[i][w] == 1 && !visited[w])
            DFS(w, visited);
    }
       
}

/*
 * 深度优先搜索遍历图
 */
void MatrixDG::DFS()
{
    int i;
    int visited[MAX];       // 顶点访问标记

    // 初始化所有顶点都没有被访问
    for (i = 0; i < mVexNum; i++)
        visited[i] = 0;

    cout << "DFS: ";
    for (i = 0; i < mVexNum; i++)
    {
        //printf("\n== LOOP(%d)\n", i);
        if (!visited[i])
            DFS(i, visited);
    }
    cout << endl;
}

/*
 * 广度优先搜索（类似于树的层次遍历）
 !!!与树的遍历不同在于要在入队列时进行访问
 */
void MatrixDG::BFS()
{
    
	queue<int> q;     // 辅组队列
    int visited[MAX];   // 顶点访问标记
    int i, j;

    for (i = 0; i < mVexNum; i++)
        visited[i] = 0;

    cout << "BFS: ";
	for(int i = 0; i < mVexNum; i++){
		if(!visited[i]){
			visited[i] = 1;
			cout << mVexs[i] << " ";
			q.push(i);
		}
		while(!q.empty()){
			int tmp = q.front();
			q.pop();			
			for(j = 0; j < mVexNum; j++){
				if(mMatrix[tmp][j] == 1 && !visited[j]){
					visited[j] = 1;
					cout << mVexs[j] << " ";
					q.push(j);
				}
			}
		}
	}
	cout << endl;
}

/*
 * 打印矩阵队列图
 */
void MatrixDG::print()
{
    int i,j;
    cout << "Martix Graph:" << endl;
    for (i = 0; i < mVexNum; i++)
    {
        for (j = 0; j < mVexNum; j++)
            cout << mMatrix[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'B'}, 
        {'B', 'C'}, 
        {'B', 'E'}, 
        {'B', 'F'}, 
        {'C', 'E'}, 
        {'D', 'C'}, 
        {'E', 'B'}, 
        {'E', 'D'}, 
        {'F', 'G'}}; 
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    MatrixDG* pG;

    // 自定义"图"(输入矩阵队列)
    //pG = new MatrixDG();
    // 采用已有的"图"
    pG = new MatrixDG(vexs, vlen, edges, elen);

    pG->print();   // 打印图
    pG->DFS();     // 深度优先遍历
    pG->BFS();     // 广度优先遍历

	system("pause");
    return 0;
}
