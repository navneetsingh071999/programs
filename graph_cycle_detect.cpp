#include <iostream>
#include <vector>
#include<map>
#define MAXN 1000
using namespace std;

int n;
 
bool cyclic(int v, vector<bool> visited, int parent, vector<int> g[])
{
	visited[v] = true;

	for(int j = 0; j != g[v].size(); j++)
	{
		if(!visited[g[v][j]])
		{
			if(cyclic(g[v][j], visited, v, g))
				return true;	
		}
		
		else if (g[v][j] != parent)
			return true;	
	}	
	return false;
} 
 
bool isCyclic(vector<int> g[])
{
	vector<bool> visited(n,false);
	
	for(int u = 0; u < n; u ++)
		if(!visited[u])
			if(cyclic(u, visited, -1, g))
				return true;
				
	return false;
}

int main()
{
	int a, b, e;

	
	cout<<"Enter no of Nodes: ";
	cin>>n;
	
	vector<int> g[n];
	
	cout<<"\nEnter no of Edges: ";
	cin>>e;
	
	for(int i = 0; i < e; i++)
	{
		cout<<"\nEnter N1 and N2: ";
		cin>>a>>b;
		
		g[a].push_back(b);
		g[b].push_back(a);
	}
//	map<int,int> :: iterator j;
//	for(int i = 0; i < n; i++)
//	{
//		for(j = g[i].begin(); j != g[i].end(); ++j)
//		{
//			cout<<j->second<<" ";
//		}
//		cout<<"\n";
//	}
	
	if(isCyclic(g))
	{
		cout<<"\nContains Cycle";
		
	}
	else
	{
		cout<<"\nNo Cycle";
	}
	
	return 0;
}

