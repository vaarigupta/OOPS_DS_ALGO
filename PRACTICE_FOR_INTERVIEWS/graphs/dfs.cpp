#include<iostream>
#include<vector>
#include<map>
using namespace std;
template<typename t>
class edge
{
public:
    t src;
    t dest;
};
template <typename t>
class graph
{
public:
    int V, E;
    vector<vector<t> > adjList;
    graph(int N, int e)
    {
        V= N;
        E= e;
        adjList.resize(N+1);
    }
    void addEdge(t u, t v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void createGraph()
    {
        for(int i=0;i<E;i++)
        {
            t src, dest;
            cin>>src>>dest;
            addEdge(src,dest);
        }
    }

    void print()
    {
        for(int i=0;i<adjList.size()-1;i++)
        {
            cout<<i<<"=> ";
            for(int j=0;j<adjList[i].size();j++)
            {
                cout<<adjList[i][j]<<",";
            }
            cout<<endl;
        }
    }
    void dfs_helper(t src, map<t, bool> &visited)
    {
        visited[src] = true;
        cout<<src<<" ";
        for(t nbr: adjList[src])
        {
            if(!visited[src])
            {
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs(t src)
    {
        map<t,bool> visited;
        dfs_helper(src,visited);
    }

};
int main()
{
    int V,E;
    cin>>V>>E;
    graph<int> g(V,E);
    g.createGraph();
    g.print();
    g.dfs(0);
    return 0;
}

/*

5 7
0 1
0 4
2 1
3 1
4 1
3 2
4 3
0=> 1,4,
1=> 0,2,3,4,
2=> 1,3,
3=> 1,2,4,
4=> 0,1,3,

*/
