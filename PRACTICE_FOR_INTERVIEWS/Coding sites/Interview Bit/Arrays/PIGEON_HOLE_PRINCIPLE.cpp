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

void pigeonHoleSort(vector<int> &v)
{
    int minv = v[0], maxv = v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<minv)
        {

            minv = v[i];
        }
        if(v[i]>maxv)
        {
            maxv = v[i];
        }
    }
    int range = maxv - minv +1;
    vector<int> pigeonhole[range];/// array of vectors
    int index =0;
    for(int i=0;i<v.size();i++)
    {
        pigeonhole[v[i]-minv].push_back(v[i]);
    }
    for(int i=0;i<range;i++)
    {
        for(auto it = pigeonhole[i].begin();it!=pigeonhole[i].end();it++)
        {
            v[index] = *it;
            index++;
        }
    }
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
    pigeonHoleSort(v);
    print(v);
    return 0;
}

// 0 6 0 6 4 8 8 1

