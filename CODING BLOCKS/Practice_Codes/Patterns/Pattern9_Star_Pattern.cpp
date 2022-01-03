#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int space1=0;
    int space2 =(n/2);

    for(int i=1;i<=n;i++)
    {
        ///1st space
        for(int sp=1;sp<=space1;sp++)
        {
             cout<<"\t";
        }
        cout<<"*";

        ///2nd space
        if(i!=(n/2)+1)
        {
             for(int sp=1;sp<=2*space2;sp++)
            {
                 cout<<"\t";
            }
            cout<<"*";
        }
        cout<<endl;

        if(i<=(n/2))
        {
            space1+=1;
            space2-=1;
        }
        else
        {
            space1-=1;
            space2+=1;
        }
    }
    return 0;
}




