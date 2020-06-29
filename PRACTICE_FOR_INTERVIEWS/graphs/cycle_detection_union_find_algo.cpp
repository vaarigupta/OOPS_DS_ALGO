#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class edge
{
public:
    int s,d;
    edge(int s, int d)
    {
        this->s = s;
        this->d = d;
    }
};
class graph
{
    public:
    vector<vector<int> > adjList;
    int N;
    graph(vector<edge> const &edges, int N)
    {
        this->N = N; ///vertices
        adjList.resize(N+1);
        for(auto &edge: edges)
        {
            adjList[edge.s].push_back(edge.d);
            //adjList[edge.d].push_back(edge.s);
        }
    }

};
class dsu
{
    unordered_map<int,int> parent;
public:
    void makeset(int N)
    {

        for(int i=1;i<=N;i++)
        {
            parent[i] =i;
        }
    }
    int find(int k)
    {
        if(parent[k]==k)
        {
            return k;
        }
        return find(parent[k]);
    }

    void union_(int a, int b)
    {
        int x = find(a);
        int y = find(b);
        parent[x] = y;
    }

};

void redundantConnection(graph const &g, int N)
{
    dsu ds;
    ds.makeset(N);
    for(int u=1;u<=N;u++)
    {
        for(int v:g.adjList[u])
        {
            int x = ds.find(u);
            int y = ds.find(v);
            if(x==y)
            {
                 cout<<u<<" "<<v<<endl;
                 return;
            }
            else
            {
                ds.union_(x,y);
            }
        }
    }
}

int main()
{
    vector<edge> edges;
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int src, dest;
        cin>>src>>dest;
        edge e(src,dest);
        edges.push_back(e);
    }
    graph g(edges,V);
    redundantConnection(g,V);

    return 0;
}

/*

3 3
1 2
1 3
2 3


5 5
1 2
2 3
3 4
1 4
1 5

*/
