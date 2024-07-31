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
void dfsHelper(t node, unordered_map<t,bool> &visited)
{
	visited[node] = true;
	cout<<node<<" , ";
	for(auto nbr: adj[node])
	{
		if(!visited[nbr])
		{
			dfsHelper(nbr, visited);

		}
	}
}
void dfsForest(t src)
{
	unordered_map<t,bool> visited;
	int comp = 1;
	cout<<comp<<"=>";
	dfsHelper(src,visited);
	for(auto node: adj)
	{
        t curr = node.first;
		if(!visited[curr])
		{
			comp++;
			cout<<endl<<comp<<"=>";
			dfsHelper(curr,visited);
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
	g.dfsForest(src);
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

1=>1 , 2 , 4 , 3 ,
2=>11 , 10 , 9 ,
3=>7 , 6 , 5 ,
*/
