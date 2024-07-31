#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int> &A) {

     vector<bool> boolean(A.size()+1,false);
    for(int i=0;i<=A.size();i++)
    {
        if(A[i]>0 && A[i]<=A.size())
        {
            boolean[A[i]] = true;
        }
    }
    if(A.size()==1 && A[0]!=1) return 1;
    else if(A.size()==1 && A[0]==1) return 2;
    else
    {
        int i;
    for(i=1;i<=A.size();i++)
    {
        if(!boolean[i])
        {
            return i;
        }
    }
    return i;

    }

}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
    }
    cout<<firstMissingPositive(v);
    return 0;
}


