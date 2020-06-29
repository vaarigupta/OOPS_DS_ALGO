#include<iostream>
using namespace std;
int main()
{
    int a[ ] = {1,4,5,2};
    int n = sizeof(a)/sizeof(int);
    ///for initial element of the subarray
    for( int i =0;i<n;i++ )
    {
        ///change the initial element of each subarray and runs till the total number of elements
        for(int j=i;j<n;j++)
        {
            ///Create partitions in the array with specific start and last element
            for(int k=i;k<=j;k++)
            {
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}

