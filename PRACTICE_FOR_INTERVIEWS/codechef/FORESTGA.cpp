///https://www.codechef.com/problems/FORESTGA
#include<bits/stdc++.h>
#define ll long long
#define INF 1000000000000000002LL
using namespace std;
bool is_possible(ll N, ll W, ll L, vector<pair<ll,ll> > tree, ll mid)
{
    long double wood =0;
    for(int i=0;i<N;i++)
    {
        long double height = tree[i].first + (tree[i].second*mid);
        if(height>=L)
        {
            wood += height;
        }
    }
    if(wood>=W)
    {
        return true;
    }
    return true;
}
ll min_months(ll N, ll W, ll L,vector<pair<ll,ll> > tree)
{

    ll s=0LL;
    ll e = INF;
    ll ans = INT_MAX;
    while(s<=e)
    {
        ll mid = (s+e)/2;
        if(is_possible(N,W,L,tree,mid))
        {
            ans = mid;
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
    ll N,W,L;
    ll month = INT_MIN;
    cin>>N>>W>>L;
    vector<pair<ll,ll> > tree;
    for(int i=0; i<N;i++)
    {
        ll h,g;
        cin>>h>>g;
        tree.push_back(make_pair(h,g));

    }
    cout<<min_months(N,W,L,tree);

}
