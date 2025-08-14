///https://www.codechef.com/problems/MINEAT
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool possible_case(ll N, ll H, vector<ll> piles, ll k)
{
    ll hrs = 0;
    for(ll i=0;i<N;i++)
    {
        hrs += ceil((double) piles[i]/k);
    }
     if(hrs>H)
    {
        return false;
    }
    return true;

}
ll min_K(ll N, ll H,ll sum, vector<ll> piles)
{
    ll s= 1, e = sum,ans = INT_MAX;
    while(s<=e)
    {
        ll mid = (s+e)/2;
        if(possible_case(N,H,piles,mid))
        {
            ans = min(mid,ans);
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return ans;


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll N,H,sum;
        cin>>N>>H;
        vector<ll> piles;
        for(ll i=0;i<N;i++)
        {
            ll b;
            cin>>b;
            sum +=b;
            piles.push_back(b);
        }
        cout<<min_K(N,H,sum,piles)<<endl;

    }
    return 0;
}

/*
3
3 3
1 2 3
3 4
1 2 3
4 5
4 3 2 7
*/
