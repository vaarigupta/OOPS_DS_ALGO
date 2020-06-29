#include<bits/stdc++.h>
using namespace std;
template<typename t>
class graph
{
    public:
        map<t, list<pair<t,int> > > m;

        void addEdge(t u, t v, int dist,bool bidir = true)
        {
            m[u].push_back(make_pair(v,dist));
            if(bidir)
            {
                m[v].push_back(make_pair(u,dist));
            }

        }
        void printGraph()
        {
            for(auto l: m) ///  l refers to each pair of key and value like an iterator
            {
                cout<<l.first<<" => ";///l.first refers to the key of type t
                for(auto x:l.second ) /// l.second refers to the value which is a list
                {
                    cout<<"("<<x.first<<","<<x.second<<")";
                }
                cout<<endl;
            }
        }
        void dijikstra(t src, t dest)
        {
            unordered_map<t, int> dist;
            unordered_map<t,t> parent;
            set<pair<int,t>> s;
            for(auto each: m)
            {
                dist[each.first] = INT_MAX;
            }
            dist[src] = 0;
            parent[src] = src;
            s.insert(make_pair(0,src));
            while(!s.empty())
            {
                auto curr = *(s.begin());
                int currDist = curr.first; ///In first - we store its distance from the source
                t currNode = curr.second; /// In second - we store the actual name of the node (key)
                s.erase(s.begin());
                for(auto nbr : m[currNode]) /// represents a whole list where "nbr" represents the individual node of the list
                {
                    t dest = nbr.first;
                    int d = nbr.second;
                    if(d + currDist < dist[dest])
                    {

                        auto f = s.find(make_pair(dist[dest],dest));
                        if(f!=s.end())
                        {
                            s.erase(f);
                        }
                        dist[dest] = d + currDist;
                        s.insert(make_pair(dist[dest],dest));
                        parent[dest] = currNode;

                    }
                }

            }
            for(auto d:dist)
            {
                cout<<" The shortest distance from "<<src<<" to "<<d.first<<" : "<<d.second<<endl;
            }

            t source = src;
            t target = dest;
            //cout<<target<<"<=";
            while(target!=source)
            {
                cout<<"Distance between "<<target<<" and "<<parent[target]<<" : "<<dist[target] - dist[parent[target]]<<endl;
                target = parent[target];
            }


        }

};


int main()
{
        graph<int> g;
        g.addEdge(0,4,1);
        g.addEdge(0,1,2);
        g.addEdge(1,2,3);
        g.addEdge(2,4,1);
        g.addEdge(2,3,2);
        g.addEdge(3,4,2);
        g.addEdge(3,5,4);
       // g.printGraph();
        g.dijikstra(0,5);
    return 0;
}

/*

 The shortest distance from 0 to 5 : 7
 The shortest distance from 0 to 4 : 1
 The shortest distance from 0 to 0 : 0
 The shortest distance from 0 to 1 : 2
 The shortest distance from 0 to 2 : 2
 The shortest distance from 0 to 3 : 3

 */
