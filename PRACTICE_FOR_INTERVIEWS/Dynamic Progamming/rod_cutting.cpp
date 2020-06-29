#include<bits/stdc++.h>
using namespace std;
int max_price(vector<int> prices, int n)
{

    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int ans = INT_MAX;
        cout<<"for i = "<<i<<endl;
        for(int j=0;j<i;j++)
        {
            ans = min(ans, prices[j] + dp[i-j-1]);
            cout<<"for j= "<<j<<" , max price "<<ans<<endl;
            dp[i] = ans;
        }
    }
    for(int i=0;i<=n;i++)
    {
        cout<<i<<" => "<<dp[i]<<endl;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int> prices;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        prices.push_back(p);
    }
    cout<<max_price(prices,n);
    return 0;
}

/*

8
1 5 8 9 10 17 17 20
22



8
1 5 8 9 10 17 17 20
for i = 1
for j= 0 , max price 1
for i = 2
for j= 0 , max price 2
for j= 1 , max price 5
for i = 3
for j= 0 , max price 6
for j= 1 , max price 6
for j= 2 , max price 8
for i = 4
for j= 0 , max price 9
for j= 1 , max price 10
for j= 2 , max price 10
for j= 3 , max price 10
for i = 5
for j= 0 , max price 11
for j= 1 , max price 13
for j= 2 , max price 13
for j= 3 , max price 13
for j= 4 , max price 13
for i = 6
for j= 0 , max price 14
for j= 1 , max price 15
for j= 2 , max price 16
for j= 3 , max price 16
for j= 4 , max price 16
for j= 5 , max price 17
for i = 7
for j= 0 , max price 18
for j= 1 , max price 18
for j= 2 , max price 18
for j= 3 , max price 18
for j= 4 , max price 18
for j= 5 , max price 18
for j= 6 , max price 18
for i = 8
for j= 0 , max price 19
for j= 1 , max price 22
for j= 2 , max price 22
for j= 3 , max price 22
for j= 4 , max price 22
for j= 5 , max price 22
for j= 6 , max price 22
for j= 7 , max price 22
0 => 0
1 => 1
2 => 5
3 => 8
4 => 10
5 => 13
6 => 17
7 => 18
8 => 22
22
*/
