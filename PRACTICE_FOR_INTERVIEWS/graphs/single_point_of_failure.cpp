#include<bits/stdc++.h>
using namespace std;
struct tarjan {

    const vector<vector<int>> & adj;
    int n;
    vector<int> depth;
    vector<int> lowval;
    int res = 0;

    tarjan(const vector<vector<int>>& a) : adj(a), n(adj.size()), depth(n, -1), lowval(n) {}

    void dfs(int a, int p = -1) {
        if (p == -1) depth[a] = 0;
        else depth[a] = depth[p] + 1;
        lowval[a] = depth[a];
        for (int i = 0; i < n; i++) {
            if (i == p) continue;
            if (!adj[a][i]) continue;
            if (depth[i] == -1) {
                dfs(i, a);
                lowval[a] = min(lowval[a], lowval[i]);
            } else {
                lowval[a] = min(lowval[a], depth[i]);
            }
        }
        if (p != -1 && lowval[a] == depth[a]) res += 1;
    }

};
int singlePointOfFailure(vector<vector<int>> connections) {
    tarjan t(connections);
    t.dfs(0);
    return t.res;
}

int main()
{
    int N;
    cin>>N;
    vector<vector<int>> connections(N,vector<int> (N,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int num;
            cin>>num;
            connections[i][j] =num;

        }
    }
    int failures = singlePointOfFailure(connections);
    int ans = N*failures + __gcd(N,failures);
    cout<<failures<<" "<<ans;
    return 0;
}


/*
2
0 1
1 0

3
0 1 1
1 0 1
1 1 0

6
0 1 1 1 0 0
1 0 1 0 0 0
1 1 0 0 0 0
1 0 0 0 1 1
0 0 0 1 0 0
0 0 0 1 0 0


5
0 1 1 1 1
1 0 0 0 0
1 0 0 0 0
1 0 0 0 0
1 0 0 0 0

7
0 1 1 0 0 0 0
1 0 1 0 0 0 0
1 1 0 0 0 0 1
0 0 0 0 1 1 1
0 0 0 1 0 1 0
0 0 0 1 1 0 0
0 0 1 1 0 0 0


6
0 1 1 1 0 0
1 0 1 0 0 0
1 1 0 0 0 0
1 0 0 0 1 1
0 0 0 1 0 0
0 0 0 1 0 0
3 21

3
0 1 1
1 0 1
1 1 0
0 3

 */
