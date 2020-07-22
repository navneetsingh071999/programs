#include <iostream>
#include <vector>
#include<map>
#define MAXN 1000
using namespace std;

int n;

map<int,map<int, int> > g;
 
bool cyclic(int v, vector<bool> visited, int parent)
{
	visited[v] = true;
	
	map<int, int> :: iterator j;
	for(j = g[v].begin(); j != g[v].end(); ++j)
	{
		if(!visited[j->second])
		{
			if(cyclic(j->second, visited, v))
				return true;	
		}
		
		else if (j->second != parent)
			return true;	
	}	
	return false;
} 
 
bool isCyclic()
{
	vector<bool> visited(n,false);
	
	for(int u = 0; u < n; u ++)
		if(!visited[u])
			if(cyclic(u, visited, -1))
				return true;
				
	return false;
}

int main()
{
	int a, b;

	
	cout<<"Enter no of Nodes: ";
	cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		cout<<"\nEnter N1 and N2: ";
		cin>>a>>b;
		if(!g[a][b] && !g[b][a])
		{
			g[a][b] = b;
			g[b][a] = a;
		}
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
	
	if(isCyclic())
	{
		cout<<"\nContains Cycle";
		
	}
	else
	{
		cout<<"\nNo Cycle";
	}
	
	return 0;
}

