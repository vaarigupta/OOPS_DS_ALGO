#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename t>
class graph
{
	unordered_map<t,list<t>> adj;
	int v,e;
	public:
	graph(int v, int e)
	{
	this->v = v;
	this->e = e;
	}
	void addEdge(int u, int v,bool bidir = true)
	{
		adj[u].push_back(v);
		if(bidir)
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

	void bfs(t src)
	{
	unordered_map<t,bool> visited;
	queue<t> q;
	visited[src] = true;
	q.push(src);
	while(!q.empty())
	{
		t curr = q.front();
		q.pop();
		cout<<curr<<" , ";
		for(auto nbr: adj[curr])
		{
			if(!visited[nbr])
			{
				q.push(nbr);
				visited[nbr] = true;
			}
		}
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
		g.addEdge(u,v);
	}
	g.printGraph();
	g.bfs(0);
return 0;
}

/*
6 7
0 1
1 2
2 4
4 3
3 5
0 4
2 3
5 -> 3 ,
3 -> 4 , 5 , 2 ,
0 -> 1 , 4 ,
1 -> 0 , 2 ,
2 -> 1 , 4 , 3 ,
4 -> 2 , 3 , 0 ,
0 , 1 , 4 , 2 , 3 , 5 ,
*/
