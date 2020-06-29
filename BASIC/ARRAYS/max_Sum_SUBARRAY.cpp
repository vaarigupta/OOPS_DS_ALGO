#include<iostream>
using namespace std;
int main()
{
    int n ,a[50], currSum=0 , maxSum=0 , left , right;
    cout<<"Enter range : ";
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i =0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            currSum = 0;
            for(int k=i;k<=j;k++)
            {
                currSum += a[k];

            }
            if(currSum>maxSum)
            {
                maxSum = currSum;
                left = i;
                right = j;
            }
        }
    }

     for(int i =left ;i<=right;i++)
     {
         cout<<a[i]<<" ";
     }
    cout<<endl<<"Maximum Sum of Array : "<<maxSum<<" ";


    return 0;
}

