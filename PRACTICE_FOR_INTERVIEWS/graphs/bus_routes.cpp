int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {

    unordered_map<int,vector<int> > stops_to_routes;
    int r = routes.size();
    for(int i=0;i<r;i++)
    {
        for(auto j:routes[i])
        {
            stops_to_routes[j].push_back(i);
        }
    }
    queue<pair<int,int>> bfs;
    bfs.push({S,0});
    unordered_set<int> visited;
    visited.insert(S);
    while(!bfs.empty())
    {
        auto f = bfs.front();
        bfs.pop();
        int bus_stop = f.first;
        int buses = f.second;
        if(bus_stop==T)
        {
            return buses;
        }
        for(auto i:stops_to_routes[bus_stop])
        {
            for(auto x:routes[i])
            {
                if(visited.find(x)==visited.end())
                {
                    bfs.push({x,buses+1});
                    visited.insert(x);
                }
            }
            routes[i].clear();
        }
    }
    return -1;

}

/*
4 3
0 1 2
0 3 4
2 5 6
4 7 6
0 7
2





*/
