#include<iostream>
#define ll long long
using namespace std;
ll bin_toDec(string str)
{
    int i = str.length()-1;
    ll ans=0,p=1;
    while(i>=0)
    {
        int no = str[i] - '0';
        ans += no*p;
        p *= 2;
        i--;

    }
    return ans;
}
int countFours(int dec)
{
    int cnt =0;
    int x = dec/4;
    //cout<<x;
    while(x!=0)
    {
       x = x/4;
       cnt++;
    }
    //cnt++;
    if(dec>=31)
    {
       return cnt;
    }
    else
    {
        return cnt+1;
    }

}
int main()
{
    string str;
    cin>>str;
    ll ans = bin_toDec(str);
    cout<<ans<<endl<<countFours(ans);
    return 0;
}

