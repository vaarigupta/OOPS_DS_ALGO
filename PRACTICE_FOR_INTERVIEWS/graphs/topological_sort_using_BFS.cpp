#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename t>
class graph
{
	unordered_map<t,list<t> > adj;
	int v,e;
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
	void topologicalSortBfs()
	{

		unordered_map<t,int> indeg;
		queue<t> q;
		for(auto node: adj)
		{
			t curr = node.first;
			indeg[curr] = 0;

		}
		for(auto node: adj)
		{
			t curr = node.first;
			for(auto nbr: adj[curr])
			{
				indeg[nbr]++;
			}
		}
		for(auto node: adj)
		{
			t curr = node.first;
			if(indeg[curr]==0)
			{
				q.push(curr);
			}
		}
		while(!q.empty())
		{
			t curr = q.front();
			cout<<curr<<"->";
			q.pop();
			for(auto nbr: adj[curr])
			{
					indeg[nbr]--;
					if(indeg[nbr]==0)
					{
						q.push(nbr);
					}

			}

		}
	}
};

int main()
{
	int v,e;
	cin>>v>>e;
	//graph<string> g(v,e);
	graph<int> g(v,e);
	for(int i=0;i<e;i++)
	{
		//string u,v;
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v,false);
	}
	g.topologicalSortBfs();
	return 0;
}



/*

4 4
0 1
0 2
2 3
1 3

0->1->2->3->



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
eng->Maths->coding->HTML->java->python->CSS->JS->WEB->

*/
