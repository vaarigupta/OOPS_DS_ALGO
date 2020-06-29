#include<iostream>
using namespace std;
int main()
{
    int [10][10] src;
    int row,col;
    cin>>row>>col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>src[i][j];
        }
    }
    int dest[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            dest[col+j-1][r] = src[i][j];
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<dest[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
