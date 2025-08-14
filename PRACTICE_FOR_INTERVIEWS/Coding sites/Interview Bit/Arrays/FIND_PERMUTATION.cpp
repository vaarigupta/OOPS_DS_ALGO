#include<bits/stdc++.h>
using namespace std;
vector<int> findPerm(const string A, int B) {

   vector<int> v;
    int j=1;
    int k=0;
    int endj = B;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='I')
        {
            v.push_back(j);
           // cout<<v[k]<<" ";
            k++;
            j++;
        }
        if(A[i]=='D')
        {
            v.push_back(endj);
            //cout<<v[k]<<" ";
            k++;
            endj--;
        }
    }
    v.push_back(j);

    return v;
}

int main()
{
    int n;
    string str;
    cin>>str;
    cin>>n;
    vector<int> v = findPerm(str,n);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
