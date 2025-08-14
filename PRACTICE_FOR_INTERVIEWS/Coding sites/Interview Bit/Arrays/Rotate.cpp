/*


*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


void rotate(vector<vector<int> > &A) {
    int n = A.size();
    cout<<"size"<<n<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            swap(A[i][j],A[j][i]);
        }
    }

    for(int i=0;i<(n/2);i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(A[j][i],A[j][n-i-1]);
        }

    }
}

int main()
{
    vector<vector<int>> a;
    vector<int> v;
    int k=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           v.push_back(k);
           k++;
        }
        a.push_back(v);
    }
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
          cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    rotate(a);
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
          cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}


