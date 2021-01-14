#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int half = n/2, space,star;
    space = half;
    star =1;

    for(int i=1;i<=n;i++)
    {
        for(int sp=1;sp<=space;sp++)
        {

             cout<<"\t";
        }
         for(int st=1;st<=star;st++)
        {

             cout<<"*\t";
        }
        cout<<endl;
        if(i<=half)
        {
            space--;
            star+=2;

        }
        else
        {

            space++;
            star-=2;

        }
    }
    return 0;
}
