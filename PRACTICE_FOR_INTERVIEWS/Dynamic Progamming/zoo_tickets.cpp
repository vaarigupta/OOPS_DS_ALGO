#include<bits/stdc++.h>
using namespace std;
int max_price(vector<int> p, int n, int k)
{
    if(k==0)
      {
          return 0;
      }
    vector<int> ans(k+1,0);
      for(int i=1; i<=k; i++)
      {
        ans[i] = p[i];
      }
      //cout<<"for i = "<<1<<" , min price :="<<ans[1]<<endl;
      for(int i=2; i<=k; i++)
      {
          //cout<<"for i = "<<i<<endl;
           for(int j=1; j<i; j++)
           {
            if(p[i-j] == -1  || ans[j] == -1)
             continue;
            ans[i] = (ans[i]== -1)?ans[j] + p[i-j]:min(ans[i], ans[j] + p[i-j]);
           }
      }
    return ans[k];

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    vector<int> prices;
    prices.push_back(0);
    for(int i=1;i<=k;i++)
    {
        int p;
        cin>>p;
        prices.push_back(p);
    }
    cout<<max_price(prices,n,k)<<endl;
    }

    return 0;
}

/*

2
3 5
-1 -1 4 5 -1
5 5
1 2 3 4 5

1
3 5
2 -1 4 5 -1

1
3 5
2 -1 4 5 -1
for i = 1 , min price :=2
for i = 2
for j = 1 , min price :=4
for i = 3
for j = 2 , min price :=4
for i = 4
for j = 1 , min price :=5
for j = 3 , min price :=5
for i = 5
for j = 1 , min price :=7
for j = 2 , min price :=7
for j = 4 , min price :=7
7

*/

