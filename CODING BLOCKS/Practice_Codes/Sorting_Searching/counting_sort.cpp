#include<iostream>
#define ll long long
using namespace std;
ll freq[1000010]={0};
ll a[1000010] = {0};
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }


    for(int i=0;i<n;i++)
    {
        freq[a[i]]++;
    }
    int j=0;
    for(int i=0;i<=1000010;i++)
    {
       while(freq[i]>0)
       {
           a[j++] = i;
           freq[i]--;
       }
    }


    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}


