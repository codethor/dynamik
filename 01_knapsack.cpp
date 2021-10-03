#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> &values,vector<int> &weights,int W)
{
	int n = values.size();
	int dp[n+1][W+1];

	for(int k=0;k<=n;k++)
	{
		for(int x=0;x<=W;x++)
		{
			if(x == 0 || k == 0)
				dp[k][x] = 0;
			else if(x - weights[k-1] >= 0)
				dp[k][x] = max(dp[k-1][x],values[k-1] + dp[k-1][x - weights[k-1]]);
			else
				dp[k][x] = dp[k-1][x];
		}
	}
	return dp[n][W];
}


int main()
{
	vector<int> weights = {10,20,30};
	vector<int> values = {60,100,120};
	cout<<"maximum value of the given weight = "<<knapsack(values,weights,50)<<endl;
	return 0;
}