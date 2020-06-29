#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
///a rat has to reach at N-1,N-1 cell of a grid for cheese but he can move only step to right and bottom cell
int robots_and_paths(int m, int n, int p , vector<vector<int> >blocked)
{
    vector<vector<int> > dp(m,vector<int> (n,0));
    for(int i=0;i<p;i++)
    {
        int x = blocked[i][0];
        int y = blocked[i][1];
        dp[x][y] = -1;
        if(x==0)
        {
            for(int k=y;k<n;k++)
            {
                dp[x][k] =-1;
            }
        }
        if(y==0)
        {
            for(int k=x;k<m;k++)
            {
                dp[k][y] =-1;
            }
        }
    }
    if(dp[0][0]== -1 || dp[m-1][n-1])
    {
        return 0;
    }
    dp[0][0] =1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || j==0)
            {
                if(dp[i][j]!= -1)
                {
                    dp[i][j] = 1;
                }

            }
            else
            {
                if(dp[i][j]!= -1)
                {
                    if(dp[i-1][j]!= -1 && dp[i][j-1]!= -1)
                    {
                         dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
                    }
                    else if(dp[i-1][j]!= -1)
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else if (dp[i][j-1]!= -1)
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                    else
                    {
                        return 0;
                    }

                }

            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m-1][n-1];

}
int main()
{
    int m,n,p;
    cin>>m>>n>>p;
    vector<vector<int> > blocked;
    for(int i=0;i<p;i++)
    {
        int x,y;
        cin>>x>>y;
        blocked.push_back({x-1,y-1});
    }
    cout<<robots_and_paths(m,n,p,blocked);
    return 0;
}

