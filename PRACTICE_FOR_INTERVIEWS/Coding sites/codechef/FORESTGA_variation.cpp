#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool is_possible(ll N, ll W, ll L, vector<ll> tree, ll mid)
{
    ll wood =0;
    for(int i=0;i<N;i++)
    {
        ll height = tree[i]*(1<<mid);
        if(height>=L)
        {
            wood += height;
            if(wood>W)
            {
                return true;
            }
        }
    }
    if(wood<W)
    {
        return false;
    }
    return true;
}
ll min_months(ll N, ll W, ll L,ll month, vector<ll> tree)
{

    ll s=0;
    ll e = month;
    ll ans =  INT_MAX;
    while(s<=e)
    {
        ll mid = (s+e)/2;
        if(is_possible(N,W,L,tree,mid))
        {
            ans = min(ans,mid);
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
    ll N,W,L,temp;
    ll month = INT_MIN;
    cin>>N>>W>>L;
    vector<int> tree;
    for(int i=0; i<N;i++)
    {
        ll h;
        cin>>h;
        temp = ceil((double)log(L/h)/log(2));
        month = max(month,temp);
        tree.push_back(h);
    }
    cout<<min_months(N,W,L,month,tree);

}

/*

3 50 24
2 3 4
4

*/
