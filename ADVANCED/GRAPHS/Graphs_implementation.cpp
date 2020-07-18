//1. Implementation of Graphs:
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename t>
class graph
{
	int v, e;
	unordered_map<t, list<t> > adj;
	public:
	graph(int v, int edges)
	{
		this->v = v;
		e = edges;

	}

void addEdge(int u, int v, bool bidir = true)
	{
		adj[u].push_back(v);
		if( bidir)
		{
			adj[v].push_back(u);
		}

	}
	void printGraph()
{
	for(auto node: adj)
	{
		cout<<node.first<<" -> ";
		for(auto nbr: node.second)
		{
		cout<<nbr<<" , ";
		}
		cout<<endl;
	}
}
};
int main()
{
	cout<<"Enter nodes and edges ";
	int v,e;
	cin>>v>>e;
	graph<int> g(v,e);
	cout<<"Enter Edges : "<<endl;
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	g.printGraph();
	return 0;


}




