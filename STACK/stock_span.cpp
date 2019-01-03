#include<iostream>
using namespace std;
int main()
{
    int n ,a[20] ,b[20] , j = 0 , cnt =1;
    cout<<"Enter the number of days :";
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    b[0] = 0;
    for(int i =0;i<n-1;i++)
    {
        j=i+1;
        cnt=1;
        while(a[i+1]>a[j-1])
        {
           j--;
           cnt++;

        }
        b[i+1]=cnt;
    }
        for(int i =0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }

    return 0;
}
