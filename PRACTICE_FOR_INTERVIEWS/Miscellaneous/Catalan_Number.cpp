#include<iostream>
using namespace std;

///Approach 1 - for every nth catalan num, using summation of f(i)*f(n-i-1) from 0 to n-1
void FindCatalanNum1(int n)
{

    long  *catalan = new long [n+1]{0};
    catalan[0] = catalan[1] = 1;

    ///for every ith catalan number
    for(int i=2;i<=n;i++)
    {
        ///sum of catalan[i]*catalan[n-i-1]
        for(int j=0;j<i;j++)
        {
            catalan[i] += catalan[j]*catalan[i-j-1];
        }
    }
    for(int i=0;i<=n;i++)
    {
        cout<<catalan[i]<<" ";
    }
}


///Approach 2 - using C(2n,n)/(n+1)
long BinomialCoefficient(int n, int r)
{
       long res =1;
       if(r > (n-r))
       {
           r = n-r;
       }
    for(int i=0;i<r;i++)
    {
        res *= (n-i);
        res /= (i+1);
    }
    return res;

}

long FindCatalanNum2(int n)
{

    long nCr = BinomialCoefficient(2*n, n);
    return nCr/(n+1);
}

int main()
{
    int n = 10;
    FindCatalanNum1(n);///O(n2) Solution
    cout<<endl;
    cout<<FindCatalanNum2(n);///O(n) Solution

//    long long ans = CatalanNum(n);
//    cout<<ans;
    return 0;
}
