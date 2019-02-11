#include<iostream>
using namespace std;
int main()
{
    int k =1 , j=1;
    for(int row=1;row<=5;row++)
    {
        if(row%2==0)
           {
               for(int each=1;each<=row;each++)
        {
           cout<<j--<<" ";
           j++;

        }
           }
           else
           { for(int each=1;each<=row;each++)
        {
           cout<<k<<" ";
           k--;

        }
           }

        cout<<endl;


    }
    return 0;
}

