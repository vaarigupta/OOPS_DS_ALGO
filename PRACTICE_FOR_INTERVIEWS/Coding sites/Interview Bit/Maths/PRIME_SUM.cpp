#include<iostream>
#include<vector>
using namespace std;
vector<int> primesum(int A) {

    vector<bool> primeNo(A+1,1);
    primeNo[0] = 0;
    primeNo[1] = 0;
    for(int i=2;i*i<=A;i++)
    {
        if(primeNo[i])
        {
            for(int j=2*i;j<=A;j+=i)
            {
                primeNo[j] = 0;
            }
        }
    }
    vector<int> ans(2,0);
    for(int i=2;i<=(A/2);i++)
    {
        if(primeNo[i] && primeNo[A-i])
        {
            ans[0] = i;
            ans[1] = A-i;
            return ans;
        }
    }

}

int main()
{
    int n;
    cin>>n;
    vector<int> v = primesum(n);
    cout<<v[0]<<" "<<v[1];

}


/*

16777214

*/
