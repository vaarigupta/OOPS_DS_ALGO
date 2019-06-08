#include<iostream>
using namespace std;
int main()
{
    int n ,a[50], currSum=0 , maxSum=0;
    cout<<"Enter range : ";
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i =0;i<n;i++)
    {
      currSum += a[i];
      if(currSum<0)
      {
          currSum =0;
      }
      maxSum = max(currSum,maxSum);
    }
    cout<<endl<<"Maximum Sum of SubArray : "<<maxSum;
    return 0;
}
