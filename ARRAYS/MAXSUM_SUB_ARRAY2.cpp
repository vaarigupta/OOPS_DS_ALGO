#include<iostream>
using namespace std;
int main()
{
    int n,a[100],maxsum=0,left =0,right=0,Cumsum[100] ={0};
    cin>>n;
    cin>>a[0];
    Cumsum[0] = a[0];
    for(int i =1;i<n;i++)
    {
        cin>>a[i];
        Cumsum[i] = Cumsum[i-1] + a[i];
    }
    for(int i=0;i<n;i++)
    {
       for(int j =i;j<n;j++)
       {
           int currentsum = 0;
           if(i>0)
           {
              currentsum = Cumsum[j] - Cumsum[i-1];
           }
           else
           {
              currentsum = Cumsum[j];
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


