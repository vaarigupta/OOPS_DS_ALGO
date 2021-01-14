#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template<typename t>
class graph
{

	int v,e;
	unordered_map<t,list<t> > adj;
	public:
	graph(int v, int e)
    {
    this-> v = v;
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
    void bfs(t src, unordered_map<t, bool> &visited)
    {
        queue<t> q;
        visited[src] = true;
        q.push(src);
        while(!q.empty())
        {
            t curr = q.front();
            q.pop();
            cout<<curr<<" , ";
            for(auto nbr:adj[curr])
            {
                if(!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }
    void bfsComp(t src)
    {
        int comp = 1;
        cout<<comp<<" => ";
        unordered_map<t, bool> visited;
        bfs(src,visited);
        for(auto node: adj)
        {
            t curr = node.first;
            if(!visited[curr])
            {
                comp++;
                cout<<endl<<comp<<" => ";
                bfs(curr, visited);
            }
        }
    }


};
int main()
{
	int v,e,src;
	cin>>v>>e;
	graph<int> g(v,e);
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
	g.bfsComp(src);
		return 0;
}

/*
10 9
1 2
1 3
2 4
2 3
5 6
6 7
5 7
9 10
10 11

1 => 1 , 2 , 3 , 4 ,
2 => 11 , 10 , 9 ,
3 => 7 , 6 , 5 ,


*/


