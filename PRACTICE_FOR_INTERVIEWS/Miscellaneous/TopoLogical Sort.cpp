#include<iostream>
#include<list>
#include<utility>
#include<queue>
#include<unordered_map>
using namespace std;
template<typename t>
class Graph
{
	public:
	int V;
	unordered_map<t, list<t> > adjl;
	t source()
	{
		auto start = adjl.begin();
		return start->first;
	}
	void add(t u, t v, bool bidir=true)
	{
		adjl[u].push_back(v);
		if(bidir)
		{
		   adjl[v].push_back(u);
		}
	}
	void print()
{
	for(pair<t,list<t>> x: adjl)
		{
			cout<<x.first<<" =>";
			for(auto num:x.second)
			{
				cout<<num<<" , ";
			}
			cout<<endl;
		}
}

void DFS(t node,unordered_map<t,bool> & visited, list<t> &ordering)
{
	visited[node] = true;
	for(auto nbr: adjl[node])
	{
		if(!visited[nbr])
		{
			DFS(nbr,visited,ordering);
}
}
ordering.push_front(node);
}
void TopologicalSortDFS()
{
	unordered_map<t,bool> visited;
	list<t> ordering;
	for(auto  vertex : adjl)
	{
	    if(!visited[vertex.first])
        {
            DFS(vertex.first,visited,ordering);
        }

	}
	for(auto node: ordering)
    {
        cout<<node<<" ";
    }
}

void TopologicalSortBFS()
	{
		unordered_map<t,int> indegree;
        for(auto node: adjl)
		{
				indegree[node.first] = 0;
		}
		for(auto node: adjl)
		{
			for(auto nbr: node.second)
			{
				indegree[nbr]++;
			}
		}

		queue<t> q;
		for(auto x: indegree)
		{
            cout<<x.first<<" "<<x.second<<endl;
			if(x.second==0)
				q.push(x.first);
		}
        cout<<endl;
		while(!q.empty())
		{
			t curr = q.front();
			cout<<curr<<"-> ";
			q.pop();
			for(auto nbr: adjl[curr])
			{
				indegree[nbr]--;
				if(indegree[nbr]==0)
					q.push(nbr);
			}
		}
	}


};

int main()
{
	Graph<int> g;
	g.add(1,2,false);
	g.add(1,3,false);
	g.add(2,3,false);
	g.add(2,4,false);
	g.add(3,5,false);
	g.print();
	int source = g.source();
	g.TopologicalSortDFS();
	cout<<endl;
	g.TopologicalSortBFS();
    cout<<endl;
	return 0;
}

/*

3 =>5 ,
1 =>2 , 3 ,
2 =>3 , 4 ,

*/
