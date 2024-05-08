#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;
class graph
{
    int v;
    list<int> *l;
public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addedge(int u, int v, bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }
    void printgraph()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<" - ";
            for(int vertex: l[i])
            {
                cout<<vertex<<" =>";
            }
            cout<<endl;
        }
    }
    void bfs(int src)
    {
        queue<int> q;
        map<int, bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(int nbr : l[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void dfs_helper(int src, map<int, bool> &visited)
    {
        visited[src] = true;
        cout<<src<<" ";
        for(int nbr: l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs(int src)
    {
        map<int,bool> visited;
        dfs_helper(src,visited);
    }

};
int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(2,1);
    g.addedge(3,1);
    g.addedge(4,1);
    g.addedge(3,2);
    g.addedge(4,3);
    g.printgraph();
    cout<<endl;
    cout<<"BFS"<<endl;
    g.bfs(0);
    cout<<endl<<endl<<"DFS"<<endl;
    g.dfs(0);
    return 0;
}

/*

0 - 1 =>4 =>
1 - 0 =>2 =>3 =>4 =>
2 - 1 =>3 =>
3 - 1 =>2 =>4 =>
4 - 0 =>1 =>3 =>



0 - 1 =>4 =>
1 - 0 =>2 =>3 =>4 =>
2 - 1 =>3 =>
3 - 1 =>2 =>4 =>
4 - 0 =>1 =>3 =>
BFS
0 1 4 2 3
DFS
0 1 2 3 4

*/

