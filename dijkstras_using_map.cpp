#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, map<int,int> > read(int , map<int, map<int, int> > );
map<int, int> dijkstras(int, int, map<int, map<int, int> > , map<int, int>);
void display(map<int,int>, int);
int minm(int, int);

int main()
{
	int n, source, dest;
	cout<<"Enter no of vertices: ";
	cin>>n;
	cout<<"\nEnter Source Node: ";
	cin>>source;
	
	map <int, int> dist;
	map <int, map<int,int> > cost;
	
	cout<<"\nEnter Cost Matrix: \n";
	cost = read(n, cost);

	dist = dijkstras(n, source, cost, dist);
	//cout<<"\nEnter Destination: ";
	//cin>>dest;
	//cout<<"\nDistance from "<<source<<" to "<<dest<<" is: "<<dist[dest];
	cout<<"\n";
	display(dist, source);
	
	return 0;
}

//function to read cost matrix
map<int, map<int,int> > read(int n, map<int, map<int, int> > cost)
{
	int value;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin>>value;
			cost[i][j] = value;
		}
	}
	return cost;
}

//function to display shortest distance
void display(map<int,int> dist, int source)
{
	map<int, int> :: iterator itr;
	cout<<"Source	 | Destination 	|  Distance\n";
	for(itr = dist.begin(); itr != dist.end(); ++itr)
	{
		cout<<source <<" 	 |	"<<itr->first << "    	| 	"<< itr->second<<"\n";	
	}	
}

//function to find minimum of two values
int minm(int a, int b)
{
	return ((a>b)?b:a);
}

//dijkstras algorithm
map <int, int> dijkstras(int n, int source, map<int, map<int, int> > cost, map<int, int> dist)
{
	int w, min;
	map<int, int> visited;
	for(int i = 1; i <= n; i++)
	{
		visited[i] = 0;
		dist[i] = cost[source][i];
		
	} 
	
	visited[source] = 1;
	
	for(int i = 1; i <= n-1 ; i++)
	{
		min = 9999;
		for(int j = 1; j <= n; j++)
		{
			if((visited[j] == 0) && (min > dist[j]))
			{
				min = dist[j];
				w = j;
			}
		}
		
		visited[w] = 1;
		for(int v = 1; v <= n; v++)
		{
			if(visited[v] == 0)
				dist[v] = minm(dist[v],cost[w][v]+dist[w]);
		}
	}
	
	return dist;
}

