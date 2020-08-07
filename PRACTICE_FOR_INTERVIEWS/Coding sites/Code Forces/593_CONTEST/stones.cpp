#include<bits/stdc++.h>
using namespace std;
int stones(int a, int b, int c)
{
    if((a<1 && b<2) || (b<1 && c<2) )
    {
        return 0;
    }
    int ans1 = 0, ans2=0;
    if((a>=1) && (b>=2))
    {
        ans1 += 3 + stones(a-1,b-2,c);
    }
    if((b>=1) && (c>=2) )
    {
        ans2 += 3 + stones(a,b-1,c-2);
    }
    return max(ans1,ans2);
}
int main()
{
    int t,a,b,c;
    cin>>t;
    while(t--)
    {
       cin>>a>>b>>c;
       cout<<stones(a,b,c)<<endl;
    }
    return 0;
}
