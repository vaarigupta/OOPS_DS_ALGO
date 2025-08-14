#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int min_cost_path(vector<vector<int> > matrix, int r, int c)
{
    vector<vector<int> > dp(r,vector<int> (c,0));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {

            if(i==0 && j==0)
            {
                dp[i][j] = matrix[i][j];
            }
            else if(i==0)
            {
                int x = ((matrix[i][j-1]*matrix[i][j])%20==0)?(matrix[i][j-1]*matrix[i][j])+1:(matrix[i][j-1]*matrix[i][j])%20;
                dp[i][j] =  dp[i][j-1] + x;
            }
            else if(j==0)
            {
                int x = ((matrix[i-1][j]*matrix[i][j])%20==0)?(matrix[i-1][j]*matrix[i][j])+1:(matrix[i-1][j]*matrix[i][j])%20;
                dp[i][j] = dp[i-1][j] + x;
            }
            else
            {
                int a = ((matrix[i-1][j]*matrix[i][j])%20==0)?(matrix[i-1][j]*matrix[i][j])+1:(matrix[i-1][j]*matrix[i][j])%20;
                int x = dp[i-1][j] + a;
                int b = ((matrix[i][j-1]*matrix[i][j])%20==0)?(matrix[i][j-1]*matrix[i][j])+1:(matrix[i][j-1]*matrix[i][j])%20;
                int y = dp[i][j-1] + b;
                int c =  ((matrix[i-1][j-1]*matrix[i][j])%20==0)?(matrix[i-1][j-1]*matrix[i][j])+1:(matrix[i-1][j-1]*matrix[i][j])%20;
                int z = dp[i-1][j-1] +c;
                dp[i][j] = min(min(x,y),z);
            }
        }
    }
    for(int i=0;i<r;i++)
    {

        for(int j=0;j<c;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[r-1][c-1];
}
int main()
{
    vector<vector<int> > matrix;
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        vector<int> row;
        for(int j=0;j<c;j++)
        {
            int num;
            cin>>num;
            row.push_back(num);

        }
        matrix.push_back(row);
    }
    cout<<min_cost_path(matrix,r,c)<<endl;
    return 0;
}
/*
3 3
2 1 3
4 5 6
7 2 3

2 4 7
10 9 10
18 18 24

24

2 2
2 4
6 1
2 10
14 4
4


*/

