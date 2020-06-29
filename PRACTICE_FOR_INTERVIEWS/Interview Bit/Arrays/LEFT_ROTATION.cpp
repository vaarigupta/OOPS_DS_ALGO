#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void leftRotation(vector<int> &v, int d)
{
    int n= v.size();
    vector<int> temp;
    for(int i=0;i<d;i++)
    {
        temp.push_back(v[i]);
    }
    //print(temp);
    for(int i=0;i<(n-d);i++)
    {
        v[i] = v[d+i];
    }
    int k=0;
    for(int i=n-d;i<n;i++)
    {
       v[i] = temp[k];
       k++;
    }
    temp.clear();
}
int main()
{
    int n,d;
    cin>>n>>d;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
    }
    leftRotation(v,d);
    print(v);

    return 0;
}
