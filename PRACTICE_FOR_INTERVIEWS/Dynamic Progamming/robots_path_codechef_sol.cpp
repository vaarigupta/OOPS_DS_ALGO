#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
	int m,n,p;
	cin>>m>>n>>p;

	vector<vector<ll> > matrix(m,vector<ll>(n,-1)),dp(m,vector<ll> (n));
	for(int i=0;i<p;i++)
	{
		int x,y;
		cin>>x>>y;

		matrix[x-1][y-1]=0;
	}

	if(matrix[0][0]==0 || matrix[m-1][n-1]==0)
		cout<<0;

	else if(m>1 && n>1 && (matrix[m-2][n-1]==0 || matrix[m-1][n-2]==0))
		cout<<0;

	else
	{
		dp[0][0]=1;
		for(int i=1;i<n;i++)
		{
			if(!matrix[0][i])
				dp[0][i]=0;

			else
				dp[0][i]=dp[0][i-1];
		}

		for(int i=1;i<m;i++)
		{
			if(!matrix[i][0])
				dp[i][0]=0;

			else
				dp[i][0]=dp[i-1][0];
		}

		for(int i=1;i<m;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(!matrix[i][j])
					dp[i][j]=0;

				else
				{
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
					dp[i][j]%=mod;
				}
			}
		}
		cout<<dp[m-1][n-1];
	}

	return 0;
}
