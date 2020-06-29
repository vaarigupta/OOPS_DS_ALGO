#include<iostream>
using namespace std;
///creating sub array of an array -> means the continuous memory allocation within an array
int main()
{
    int n,a[100];
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
       for(int j =i;j<n;j++)
       {
           for(int k=i;k<=j;k++)
           {
               cout<<a[k]<<",";
           }
           cout<<endl;
       }
    }


    return 0;
}
