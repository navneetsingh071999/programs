#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

int n;

void addnode(vector<int> g[], int a, int b)
{

	g[a].push_back(b);
	g[b].push_back(a);

}


bool bfs(int src, int dest, int dist[], int prec[], vector<int> g[])
{
	vector<bool> visit(n, false);
	list<int> q;
	

	for(int i = 0; i < n; i++)
	{
		//visit[i] = false;
		dist[i] = INT_MAX;
		prec[i] = -1;
	}
	
	visit[src] = true;
	dist[src] = 0;
	q.push_back(src);
	
	while(!q.empty())
	{
		int u = q.front();
		
		q.pop_front();
	//	map<int, int> :: iterator i;
		 for (int i = 0; i < g[u].size(); i++) 
		{
//			cout<<i->second;
			if(visit[g[u][i]] == false)
			{
				visit[g[u][i]] = true;
				dist[g[u][i]] = dist[u] + 1;
				prec[g[u][i]] = u;
				q.push_back(g[u][i]);
			
			
			if(g[u][i] == dest)
				return true;
			}
		}
	}

	return false;
}

void print_short(vector<int> g[], int src, int dest)
{
	int dist[n];
	int prec[n];
	
	if(bfs(src, dest, dist, prec, g) == false)
	{
		cout<<"\nSource and Destination are not connected:\n";
		return;
	}
	
	vector<int> path;
	int node = dest;
	path.push_back(node);
	while(prec[node] != -1)
	{
		path.push_back(prec[node]);
		node = prec[node];
	}
	
	
	cout<<"\nShortest path length is: "<<dist[dest];
	cout<<"\nPath is: \n";
	for(int i = path.size()-1; i >= 0; i--)
	{
		cout<<path[i]<<"->";
	}
	cout<<"\n";
}


int main()
{

	cout<<"Enter no of nodes:";
	cin>>n;
	vector<int> adj[n];
	int a,b, e;
	cout<<"\nEnter nof of Edges: ";
	cin>>e;
	for(int i = 0; i < e; i++)
	{
		cout<<"\nEnter N1 and N2: ";
		cin>>a>>b;
		addnode(adj, a, b);
	}

//	addnode(adj, 0, 1); 
//	addnode(adj, 0, 3); 
//	addnode(adj, 1, 2); 
//	addnode(adj, 3, 4); 
//	addnode(adj, 3, 7); 
//	addnode(adj, 4, 5); 
//	addnode(adj, 4, 6); 
//	addnode(adj, 4, 7); 
//	addnode(adj, 5, 6); 
//	addnode(adj, 6, 7); 
	
	int src, dest;
	
	cout<<"\nEnter Source and Destination: ";
	cin>>src>>dest;
	
	print_short(adj, src, dest);
	
	return 0;
}
