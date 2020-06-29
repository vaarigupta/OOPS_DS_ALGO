#include<iostream>
using namespace std;
int main()
{
    /// Linear Search - Time Complexity - O(n)

    int key , n,i , a[50];
    cout<<"Enter the range of array"<<endl;
    cin>>n;
    cout<<"Enter the elements of the array"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the Key to be searched "<<endl;
    cin>>key;
    for(i =0;i<n;i++)
    {
      if(key==a[i])
      {
          cout<<key<<" is found at index "<<i<<endl;
          break;
      }
    }
    if(i==n)
    {
        cout<<"Sorry!! "<<key<<" is not found"<<endl;
    }

    return 0;
}
