#include<iostream>
using namespace std;
int main()
{
    int key , i;
    int a[ ] = {1,4,5,2,3,9,10};
    int n = sizeof(a)/sizeof(int);
    cout<<"Enter the key : ";
    cin>>key;
    for( i =0;i<n;i++ )
    {
        if(a[i]==key)
        {
            cout<<key<<" is found at"<<i<<endl;
            break;
        }
    }
    if(i==n)
    {
        cout<<key<<" is not found"<<endl;
    }

    return 0;
}
