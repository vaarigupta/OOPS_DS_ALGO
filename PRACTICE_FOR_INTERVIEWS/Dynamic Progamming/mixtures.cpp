#include<iostream>
using namespace std;
long long dp[1000][1000];
long long sum(int i, int j, int *mixtures)
{
    long long result =0;
    for(int k=i;k<=j;k++)
    {
        result += mixtures[k];
        result %= 100;

    }
    return result;
}
long long min_smoke(int i, int j, int *mixtures)
{
    if(i>=j)
    {
        dp[i][j] =0;
        return 0;
    }
    if(dp[i][j]!= -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for(int k=i;k<=j;k++)
    {
        dp[i][j] = min(dp[i][j],min_smoke(i,k,mixtures) + min_smoke(k+1,j,mixtures) + sum(i,k,mixtures)*sum(k+1,j,mixtures));
    }
     return dp[i][j];

}
int main()
{
    int n;
    while((scanf("%d",&n))!=EOF)
    {
        int mixtures[1000];

        for(int i=0;i<n;i++)
        {
            cin>>mixtures[i];
        }
                for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]= -1;
            }
        }
        cout<<min_smoke(0,n-1,mixtures)<<endl;
    }
    return 0;
}

