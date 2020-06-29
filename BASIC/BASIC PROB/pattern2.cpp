#include<iostream>
using namespace std;
int main()
{
    int value;
    for(int row=1;row<=5;row++)
    {
        if(row%2==0)
        {
            value=1;
        for(int each=1;each<=row;each++)
        {
           value = 1-value;
          cout<<value<<" ";

        }
        }
        else
        {
            value=0;
        for(int each=1;each<=row;each++)
        {

        value = 1-value;
          cout<<value<<" ";

        }
        }

        cout<<endl;


    }
    return 0;
}

