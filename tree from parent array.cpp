#include <iostream>
using namespace std;

struct Node
{
	int key;
	struct Node * left, * right;
};

Node  * newNode(int key1)
{
	Node * temp = new Node;
	temp->key = key1;
	temp->left = temp->right = NULL;
	return (temp);
}


void fillheight(int a[], int node, Node * created[], Node ** root)
{
	if(created[node] != NULL)
	{
		return;	
	}	
	
	created[node] = newNode(node);
	
	if(a[node] == -1)
	{
		*root = created[node];
		return;
	}
	
	if(created[a[node]] == NULL)
	{
		fillheight(a, a[node], created, root);
	}
	
	Node * p = created[a[node]];
	
	if(p->left == NULL)
	{
		p->left = created[node];
	}
	else
		p->right = created[node];
	
}

Node * createtree(int a[], int n)
{
	Node * created[n];
	for(int i = 0; i < n; i++)
	{
		created[i] = NULL;
	}
	
	Node * root = NULL;
	for(int i = 0; i < n; i++)
	{
		fillheight(a, i, created, &root);
	}
	
	return root;
}

void inorder(Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->key << " "; 
        inorder(root->right); 
    } 
} 

int main()
{
	
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	
	Node *root = createtree(a, n);
	//cout<<root->key;
	inorder(root);
	
}
