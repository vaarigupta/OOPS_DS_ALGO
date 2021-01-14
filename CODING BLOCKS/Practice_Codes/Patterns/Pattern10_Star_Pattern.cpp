#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int space=(n/2),star=1;
    int space2 = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=space;j++)
        {
            cout<<"\t";
        }
        cout<<"*";
        for(int j=1;j<=2*space2;j++)
        {
            cout<<"\t";
        }
        if(i!=1 && i!=n)
        {
            cout<<"*";
        }
        cout<<endl;
        if(i<=n/2)
        {
            space--;
            space2++;

        }
        else
        {
            space++;
            space2--;
        }
    }
    return 0;
}




