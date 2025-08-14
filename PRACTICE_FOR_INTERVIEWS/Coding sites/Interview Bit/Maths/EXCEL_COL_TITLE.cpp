#include<bits/stdc++.h>
using namespace std;
long long int mod = 100000007;
string convertToTitle(int n) {
   string str;
   while(n>0)
   {
       int rem = n%26;
       if(rem)
       {
           char c = (rem-1) + 'A';
           str.push_back(c);
           n /= 26;
       }
       else
       {
           char c = 'Z';
           str.push_back(c);
           n = (n/26) - 1;
       }
   }
   reverse(str.begin(),str.end());
   return str;
}
int main()
{
    int n;
    cin>>n;
    cout<<convertToTitle(n);
    return 0;
}

