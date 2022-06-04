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

void BFS(t src)
{
	unordered_map<t,bool> visited;
	queue<t> q;
	q.push(src);
	visited[src] = true;
	while(!q.empty())
	{
		auto curr = q.front();
		cout<<curr<<" ";
		q.pop();
		for(auto nbr : adjl[curr])
		{
			if(!visited[nbr])
			{
				visited[nbr] = true;
				q.push(nbr);
			}
		}

	}
}
void DFSHelper(t src, unordered_map<t,bool>& visited)
{
	cout<<src<<" ";
	visited[src] = true;
	for(auto nbr: adjl[src])
	{
		if(!visited[nbr])
		 {
			DFSHelper(nbr,visited);
		 }
	}
}
	void DFS(t source)
	{
		unordered_map<t,bool> visited;
		DFSHelper(source,visited);
	}
void SSSP(t src, t dest)
	{
		unordered_map<t,int> dist;
        unordered_map<t,t> parent;
		for(auto edge : adjl)
		{
			dist[edge.first] = INT_MAX;
		}
		queue<t> q;
		q.push(src);
		dist[src] = 0;
		parent[src] = src;
		while(!q.empty())
		{
			auto curr = q.front();
			q.pop();
			for(auto nbr: adjl[curr])
			{
			    if(dist[nbr]==INT_MAX)
				{
					dist[nbr] = dist[curr]+1;
					parent[nbr] = curr;
					q.push(nbr);
				}
			}
		}

		cout<<" Distance between "<<src<<" and "<<dest<<" :"<<dist[dest]<<endl;
		while(dest!=src)
		{
			cout<<dest<<"=>";
			dest = parent[dest];
		}
		cout<<src<<endl;
	}
bool CycleDetectionBFS(t src)
{
	unordered_map<t,bool> visited;
	unordered_map<t,t> parent;
	queue<t> q;
	q.push(src);
	visited[src] = true;
	cout<<src<<"-- Parent : "<<src<<endl;
	parent[src] = src;
	while(!q.empty())
	{
		t curr = q.front();
		q.pop();
		for(auto nbr: adjl[curr])
		{

            if(visited[nbr] && parent[curr]!=nbr)
            {
                cout<<nbr<<"-- Parent : (last)"<<curr<<endl;
                return true;
            }
            if(!visited[nbr])
			{
				visited[nbr] = true;
				parent[nbr] = curr;
				cout<<nbr<<"-- Parent : "<<curr<<endl;
				q.push(nbr);
            }
        }
	}
	return false;

}

};

int main()
{
	Graph<int> g;
	g.add(1,2);
	g.add(1,3);
	g.add(2,3);
	g.add(2,4);
	g.add(3,5);
	g.print();
	int source = g.source();
	g.BFS(source);
    cout<<endl;
	g.DFS(source);
	g.SSSP(1,4);
	string hasCycle = g.CycleDetectionBFS(1)? "yes":"NO";
	cout<<" Cycle present : "<<hasCycle<<endl;
	return 0;
}
/*


5 =>3 ,
4 =>2 ,
3 =>1 , 2 , 5 ,
1 =>2 , 3 ,
2 =>1 , 3 , 4 ,
5 3 1 2 4
5 3 1 2 4  Distance between 1 and 4 :2
4=>2=>1
1-- Parent : 1
2-- Parent : 1
3-- Parent : 1
3-- Parent : (last)2
 Cycle present : yes

 */
