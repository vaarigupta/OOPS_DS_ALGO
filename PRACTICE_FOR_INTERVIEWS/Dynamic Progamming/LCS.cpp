#include<bits/stdc++.h>
using namespace std;

int LCS(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if(i==0 || j==0)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s[i-1]==t[j-1])
      return dp[i][j] = 1+ LCS(s,t,i-1,j-1,dp);

     return dp[i][j] = max(LCS(s,t,i-1,j,dp),LCS(s,t,i,j-1,dp));

}

int LCSBottomUp(string &s, string &t, int n, int m, vector<vector<int>> &dp)
{
    ///write the base case
     for(int j=0;j<=m;j++)
        dp[0][j] = 0;

     for(int i=0;i<=n;i++)
        dp[i][0] =0;


    ///write down changing parameter in opposite direction
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=m;j++)
         {
             ///copy the recurrence
             if(s[i-1]==t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
             else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
         }
     }
     return dp[n][m];
}

string PrintLCS(string &s, string &t, int n, int m, vector<vector<int>> &dp)
{

    int len = dp[n][m];
    string ans(len,'#');

    int i=n, j=m, index = len-1;
    while(i>0 && j>0)
    {
        if(s[i-1] == t[j-1])
        {
            ans[index] = s[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] >dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return ans;
}
int main()
{
    string input1 = "abcd";
    string input2 = "bcdee";

    int n = input1.size();
    int m = input2.size();

    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
   // int ans = LCS(input1, input2,n,m,dp);
    int ans = LCSBottomUp(input1, input2,n,m,dp);

    string lcs = PrintLCS(input1, input2,n,m,dp);
    cout<<ans<<" "<<lcs;
    return 0;
}
