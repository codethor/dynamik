#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    			int graph[4][4],start=0,min_path=INT_MAX;
    			cout<<"Enter the cost: "<<endl;
    			for(int i=0;i<4;i++)
        			for(int j=0;j<4;j++)
            				cin>>graph[i][j];
    			vector<int>vertex;
    			for(int i=0;i<4;i++)
    			{
        			if(i!=start)
            			vertex.push_back(i);
    			}
    			do
    			{
        			int current_pathcost=0,temp=start;
        			for(int i=0;i<vertex.size();i++)
        			{
            				current_pathcost+=graph[temp][vertex[i]];
            				temp=vertex[i];
        			}
        			current_pathcost+=graph[temp][start];
        			min_path=min(min_path,current_pathcost);
    			} while (next_permutation(vertex.begin(),vertex.end()));
    			cout<<"optimal path for travelling with minimum cost: "<<min_path<<endl;
    			return 0;
}

/*
INPUT
Enter teh cost:
0
10
15
20
5
0
9
10
6
13
0
12
8
8
9
0

OUTPUT
minimum cost for travelling: 35

*/
