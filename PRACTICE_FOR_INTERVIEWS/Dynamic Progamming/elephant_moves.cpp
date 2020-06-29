#include<bits/stdc++.h>
using namespace std;
///a elephant has to reach at N-1,N-1 cell of a grid where he can move any number of steps to reach the right and bottom cell
int elephants_moves(int n)
{
    vector<vector<int> > dp(n,vector<int> (n,0));
    dp[0][0] =1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<j;k++)
            {
                dp[i][j]+= dp[i][k];
            }
            for(int k=0;k<i;k++)
            {
                dp[i][j] += dp[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n-1][n-1];

}
int main()
{
    int n;
    cin>>n;
    cout<<elephants_moves(n);
    return 0;
}

/*

4
1 1 2 4
1 2 5 12
2 5 14 37
4 12 37 106
106

*/
