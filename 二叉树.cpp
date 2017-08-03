#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node{
	int val;
	Node *left, *right, *parent;
	Node(int x):
	val(x), left(NULL), right(NULL), parent(NULL){}
};

/*递归遍历*/
void Preorder(Node *root){
	if(!root)
		return;
	cout << root->val << '\t';
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node *root){
	if(!root)
		return;
	Inorder(root->left);
	cout << root->val << '\t';
	Inorder(root->right);
}

void Postorder(Node *root){
	if(!root)
		return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->val << '\t';
}

/*非递归遍历*/
void Preorder1(Node *root){
	if(!root)
		return;
	stack<Node*> s;
	Node *p = root;
	while(p || !s.empty()){
		while(p){
			s.push(p);
			cout << p->val << '\t';
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}

void Inorder1(Node *root){
	if(!root)
		return;
	stack<Node*> s;
	Node *p = root;
	while(p || !s.empty()){
		while(p){
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			cout << p->val <<'\t';
			p = p->right;
		}

	}
}

/*要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；
或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。若非上述两种情况，
则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。*/
void Postorder1(Node *root){
	if(!root)
		return;
	stack<Node*> s;
	s.push(root);
	Node *cur, *pre = NULL;
	while(!s.empty()){
		cur = s.top();		
		if((!cur->left && !cur->right) || (pre && (cur->left == pre || cur->right == pre)) ){
			cout << cur->val << '\t';
			s.pop();
			pre = cur;
		}
		else{
			if(cur->right)
				s.push(cur->right);
			if(cur->left)
				s.push(cur->left);
		}

	}
}

/*广度优先遍历*/
void BFS(Node *root){
	if(!root)
		return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *p = q.front();
		q.pop();
		cout << p->val << '\t';
		if(p->left)
			q.push(p->left);
		if(p->right)
			q.push(p->right);
	}
}

/*二叉搜索树的插入*/
void InsertNode(Node *&root, int key){		//构建二叉搜索树
	Node *tmp = new Node(key);
	if(!root){
		root = tmp;
		return;
	}
	Node *p = root, *parent = NULL;
	while(p){
		if(key < p->val){
			parent = p;
			p = p->left;
		}
		else{
			parent = p;
			p = p->right;
		}
	}
	tmp->parent = parent;
	if(key < parent->val)
		parent->left = tmp;
	else
		parent->right = tmp;


	
}

/*二叉搜索树中寻找节点x的下一个节点*/
Node *SearchSuccessor(Node *x){				
	if(!x)
		return NULL;
	if(x->right){
		Node *p = x->right;
		while(p->left)
			p = p->left;
		return p;
	}
	Node *p = x->parent;
	while(p && p->right == x){
		x = p;
		p = p->parent;		
	}
	return p;
}

/*搜索二叉搜索树*/
Node* SearchNode(Node* root, int key){
	if(!root)
		return NULL;
	while(root){
		if(key == root->val)
			return root;
		else if(key < root->val)
			root = root->left;
		else
			root = root->right;
	}
	return root;
}

/*二叉搜索树删除节点*/
void DeleteNode(Node *&root, int key){
	if(!root)
		return;
	Node *x = SearchNode(root, key);	//搜索要删除的节点
	if(!x)
		return;
	Node *p = (!x->left || !x->right) ? x : SearchSuccessor(x);		//实际上要删除的节点，若节点x左右孩子都不为空，则删除掉的其实是节点x的下一个节点
	Node *son = p->left ? p->left : p->right;		//要删除节点的孩子节点，（事实上要删除的节点最后肯定只有一个孩子或者没有孩子）

	if(son)
		son->parent = p->parent;

	if(!p->parent)
		root = son;

	else if(p->parent->left == p)
		p->parent->left = son;
	else
		p->parent->right = son;
	
	if(p->val != x->val)			//若要删除的节点不是搜索到的节点，交换数值
		x->val = p->val;

	delete(p);
	
}

int main()
{
	Node *bst = NULL;
	int a[] = {15,6,18,3,7,17,20,2,4,13,9};
	int i;
	int len = sizeof(a)/sizeof(a[0]);
	cout << len << endl;
	for(i=0;i<len;i++) 
		InsertNode(bst,a[i]);

	cout<< "前序遍历" << endl;
	Preorder(bst);
	cout << endl;
	Preorder1(bst);
	cout << endl;
	
	cout<< "中序遍历" << endl;
	Inorder(bst);
	cout << endl;
	Inorder1(bst);
	cout << endl;
	
	cout<< "后序遍历" << endl;
	Postorder(bst);
	cout << endl;	
	Postorder1(bst);
	cout << endl;
	
	cout<< "广度优先遍历" << endl;
	BFS(bst);
	cout << endl;
	
	for(i=0;i<len;i++) {
		DeleteNode(bst,a[i]);
		Inorder(bst);
		cout << endl;
	}
	

	system("pause");
	return 0;
}
