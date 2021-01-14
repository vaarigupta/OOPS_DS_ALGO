#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int half = (n/2) +1, space,star;
    space = 1;
    star =half;

    for(int i=1;i<=n;i++)
    {
        for(int st=1;st<=star;st++)
        {

             cout<<"*\t";
        }
        for(int sp=1;sp<=space;sp++)
        {

             cout<<"\t";
        }
        for(int st=1;st<=star;st++)
        {

             cout<<"*\t";
        }
        cout<<endl;
        if(i<=(n/2))
        {
            space+=2;
            star--;

        }
        else
        {
            space-=2;
            star++;
        }
    }
    return 0;
}

