#include<iostream>
using namespace std;
int main()
{
    int n,a[100],maxsum=0,left =0,right=0;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
       for(int j =i;j<n;j++)
       {    int currentsum = 0;
           for(int k=i;k<=j;k++)
           {

               currentsum += a[k];
           }
           if(currentsum > maxsum)
           {
               maxsum = currentsum;
               left = i ;
               right = j;
           }
       }
    }
    cout<<maxsum<<endl;
    for(int i = left;i<=right;i++) /// subarray displayed whose sum is max
    {
        cout<<a[i]<<" ,";
    }


    return 0;
}

