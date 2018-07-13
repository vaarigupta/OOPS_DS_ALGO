#include<iostream>
using namespace std;
int main()
{
    int n,a[100],maxsum=0;
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
           if(currentsum>maxsum)
           {
               maxsum = currentsum;
           }


       }
    }
    cout<<maxsum<<endl;


    return 0;
}

