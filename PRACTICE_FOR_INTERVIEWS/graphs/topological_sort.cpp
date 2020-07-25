#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
///Topological Sort using DFS
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
	void addEdge(t u, t v, bool bidir = true)
	{
		adj[u].push_back(v);
		if(bidir)
		{
			adj[v].push_back(u);
		}

	}
	void dfsHelper(t node, unordered_map<t,bool> &visited , list<t> &ordering)
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
	int v,e;
	cin>>v>>e;
	graph<int> g(v,e);
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v,false);

	}
	g.topologicalSortDfs();
	return 0;
}
/*
2 2
0 1
1 0
4 4
1 2
3 1
2 4
4 3

1->2->3->4->


9 12
eng HTML
eng coding
Maths coding
coding HTML
HTML CSS
CSS JS
JS WEB
coding java
coding python
python WEB
java WEB
coding JS

Maths->eng->coding->HTML->CSS->JS->python->java->WEB->
 */
