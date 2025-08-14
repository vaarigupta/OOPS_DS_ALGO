#include<iostream>
#define R 3
#define C 4
using namespace std;

/*


void Solution::setZeroes(vector<vector<int> > &A) {
    int *row = new int[A.size()];
    int *col = new int[A[0].size()];
    memset(row,0,sizeof(int)*A.size());
    memset(col,0,sizeof(int)*A[0].size());
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]==0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(row[i] or col[j])
            {
                A[i][j] = 0;
            }
        }
    }
    delete [] row;
    delete [] col;
}

*/
void modifyMatrix(bool mat[R][C])
{
    bool row[R] ={0} , col[C] = {0};
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==1)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
//    for(int i=0;i<R;i++)
//    {
//        cout<<row[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<C;i++)
//    {
//        cout<<col[i]<<" ";
//    }
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(row[i] || col[j])
            {
                mat[i][j] =1;
            }

        }
    }
}
void modifyMatrix1(bool mat[R][C])
{

}
/* A utility function to print a 2D matrix */
void printMatrix(bool mat[R][C])
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

// Driver Code
int main()
{
    bool mat[R][C] = { {1, 0, 0, 1},
                       {0, 0, 1, 0},
                       {0, 0, 0, 0}};

    cout << "Input Matrix \n";
    printMatrix(mat);

    modifyMatrix(mat);

    cout<<"Matrix after modification \n";
    printMatrix(mat);

    return 0;
}
