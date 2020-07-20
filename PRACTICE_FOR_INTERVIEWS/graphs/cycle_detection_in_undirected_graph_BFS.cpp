#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename t>
class graph
{
    unordered_map<t,list<t> > adj;
    int v, e;
public:
    graph(int v, int e)
    {
        this->v = v;
        this->e = e;
    }
    void addEdge(t u, t v, bool bidir = true)
    {
        adj[u].push_back(v);
        if(bidir)
        {
            adj[v].push_back(u);
        }
    }
    bool cycleDetection(t src)
    {
        unordered_map<t, bool> visited;
        unordered_map<t,t> parent;
        queue<t> q;
        visited[src] = true;
        parent[src] = src;
        q.push(src);
        while(!q.empty())
        {
            t curr = q.front();
            q.pop();
            for(auto x: adj[curr])
            {
                if(visited[x] && x!=parent[curr])
                {
                    return true;
                }

                if(!visited[x])
                {
                    parent[x] = curr;
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
        return false;

    }
};
int main()
{
    int v,e;
    cin>>v>>e;
    graph<int> g(v,e);
    int src = 0;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        if(i==0)
        {
            src = u;
        }
        g.addEdge(u,v);
    }
    if(g.cycleDetection(src))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

    return 0;
}

/*
4 4
1 2
1 3
2 4
2 3
YES


4 3
1 2
1 3
2 4
NO
*/
