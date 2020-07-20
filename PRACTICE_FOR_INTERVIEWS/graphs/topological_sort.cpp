#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename t>
class graph
{
	int v,e;
	unordered_map<t,list<t> > adj;
	public:
	graph(int v, int e)
	{
		this->v = v;
		this->e = e;
	}
	void addEdge(int u, int v, bool bidir = true)
	{
		adj[u].push_back(v);
		if(bidir)
		{
			adj[v].push_back(u);
		}

	}
	void dfsHelper(t node, unordered_map<t,bool> &visited , list<t> ordering)
{
		visited[node] = true;
		for(auto nbr: adj[node])
		{
			if(!visited[nbr])
			{
				dfsHelper(nbr,visited,ordering);
			}
		}
		ordering.push_front(node);
}
	void topologicalSortDfs()
{
	unordered_map<t,bool> visited;
	list<t> ordering;
	for(auto node: adj)
	{
		t curr = node.first;
		if(!visited[curr])
			{
				dfsHelper(curr,visited,ordering);
			}
	}
	for(auto element: ordering)
	{
		cout<<element<<"->";
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
		g.addEdge(u,v,false);

	}
	g.topologicalSortDfs();
	return 0;
}

