#include<iostream>
using namespace std;
int main()
{
    int n ,a[50], currSum=0 , maxSum=0 , cs[50]={0} , left , right;
    cout<<"Enter range : ";
    cin>>n;
    cout<<"Enter the Elements : ";
    cin>>a[0];
    cs[0] = a[0];
    for(int i =1;i<n;i++)
    {
        cin>>a[i];
        cs[i] = cs[i-1] + a[i];
    }
    for(int i =0;i<n;i++)
    {

       for(int j =i;j<n;j++)
       {
           currSum = 0;
           currSum = cs[j] - cs[i-1];
        if(currSum > maxSum)
       {
           maxSum = currSum;
           left = i;
           right = j;
       }
       }

    }
    for(int k=left;k<=right;k++)
    {
        cout<<a[k]<<" ";
    }
     cout<<endl<<"Maximum Sum of SubArray : "<<maxSum;

    return 0;
}
