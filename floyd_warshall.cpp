# include<bits/stdc++.h>
using namespace std;
const int INF = 99999 ;
int n,m;
int graph[405][405];
void floydWarshall ();
int main()
{
	  cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
            if(i!=j)
			graph[i][j] = INF;
            else
            graph[i][j] = 0;    
		}
	}
	for(int i=0;i<m;++i)
	{
		int x,y,w;  cin>>x>>y>>w;
		graph[x][y] = w;
	}

	floydWarshall();
}

void floydWarshall ()
{
    int i, j, k;
    for (k = 1; k <=n; k++)
    {
        for (i = 1; i <=n; i++)
        {
            for (j = 1; j <=n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    
    int q;  cin>>q;
	while(q--)
	{
		int x,y;  cin>>x>>y;
		if(graph[x][y]!=INF)
		cout<<graph[x][y]<<endl;
		else
		cout<<"-1"<<endl;
	}
}