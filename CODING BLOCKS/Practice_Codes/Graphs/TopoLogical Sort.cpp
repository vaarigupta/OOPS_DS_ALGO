#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

template <typename t>
class Graph
{
    unordered_map<t,list<t>> adj;
    int v,e;
    public:
     Graph(int v, int e)
       {
        this->v = v;
        this->e = e;
       }

    void AddEdge(t u, t v, bool bidirectional = true)
    {

        adj[u].push_back(v);
        if(bidirectional)
             adj[v].push_back(u);
    }

    void printGraph()
    {
        for(auto x: adj)
        {
            cout<<x.first<<"=>";
            for(auto y : x.second)
            {
                cout<<y<<",";
            }
            cout<<endl;
        }
    }

    void TopologicalSort()
    {
    queue<t> q;
    unordered_map<t,bool> visited;
    unordered_map<t,int> indegree;

    ///counting indegree of each node
    for(auto node : adj)
      {
        t u = node.first;

        for(auto v: adj[u])
       {
        indegree[v]++;
        }
      }

    for(auto node : adj)
    {
        if(indegree[node.first]==0)
        q.push(node.first);
    }
    while(!q.empty())
    {
       t curr = q.front();
       q.pop();
        cout<<curr<<" => ";
         for(auto nbr : adj[curr])
         {
            indegree[nbr]--;
             if(indegree[nbr]==0)
                q.push(nbr);

         }

    }
     cout<<endl;

    }


};
int main()
{

    Graph<string> g(5,5);
    g.AddEdge("Eng" ,"Maths",false);
    g.AddEdge("Eng" ,"Hindi",false);
    g.AddEdge("Maths" ,"Sci",false);
    g.AddEdge("Hindi" ,"SST",false);
    g.AddEdge("Sci" ,"SST",false);
    g.printGraph();
    g.TopologicalSort();

  return 0;
}

