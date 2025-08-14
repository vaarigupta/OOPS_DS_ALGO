#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dig_jumps(string s)
{
    int n = s.size();
    vector<bool> visited(n,false);
    vector<int> min_jumps(n,0);
    queue<int> q;
    vector<int> indices[10];
    for(int i=0;i<n;i++)
    {
        indices[s[i]-'0'].push_back(i);
    }
    q.push(0);
    visited[0] = true;
    min_jumps[0] =0;
    while(!q.empty())
    {
        int i = q.front();
        if(i==n-1)
        {
            break;
        }
        q.pop();
        int digit = s[i]-'0';//digit
        int vsize = indices[digit].size(); ///size of vector (having all those indices with digit )
       for(int y=0;y<vsize;y++)
        {
        	int x = indices[digit][y];
            if(!visited[x])
            {
                visited[x] = true;
                q.push(x);
                min_jumps[x] = min_jumps[i]+1;
            }
        }
        indices[digit].clear();
        if((i-1)>=0 && !visited[i-1])
        {
            visited[i-1] = true;
            q.push(i-1);
            min_jumps[i-1] = min_jumps[i] +1;
        }
        if( (i+1)<n && !visited[i+1])
        {
            visited[i+1] = true;
            q.push(i+1);
            min_jumps[i+1] = min_jumps[i] +1;
        }
    }
    return min_jumps[n-1];
}
int main()
{
    string s;
    cin>>s;
    cout<<dig_jumps(s);

    return 0;
}
