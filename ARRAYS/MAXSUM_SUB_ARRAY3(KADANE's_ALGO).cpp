#include<iostream>
using namespace std;
int main()
{
    int n,a[100],maxsum=0,currentsum=0;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i =0;i<n;i++)
    {
        currentsum += a[i];
        if(currentsum <0)
        {
            currentsum = 0;
        }
        maxsum = max(maxsum,currentsum);
    }
    cout<<maxsum<<endl;


    return 0;
}


