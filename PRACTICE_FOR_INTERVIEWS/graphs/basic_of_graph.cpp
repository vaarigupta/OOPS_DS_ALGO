#include<bits/stdc++.h>
using namespace std;
template<typename t>
class graph
{
public:
    unordered_map<t,list<t> > adlist;
    graph()
    {

    }
    void addEdge(t u, t v , bool bidir = true)
    {
        adlist[u].push_back(v);
        if(bidir)
        {
            adlist[v].push_back(u);
        }

    }
    void printGraph()
    {
        for(auto x: adlist)
        {
            cout<<x.first<<"=>";
            for(auto y : x.second)
            {
                cout<<y<<",";
            }
            cout<<endl;
        }
    }
    void bfs(t src)
    {
        unordered_map<t,bool> visited;
        visited[src] = true;
        queue<t> q;
        q.push(src);
        while(!q.empty())
        {
            t node = q.front();
            q.pop();
            cout<<node<<" ,";
            for( t nbr: adlist[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }

        }
    }
    void sssp(t src, t dest) ///single source shortest path
    {
        unordered_map<t,int> dist; /// minimum dist from the source node
        unordered_map<t,t> parent; /// parent of the node
        queue<t> q; ///to visit only for once
        for(auto x: adlist)
        {
            ///each vertex
            dist[x.first] = INT_MAX; ///store with big value first
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;
        while(!q.empty())
        {
            t node = q.front();
           // cout<<node<<",";
            q.pop();
            for(auto nbr:adlist[node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1; ///update distance of each neighbour
                    parent[nbr] = node; ///update parent of each neighbour
                }
            }
        }
        cout<<dist[dest]<<endl;
        t s = src;
        t d = dest;
        cout<<dest<<"<=";
        while(d!=s)
        {
            cout<<parent[d]<<" <= ";
            d = parent[d];
        }

    }
    void dfsHelper(t src, unordered_map<t,bool> &visited)
    {
        visited[src] = true;
        cout<<src<<", ";
        for(auto nbr: adlist[src])
        {
            if(!visited[nbr])
            {
              dfsHelper(nbr,visited);
            }

        }
    }
    void dfs(t src)
    {
        unordered_map<t,bool> visited;
        dfsHelper(src,visited);
    }
};


int main()
{
        graph<int> g;
        g.addEdge(0,4);
        g.addEdge(0,1);
        g.addEdge(1,2);
        g.addEdge(2,4);
        g.addEdge(2,3);
        g.addEdge(3,4);
        g.addEdge(3,5);
        g.dfs(0);
       // g.sssp(0,2);
    return 0;
}
