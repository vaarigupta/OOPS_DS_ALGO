#include<bits/stdc++.h>
using namespace std;
///a rat has to reach at N-1,N-1 cell of a grid for cheese but he can move only step to right and bottom cell
int rats_and_cheese_ways(int n)
{
    vector<vector<int> > dp(n,vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
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
    cout<<rats_and_cheese_ways(n);
    return 0;
}


/*

4
1 1 1 1
1 2 3 4
1 3 6 10
1 4 10 20
20
*/
