
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
void rotateAndDelete(vector<ll> v, ll n)
{
  // ll i=1;
   for(ll j=n-1;j>=1;j--)
        {
            v[j] = v[j-1];
        }
        for(ll i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
   while(n>1 && i<=(n-1))
    {
        ll temp = v[n-1];
        for(ll j=n-1;j>0;j--)
        {
            v[j] = v[j-1];
        }
        for(ll i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        v[0] = temp;
        //v[n-i] = -1;
        for(ll j=(n-i)>0?(n-i):0;j<n;j++)
        {
            v[j] = v[j+1];

        }
        v.pop_back();
        i++;
    }
    if(n==1)
    {
        return v[0];
    }
}
int main()
 {
     //code
     int t;
     ll n;
     vector<ll> v;
     cin>>t;
     while(t--)
     {
         cin>>n;
         for(ll i=0;i<n;i++)
         {
             cin>>v[i];
         }
         rotateAndDelete(v,n);
     }
	return 0;
}
