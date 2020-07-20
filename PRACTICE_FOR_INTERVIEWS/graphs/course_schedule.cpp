///https://leetcode.com/problems/course-schedule/
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
    bool bfs(t src, unordered_map<t, bool> &visited, unordered_map<t,t> &parent)
    {
        queue<t> q;
        visited[src] = true;
        parent[src] = src;
        q.push(src);
        while(!q.empty())
        {
            t curr = q.front();
            q.pop();
            for(auto nbr:adj[curr])
            {
                if(visited[nbr] && nbr!=parent[curr])
                {
                    return true;
                }
                if(!visited[nbr])
                {
                    parent[nbr] = curr;
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return false;
    }
    bool canFinish()
    {

        unordered_map<t, bool> visited;
        unordered_map<t,t> parent;
        for(auto node: adj)
        {
            t curr = node.first;
            if(!visited[curr])
            {

                if(bfs(curr, visited,parent))
                {
                    return true;
                }
            }
        }
        return false;
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
	if(g.canFinish())
    {
        cout<<"Not possible"<<endl;
    }
    else
    {
        cout<<"Possible"<<endl;
    }

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

1 => 1 , 2 , 3 , 4 ,
2 => 11 , 10 , 9 ,
3 => 7 , 6 , 5 ,

 6 5
 1 2
 2 3
 3 4
 4 5
 5 6
*/

