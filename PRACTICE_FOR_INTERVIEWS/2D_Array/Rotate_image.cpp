#include<iostream>
#include<vector>
using namespace std;
void rotate_image(vector< vector<int> > v, int n)
{
    vector<vector<int> > temp(n,vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[n-1-j][i] = v[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {

            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vector< vector<int> > v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<int> input;
        for(int j=0;j<n;j++)
        {
            int no;
            cin>>no;
            input.push_back(no);
        }
        v.push_back(input);
    }
    rotate_image(v,n);
    return 0;
}

/*
3
1 2 3
4 5 6
7 8 9
3 6 9
2 5 8
1 4 7

*/
