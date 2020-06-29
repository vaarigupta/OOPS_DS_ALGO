#include<bits/stdc++.h>
using namespace std;
void pascalTriangle(int n)
{
    int c=1;
    cout<<c<<" "<<endl;
    for(int line=1;line<n;line++)
    {
        cout<<c<<" ";
        for(int i=1;i<=line;i++ )
        {
            c = c*(line-i + 1)/i;
            cout<<c<<" ";
        }
        cout<<endl;
    }

}
void kthRowOfPascalTriangle(int row)
{
    int c=1;
    cout<<c<<" ";
    for(int i=1;i<=row;i++)
    {
        c = c*(row-i+1)/i;
        cout<<c<<" ";
    }
    cout<<endl;
}
vector<vector<int> > solve(int A) {

    int c=1;
    vector<vector<int> > ans;
    vector<int> v;
    v.push_back(c);
    ans.push_back(v);
   // v.clear();
    for(int line=1;line<A;line++)
    {
        for(int i=1;i<=line;i++)
        {
            c = c*(line -i +1)/i;
            //cout<<c<<" ";
            v.push_back(c);
        }
        ans.push_back(v);
       // v.clear();

    }
    return ans;
}
void print(vector<vector<int> > v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int i=0;i<v[i].size();i++)
        {
            cout<<v[i][i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    pascalTriangle(n);
    //vector<vector<int> > v = solve(n);
    //print(v);
    kthRowOfPascalTriangle(3);
    return 0;
}


/*

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

*/
