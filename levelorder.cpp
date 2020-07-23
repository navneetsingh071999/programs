#include <iostream>

using namespace std;

int fillheight(int a[], int node, int depth[])
{
		
	if(a[node] == -1)
	{
		//depth[node] = 1;
		return 1;
	}
	
	if(depth[node] != -1)
		return depth[node];
	
	

	depth[node] = fillheight(a, a[node], depth) + 1;
	
	return depth[node];
}

int find_height(int a[], int n)
{
	int depth[n];
	for(int i = 0; i < n; i++)
	{
		depth[i] = -1;
	}
	
	int ht = 0;
	for(int i = 0; i < n; i++)
		ht = max(ht, fillheight(a, i, depth));
		

	cout<<endl;
	for(int i = 1; i <= ht ; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(depth[j] == -1)
			{
				depth[j]+=2;
			}
				if(depth[j] == i)
					cout<<j<<" ";
			
		}
		cout<<endl;
	}
	return ht;
		
}


int main()
{
	int n;
	cout<<"Enter no of nodes: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter parent array (-1 = root): \n";
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	cout<<"\nheight is: "<<find_height(a, n);
	return 0;
}
