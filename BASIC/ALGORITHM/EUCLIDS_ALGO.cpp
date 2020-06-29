#include<iostream>
using namespace  std;
int EUCLID(int i ,int j)
{
    int rem;
    int n = max(i,j);
    int m = min(i,j);
    while(n%m!=0)
    {
     rem = n%m;
     n=m;
     m=rem;
    }
    return m;

}
int main()
{

    int m,n;
    cout<<"Enter the values"<<endl;
    cin>>m>>n;
    int hcf = EUCLID(m,n);
    cout<<hcf<<endl;



}
