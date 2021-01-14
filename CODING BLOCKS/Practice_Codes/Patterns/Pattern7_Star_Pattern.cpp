#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int space=0;

    for(int i=1;i<=n;i++)
    {
        for(int sp=1;sp<=space;sp++)
        {

             cout<<"\t";
        }
        cout<<"*\t"<<endl;
        space++;
    }
    return 0;
}


