#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool possible_distribution(ll n, ll m, ll x, ll y, ll winner)
{
    ll good = winner;
    ll bad = n - good;
    ll LHS = m + bad*y;
    ll RHS = good*x;
    return LHS>=RHS;
//    if(LHS >= RHS)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }

}
ll max_students(ll n, ll m, ll x, ll y)
{
    ll s=0, e=n;
    ll ans = INT_MIN;
    while(s<=e)
    {
        ll mid = (s+e)/2;
        if(possible_distribution(n,m,x,y,mid))
        {

            ans = max(mid,ans);
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return ans;
}
int main()
{
   ll N,M,X,Y;
   cin>>N>>M>>X>>Y;
   int good_students = max_students(N,M,X,Y);
   int bad_students = N - good_students;
   cout<<good_students<<" "<<bad_students;

return 0;
}

/*
3 5 5 6
2

5 10 2 1
5

5 10 2 1
*/
