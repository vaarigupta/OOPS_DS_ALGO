#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v)
{
     for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
///complexity - o(n)
int repeatedNumber(const vector<int> &A) {

    vector<int> count(A.size(),0);
    for(int i=0;i<A.size();i++)
    {
        count[A[i]]++;
    }
    //print(count);
    int i=0;
    for( i=0;i<A.size();i++)
    {
        if(count[i]==0 || count[i]==1)
        {
            continue;
        }
        if(count[i]>1)
        {
            return i;
        }

    }
    if(i==A.size())
    {
        return -1;
    }


}

///space optimized solution - complexity less than o(n)
int repeatedNumber1(const vector<int> &A)
{
    vector<bool> v(A.size(),true);
    for(int i=1;i<A.size();i++)
    {
        if(v[A[i]])
        {
            v[A[i]] = false;
        }
        else
        {
            return A[i];
        }
    }
    return -1;
}
int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
    }
   //print(v);
    cout<<repeatedNumber1(v);
    return 0;
}

/*

5
3 4 1 4 1
3 4 1 4 1
 0 2 0 1 2
*/
