#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<pair<int,long long int>> *l;
    public:
        Graph(int n)
        {
            V = n;
            l = new list<pair<int,long long int>>[V+1];
        }
    void add_edge(int u,int v,long long int weight)
    {
        l[u].push_back(make_pair(v,weight));
        l[v].push_back(make_pair(u,weight));
    }
    int dfs_helper(int source,bool *visited,int *nodeCount,long long int &ans)
    {
        visited[source] = true;
        nodeCount[source] = 1;
        for(auto itr:l[source])
        {
            if(!visited[itr.first])
            {   nodeCount[source]+=dfs_helper(itr.first,visited,nodeCount,ans);
                ans+= 2*min(nodeCount[itr.first],V-nodeCount[itr.first])*itr.second;
            }
        }
        return nodeCount[source];
    }
    int dfs()
    {
        bool *visited = new bool[V+1]{0};
        int *nodeCount = new int[V+1]{0};
        long long int ans = 0;
        for(auto itr:l[1])
        {
            if(!visited[itr.first])
            {
                dfs_helper(itr.first,visited,nodeCount,ans);
                break;
            }
        }
        return ans;
    }
};
int main()
{
    int t,a=1;
    cin>>t;
    while(a<=t)
    {
        int n;
        cin>>n;
        Graph g(n);
        while(n>1)
        {
            n--;
            int i,j;long long int k;
            cin>>i>>j>>k;
            g.add_edge(i,j,k);
        }
        cout<<"Case #"<<a<<": "<<g.dfs()<<endl;
        a++;
    }
}
