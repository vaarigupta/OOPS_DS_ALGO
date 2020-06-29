#include<bits/stdc++.h>
using namespace std;
long long int mod = 100000007;
int excel_col_num(string str)
{
    int l = str.length();
    int ans=0, p=1;
    for(int i=l-1;i>=0;i--)
    {
        ans += (str[i] - 'A' + 1)*p;
        p *= 26;
        p %= mod;
    }
    return ans;
}
int main()
{
    string str;
    cin>>str;
    cout<<excel_col_num(str);
    return 0;
}
