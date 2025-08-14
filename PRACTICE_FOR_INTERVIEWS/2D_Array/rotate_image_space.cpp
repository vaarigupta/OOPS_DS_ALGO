#include<iostream>
using namespace std;
void print(int arr[10][10],int row, int col)
{
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int src[10][10];
    int row,col;
    cin>>row>>col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>src[i][j];
        }
    }
    print(src,row,col);
    int dest[10][10];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            dest[col+j-1][i] = src[i][j];
        }
    }
     for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            cout<<dest[i][j]<<" ";
        }
        cout<<endl;
    }
        //print(dest,row,col);
    return 0;
}

/*
3 4
1    2    3    4
5    6    7    8
9    10    11    12
*/
