#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int first=0,second=1;
    cout<<first<<endl;
    for(int i=2;i<=n;i++)
    {
       for(int j=1;j<=i;j++)
       {
           cout<<second<<"\t";
           int temp = first;
           first = second;
           second = temp+second;

       }
       cout<<endl;
    }
    return 0;
}





