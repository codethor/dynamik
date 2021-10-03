#include<bits/stdc++.h>

using namespace std;

int grid(int arr[][5],int n)
{
	cout<<"============="<<endl;
	int sum[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
		sum[i][0] = 0;
		sum[0][i] = 0;
	}

	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			sum[x][y] = max(sum[x][y-1],sum[x-1][y]) + arr[x-1][y-1];
		}
	}
	for(int i=0;i<=5;i++)  
	{
		for(int j=0;j<=5;j++)
		{
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	return sum[n][n];

}
int main(int argc, char const *argv[])
{
	int arr[5][5]={{3,7,9,2,7},{9,8,3,5,5},{1,7,9,8,5},{3,8,6,4,10},{6,3,9,7,8}};
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int val = grid(arr,5);
	cout<<val<<endl;
	return 0;
}