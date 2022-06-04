
#include <bits/stdc++.h>
using namespace std;
long FindSubsequences(string s)
{
    int n = s.length();
    long subsequence_count = 0;
    long ans =0;
    int ones[n] = {0};
    int zeroes[n] = {0};
    if(s[0]=='1')
    {
        ones[0] = 1;
    }
    if(s[0]=='0')
    {
        zeroes[0] = 1;
    }
    for(int i=1;i<n;i++)
    {
        if(s[i]=='1')
        {

          ones[i] +=  ones[i-1] +1 ;
          zeroes[i] = zeroes[i-1];

        }
         if(s[i]=='0')
        {

          zeroes[i] += zeroes[i-1]+1;
          ones[i] = ones[i-1];

        }
    }


    for(int i=0;i<n;i++)
    {
        cout<<ones[i]<<" ";
    }
    cout<<endl;
     for(int i=0;i<n;i++)
    {
        cout<<zeroes[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++)
    {

        if(s[i]=='0')
        {
            subsequence_count += ones[i-1]*(ones[n-1]-ones[i]);
        }
        if(s[i]=='1')
        {
            subsequence_count += zeroes[i-1]*(zeroes[n-1]-zeroes[i]);
        }
    }
    return subsequence_count;
}
int main()
{
    string s = "10101";
    int ans = FindSubsequences(s);
    cout<<ans;
    return 0;
}

//"01001" - 4
//"10111" - 3
//"10101" - 3
//"111101111" - 16
//"0000100000" - 20
