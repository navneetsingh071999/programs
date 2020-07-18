#include <iostream>
#include <map>
#include <vector>
using namespace std;

//function declearation
void display(int, int[][3], map<int,vector<int> > pgno, map<int,int> nobook);
void decission(int, int, int, int a[][3]);

//global variables
map <int, vector<int> > pgno;
map <int, int> nobook; 

int main()
{
	int no_self, no_query, qType, sNum;
	cin>>no_self;
	cin>>no_query;
	int a[no_query][3]; // input array
	
	//input for question
	for(int i = 0; i < no_query; i++)
	{
		cin>>qType;
		cin>>sNum;
		decission(i, qType, sNum, a);
	}
	
	display(no_query, a, pgno, nobook);
	
}

void decission(int i, int qType, int sNum, int a[][3])
{
	a[i][0] = qType;
	a[i][1] = sNum;
	if(qType == 1)
		{
			cin>>a[i][2];
			pgno[sNum].push_back(a[i][2]);
			
			if(!nobook[sNum])
			{
				nobook[sNum] = 1;
			}
			else
			{
				nobook[sNum]++;
			}
		}
		else if(qType == 2)
		{
			cin>>a[i][2];
		}	
		else if(qType == 3)
		{
			a[i][2] = 0;
		}
}


void display(int no_query, int a[][3], map<int,vector<int> > pgno, map<int,int> nobook)
{
	for(int i = 0; i < no_query; i++)
	{
		if(a[i][0] == 2)
		{
			cout<<pgno[a[i][1]][a[i][2]];cout<<"\n";	
		}
		if(a[i][0] == 3)
		{
			cout<<nobook[a[i][1]];	
		}
		
	}	
}
