#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<int> > market)
{

    for(int i=0;i<market.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<market[i][j]<<" ";
        }
        cout<<endl;
    }
}
int min_cost( vector<vector<int> > &market, int N)
{
    int ans = INT_MAX;
    if(N==1)
    {
       int ans = min(min(min(market[0][0],ans), market[0][1]), market[0][2]);
       return ans;
    }
    for(int i=1;i<N;i++)
    {

        market[i][0] = min(market[i][0] + market[i-1][1] ,market[i][0] + market[i-1][2]);
        market[i][1] = min(market[i][1] +market[i-1][0],market[i][1] + market[i-1][2] );
        market[i][2] = min(market[i][2] + market[i-1][0],market[i][2] + market[i-1][1]);

    }
     ans = min(min(min(market[N-1][0],ans), market[N-1][1]), market[N-1][2]);
       return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int N;
        cin>>N;
        vector<vector<int> > market(N, vector<int> (3,0));
        for(int i =0;i<N;i++)
        {
            for(int j=0;j<3;j++)
            {
                int no;
                cin>>no;
                market[i][j] = no;
            }
        }

        cout<<min_cost(market,N)<<endl;
        print(market);
    }
    return 0;
}
/*
1
6
1 50 50
50 50 50
1 50 50
45 60 89
34 15 23
11 12 45


146
1 50 50
100 51 51
52 101 101
146 112 141
146 156 135
146 147 191


1
3
1 50 50
50 50 50
1 50 50
52
*/
