#include<iostream>
#include<list>
#include<utility>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;
template<typename t>
class Graph
{
	public:
	int V;
	unordered_map<t, list<pair<t,int>> > adjl; //list of pairs as values - first - value, second - edge weight
	t source()
	{
		auto start = adjl.begin();
		return start->first;
	}
	void add(t u, t v,int weight, bool bidir=true)
	{
		adjl[u].push_back({v,weight});
		if(bidir)
		{
		   adjl[v].push_back({u,weight});
		}
	}
	void print()
{
	for(auto x: adjl)
		{
			cout<<x.first<<" =>";
			for(auto node:x.second)
			{
				cout<<"( "<<node.first<<", "<<node.second<<" ) ,";
			}
			cout<<endl;
		}
}
void Dijkstra(t src)
{
	unordered_map<t,int> dist;
	set<pair<int,t> > s; //first - dist , second - node
	for(auto node: adjl)
	{
		dist[node.first] = INT_MAX;
	}
	dist[src] = 0;
	s.insert({0,src});

	while(!s.empty())
	{
		auto curr = s.begin();
		t node = curr->second;
		int distTillNow = curr->first;
		s.erase(curr);
	 for(auto nbrPair: adjl[node])
	 {
		auto nbr = nbrPair.first;
		auto weight = nbrPair.second;

		if(distTillNow + weight < dist[nbr])
		{
		    auto f = s.find({dist[nbr],nbr});
			if(f!=s.end())
            {
                s.erase({dist[nbr],nbr});
            }
			dist[nbr] = distTillNow + weight;
			s.insert({dist[nbr],nbr});
		}
 }
	}
	for(auto d: dist)
	{
		cout<<"Shortest Distance btw "<<src<<" and "<<d.first<<" : "<<d.second<<endl;
	}
}
};

int main()
{
	Graph<int> g;
	g.add(0,1,1);
	g.add(0,3,7);
	g.add(0,2,4);
	g.add(1,2,1);
	g.add(2,3,2);
	g.add(3,4,3);
	g.print();
	int source = g.source();
	cout<<endl;
	g.Dijkstra(0);
	return 0;
}

/*
4 =>( 3, 3 ) ,
2 =>( 0, 4 ) ,( 1, 1 ) ,( 3, 2 ) ,
3 =>( 0, 7 ) ,( 2, 2 ) ,( 4, 3 ) ,
0 =>( 1, 1 ) ,( 3, 7 ) ,( 2, 4 ) ,
1 =>( 0, 1 ) ,( 2, 1 ) ,

Shortest Distance btw 0 and 1 : 1
Shortest Distance btw 0 and 0 : 0
Shortest Distance btw 0 and 3 : 4
Shortest Distance btw 0 and 4 : 7
Shortest Distance btw 0 and 2 : 2
*/
