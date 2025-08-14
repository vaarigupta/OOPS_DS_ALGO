#include<iostream>
using namespace std;

///generating max sum of subarray in o(n) time - "KADANE ALGO"
void maxSum(int a[], int n)
{
    int currSum = 0, max_sum = 0;
    for(int i=0;i<n;i++)
    {
       currSum += a[i];
       if(currSum<0)
       {
           currSum = 0;
       }
        max_sum = max( max_sum,currSum);
    }
    cout<<"Max Sum :"<< max_sum<<endl;
//    for(int i=x;i<=y;i++)
//    {
//        cout<<a[i]<<" ";
//    }
}
int main()
{
    int a[100]={0},n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    maxSum(a,n);
    return 0;
}

