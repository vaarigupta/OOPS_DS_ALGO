#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int dp[100][100] = {0};
    cout<<"1\t"<<endl;
    dp[0][0] = 1;
    for(int i=2;i<=n;i++)
    {
       for(int j=1;j<=i;j++)
       {
           if(j==1 || j==i)
           {
               dp[i][j] =1;
                cout<<"1\t";
           }
            else
            {
                int num = dp[i-1][j] + dp[i-1][j-1];
                dp[i][j] = num;
                cout<<num<<"\t";
            }
       }
       cout<<endl;
    }
    return 0;
}






