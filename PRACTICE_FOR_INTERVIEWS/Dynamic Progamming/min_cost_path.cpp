#include<bits/stdc++.h>
using namespace std;
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
                dp[i][j] = dp[i][j-1] + matrix[i][j];
            }
            else if(j==0)
            {
                dp[i][j] = dp[i-1][j] + matrix[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
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
3 1 5
6 2 1
7 1 1

*/
