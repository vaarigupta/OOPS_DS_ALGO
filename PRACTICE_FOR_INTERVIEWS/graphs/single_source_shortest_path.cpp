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
	void sssp(t src)
	{
		unordered_map<t,bool> visited;
		unordered_map<t,t> parent;
		unordered_map<t,int> dist;
		queue<t> q;
		visited[src] = true;
		parent[src] = src;
		dist[src] = 0;
		q.push(src);
		while(!q.empty())
		{
			t curr = q.front();
			q.pop();

			for(auto nbr: adj[curr])
			{
				if(!visited[nbr])
				{
					visited[nbr] = true;
					parent[nbr] = curr;
					dist[nbr] = dist[curr] +1;
					q.push(nbr);
				}
			}
		}

		for(auto d: dist)
		{
			t node = d.first;
			int paths = d.second;
			cout<<"The shortest distance from "<<src<<" to "<<node<<" : "<<paths<<endl;
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
	g.sssp(src);
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
The shortest distance from 0 to 3 : 2
The shortest distance from 0 to 0 : 0
The shortest distance from 0 to 1 : 1
The shortest distance from 0 to 4 : 1
The shortest distance from 0 to 2 : 2
*/

