#include<iostream>
using namespace std;
int LowerBound(int a[], int n , int key)
{
    int s = 0 , e = n-1 , mid , ans=-1;
    while(s<=e)
    {
       mid = (s+e)/2;
       if(a[mid]==key)
       {
         ans = mid;
         e = mid -1;
       }
       else if(a[mid]>key)
       {
           e = mid-1;
       }
       else
       {
           s= mid+1;
       }
    }
    if(s>e)
    {
        return ans;
    }

}

int Upper_Bound(int a[] , int n , int key)
{

    int s =0 , e= n-1 , mid , ans = -1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(a[mid]== key)
        {
            ans = mid ;
            s = mid+1;
        }
        else if(a[mid]>key)
        {

            e = mid -1;
        }
        else
        {
            s = mid +1;
        }
    }
    if(s>e)
    {
        return ans;
    }
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
   cout<<"Enter the key whose lower bound to be found"<<endl;
   cin>>key;
   int lower = LowerBound(a,n,key);
   int Upper = Upper_Bound(a,n,key);
   if(lower == -1 || Upper == -1)
   {
       cout<<"Sorry"<<key<<"is not found"<<endl;
   }
   else
   {
       cout<<"The LOWER BOUND of key "<<key<<" : "<<lower<<endl;
        cout<<"The UPPER BOUND of key "<<key<<" : "<<Upper<<endl;

   }


  return 0;
}

