///https://leetcode.com/problems/friend-circles/
#include<bits/stdc++.h>
using namespace std;
 void dfs(int i, vector<vector<int>>& M, vector<bool> &visited)
    {
        visited[i] = true;
        for(int j=0;j<M.size();j++)
        {
            if(M[i][j] && !visited[j])
            {
                dfs(j,M,visited);
            }
        }
    }
    int findCircleNumdfs(vector<vector<int>>& M) {
        int n = M.size();
        vector<bool> visited(n,false);
        int comp =0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,M,visited);
                comp++;
            }

        }
        return comp;


    }

    int findCircleNumbfs(vector<vector<int>>& M) {
        int n = M.size();
        vector<bool> visited(n,false);
        int comp =0;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
                while(!q.empty())
                {
                    int k = q.front();
                    q.pop();
                    for(int j=0;j<n;j++)
                    {
                        if(M[k][j] && !visited[j])
                        {
                            visited[j] = true;
                            q.push(j);

                        }
                    }

                }
                comp++;
            }
        }
        return comp;


    }
int main()
{
    int n;
    cin>>n;
    vector<vector<int> > M(n, vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            M[i][j] = num;
        }
    }
    cout<<findCircleNumbfs(M);
    return 0;
}
/*
3
1 1 0
1 1 0
0 0 1
Op-
2

3
1 1 0
1 1 1
0 1 1
op-
1

 */
