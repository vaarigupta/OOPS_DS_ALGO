#include<iostream>
using namespace std;
int pivot_Element(int a[] , int n)
{
    int s =0, e=n-1, mid,ans;
    while(s<=e)
    {
        mid =(s+e)/2;
        if(a[mid]<a[mid-1])
        {
           ans = a[mid -1];
           break;
        }
        else if(a[mid]>a[mid+1])
        {
            ans = a[mid] ;
            break;
        }
        else if (a[s]>a[mid])
        {
            e = mid -1;
        }
        else
        {
            s = mid +1;
        }
    }
    return ans;

}
int main()
{

    int n ,a[100] , key;
   cout<<"Enter the range of the array"<<endl;
   cin>>n;
   cout<<"Enter the elements in the array "<<endl;
   for(int i =0;i<n;i++)
   {
       cin>>a[i];
   }
   int pivot = pivot_Element(a,n);
   cout<<"Pivot Element is "<<pivot<<endl;
    return 0;
}
