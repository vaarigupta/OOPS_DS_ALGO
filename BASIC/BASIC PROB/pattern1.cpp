#include<iostream>
using namespace std;
int main()
{
    int k =1;
    for(int row=1;row<=4;row++)
    {
        for(int each=1;each<=row;each++)
        {
            cout<<k<<" ";
            k++;
        }
        cout<<endl;


    }
    return 0;
}
