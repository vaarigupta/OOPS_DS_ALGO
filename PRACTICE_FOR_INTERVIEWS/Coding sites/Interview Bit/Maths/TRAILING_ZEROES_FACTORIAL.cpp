#include<bits/stdc++.h>
using namespace std;
int trailingZeroes(int n)
{
    long long int zeroes = 0,p=1;
    long long int ans = floor(n/5);
    while(ans!=0)
    {
       zeroes += ans;
       p *= 5;
       ans = floor(n/(5*p));
    }
    return zeroes;
}
/// log(n) time complexity
int trailingZeroesGfg(int n)
{
    int cnt = 0;
    for(int i=5;(n/i)>=1;i *= 5)
    {
        cnt += (n/i);
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    cout<<trailingZeroesGfg(n);
    return 0;
}
