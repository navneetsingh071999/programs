#include <iostream>
#include <vector>
using namespace std;

void fillheight(int a[], int node, vector<int> child[], int mn)
{
	if(a[node] == -1)
	{
		return;
	}
	
	child[mn].push_back(a[node]);
	fillheight(a, a[node], child, mn);
}

int find_height(int a[], int n, int mn1, int mn2)
{

	vector<int> child[n];
	
	fillheight(a, mn1, child, mn1);
	fillheight(a, mn2, child, mn2);
	
	for(int i = 0; i < child[mn1].size(); i++)
	{
		for(int j = 0; j < child[mn2].size(); j++)
		{
			if(child[mn2][j] == child[mn1][i])
				return child[mn2][j];
		}
	}
	
	return -1;
}


int main()
{
	int n, mn1, mn2;
	cout<<"Enter no of nodes: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter parent array (-1 = root): \n";
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	cout<<"Enter two nodes: ";
	cin>>mn1>>mn2;
	
	cout<<"common ansestor: "<<find_height(a, n, mn1, mn2);
	return 0;
}
