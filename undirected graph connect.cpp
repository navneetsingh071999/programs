#include <iostream>
#include <vector>
#include <list>
using namespace std;

int n;

void addNode(vector<int> g[], int a, int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}

bool dfs1(vector<int> g[], vector<bool> visit1, int u)
{
	visit1[u] = true;
	for(int i = 0; i < g[u].size(); i++)
	{
		if(!visit1[g[u][i]])
			if(dfs1(g, visit1, g[u][i]))
				return true;
	}
	
	for(int i = 0; i <n ; i++)
	{
		if(!visit1[i])
			return false;
	}
	return true;
}


bool connected(vector<int> g[])
{
	vector<bool> visit1(n, false);
	
	for(int i = 0; i < n; i++)
	{
		if(!visit1[i])
		{
			if(dfs1(g, visit1, i))
				return true;
			else
				break;
		}
	
	}
	
	return false;
}

int main()
{
	cout<<"\nEnter No of Nodes: ";
	cin>>n;
	vector<int> g[n];
	int a, b, e;
	cout<<"\nEnter No of edges: ";
	cin>>e;
	
	for(int i = 0; i < e; i++)
	{
		cout<<"\nEnter N1 and N2: ";
		cin>>a>>b;
		
		addNode(g, a, b);
	}
	
	if(connected(g))
	{
		cout<<"connected";
	}
	else
	{
		cout<<"Not connected";
	}
	
		
	return 0;
}
