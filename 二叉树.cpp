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

/*�ݹ����*/
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

/*�ǵݹ����*/
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

/*Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ�����P���������Ӻ��Һ��ӣ������ֱ�ӷ�������
����P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣�����������������
��P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�*/
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

/*������ȱ���*/
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

/*�����������Ĳ���*/
void InsertNode(Node *&root, int key){		//��������������
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

/*������������Ѱ�ҽڵ�x����һ���ڵ�*/
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

/*��������������*/
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

/*����������ɾ���ڵ�*/
void DeleteNode(Node *&root, int key){
	if(!root)
		return;
	Node *x = SearchNode(root, key);	//����Ҫɾ���Ľڵ�
	if(!x)
		return;
	Node *p = (!x->left || !x->right) ? x : SearchSuccessor(x);		//ʵ����Ҫɾ���Ľڵ㣬���ڵ�x���Һ��Ӷ���Ϊ�գ���ɾ��������ʵ�ǽڵ�x����һ���ڵ�
	Node *son = p->left ? p->left : p->right;		//Ҫɾ���ڵ�ĺ��ӽڵ㣬����ʵ��Ҫɾ���Ľڵ����϶�ֻ��һ�����ӻ���û�к��ӣ�

	if(son)
		son->parent = p->parent;

	if(!p->parent)
		root = son;

	else if(p->parent->left == p)
		p->parent->left = son;
	else
		p->parent->right = son;
	
	if(p->val != x->val)			//��Ҫɾ���Ľڵ㲻���������Ľڵ㣬������ֵ
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

	cout<< "ǰ�����" << endl;
	Preorder(bst);
	cout << endl;
	Preorder1(bst);
	cout << endl;
	
	cout<< "�������" << endl;
	Inorder(bst);
	cout << endl;
	Inorder1(bst);
	cout << endl;
	
	cout<< "�������" << endl;
	Postorder(bst);
	cout << endl;	
	Postorder1(bst);
	cout << endl;
	
	cout<< "������ȱ���" << endl;
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
