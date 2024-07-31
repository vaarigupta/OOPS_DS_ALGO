#include<bits/stdc++.h>
using namespace std;
template<typename t>

///from coding blocks
class graph
{
public:
    map<t,list<t> > m;
    graph()
    {

    }
    void addEdge(t u, t v, bool bidir=true)
    {
        m[u].push_back(v);
        if(bidir)
        {
            m[v].push_back(u);
        }
    }
    void printGraph()
    {
        for(auto l:m)
        {
            cout<<l.first<<" =>";
            for(auto n:l.second)
            {
                cout<<n<<" , ";
            }
            cout<<endl;
        }
    }
    void sssp(t src, t dest)
    {
        unordered_map<t,int> dist;
        unordered_map<t,t> parent;
        queue<t> q;
        for(auto x:m)
        {
            dist[x.first] = INT_MAX;
        }
        dist[src] = 0;
        parent[src] = src;
        q.push(src);
        while(!q.empty())
        {
            t curr = q.front();
            q.pop();
            for(auto x: m[curr])
            {
                if(dist[x]==INT_MAX)
                {
                    dist[x] = dist[curr] + 1;
                    parent[x] = curr;
                    q.push(x);

                }
            }
        }
        cout<<"The minimum distance from "<<src<<" to "<<dest<<" : "<<dist[dest]<<endl;
        int temp = dest;
        while(dest!=src)
        {
            cout<<dest<<"<=";
            dest = parent[dest];
        }
//        for(auto x: m)
//        {
//            cout<<"The minimum distance from "<<src<<" to "<<x.first<<" : "<<dist[x.first]<<endl;
//        }
    }
};
int main()
{
    int n,pairs,src,dest;
    cin>>n>>pairs;
    vector<int> board(n+1,0);
    for(int i=0;i<pairs;i++)
    {
        int index, value;
        cin>>index>>value;
        board[index] = value;
    }
     graph<int> g;
    for(int u=0;u<=n;u++)
    {
        for(int dice=1;dice<=2;dice++)
        {
            int v = u + dice + board[u+dice];
            //cout<<u<<" "<<v<<endl;
            g.addEdge(u,v,false);
        }
    }
    cin>>src>>dest;
    g.sssp(src,dest);
    return 0;
}

/*

9 4
2 5
4 3
6 8
7 1


9 4
2 3
4 -1
6 2
7 -6
0 9
The minimum distance from 0 to 9 : 3
9<=8<=5<=

0 1
0 5
1 5
1 3
2 3
2 3
3 3
3 5
4 5
4 8
5 8
5 1
6 1
6 8
7 8
7 9
8 9
8 70453433
9 70453433
9 29712

---------------------
6 2 2
2 2
5 -3




1
36 10
2 13
5 2
9 18
18 11
17 -13
20 -14
24 -8
25 -10
32 -2
34 -22
0 36
The minimum distance from 0 to 36 : 4



36 10
2 13
5 2
9 18
18 11
17 -13
20 -14
24 -8
25 -10
32 -2
34 -22
The minimum distance from 0 to 0 : 0
The minimum distance from 0 to 1 : 1
The minimum distance from 0 to 2 : 2147483647
The minimum distance from 0 to 3 : 1
The minimum distance from 0 to 4 : 1
The minimum distance from 0 to 5 : 2147483647
The minimum distance from 0 to 6 : 1
The minimum distance from 0 to 7 : 1
The minimum distance from 0 to 8 : 2
The minimum distance from 0 to 9 : 2147483647
The minimum distance from 0 to 10 : 2
The minimum distance from 0 to 11 : 2
The minimum distance from 0 to 12 : 2
The minimum distance from 0 to 13 : 2
The minimum distance from 0 to 14 : 3
The minimum distance from 0 to 15 : 1
The minimum distance from 0 to 16 : 2
The minimum distance from 0 to 17 : 2147483647
The minimum distance from 0 to 18 : 2147483647
The minimum distance from 0 to 19 : 2
The minimum distance from 0 to 20 : 2147483647
The minimum distance from 0 to 21 : 2
The minimum distance from 0 to 22 : 3
The minimum distance from 0 to 23 : 3
The minimum distance from 0 to 24 : 2147483647
The minimum distance from 0 to 25 : 2147483647
The minimum distance from 0 to 26 : 3
The minimum distance from 0 to 27 : 2
The minimum distance from 0 to 28 : 3
The minimum distance from 0 to 29 : 2
The minimum distance from 0 to 30 : 3
The minimum distance from 0 to 31 : 3
The minimum distance from 0 to 32 : 2147483647
The minimum distance from 0 to 33 : 3
The minimum distance from 0 to 34 : 2147483647
The minimum distance from 0 to 35 : 3
The minimum distance from 0 to 36 : 4

Graph Edges
0 1
0 15
0 3
0 4
0 7
0 6
1 15
1 3
1 4
1 7
1 6
1 7
2 3
2 4
2 7
2 6
2 7
2 8
3 4
3 7
3 6
3 7
3 8
3 27
4 7
4 6
4 7
4 8
4 27
4 10
5 6
5 7
5 8
5 27
5 10
5 11
6 7
6 8
6 27
6 10
6 11
6 12
7 8
7 27
7 10
7 11
7 12
7 13
8 27
8 10
8 11
8 12
8 13
8 14
9 10
9 11
9 12
9 13
9 14
9 15
10 11
10 12
10 13
10 14
10 15
10 16
11 12
11 13
11 14
11 15
11 16
11 4
12 13
12 14
12 15
12 16
12 4
12 29
13 14
13 15
13 16
13 4
13 29
13 19
14 15
14 16
14 4
14 29
14 19
14 6
15 16
15 4
15 29
15 19
15 6
15 21
16 4
16 29
16 19
16 6
16 21
16 22
17 29
17 19
17 6
17 21
17 22
17 23
18 19
18 6
18 21
18 22
18 23
18 16
19 6
19 21
19 22
19 23
19 16
19 15
20 21
20 22
20 23
20 16
20 15
20 26
21 22
21 23
21 16
21 15
21 26
21 27
22 23
22 16
22 15
22 26
22 27
22 28
23 16
23 15
23 26
23 27
23 28
23 29
24 15
24 26
24 27
24 28
24 29
24 30
25 26
25 27
25 28
25 29
25 30
25 31
26 27
26 28
26 29
26 30
26 31
26 30
27 28
27 29
27 30
27 31
27 30
27 33
28 29
28 30
28 31
28 30
28 33
28 12
29 30
29 31
29 30
29 33
29 12
29 35
30 31
30 30
30 33
30 12
30 35
30 36
31 30
31 33
31 12
31 35
31 36
31 37
32 33
32 12
32 35
32 36
32 37
32 -283519595
33 12
33 35
33 36
33 37
33 -283519595
33 50901
34 35
34 36
34 37
34 -283519595
34 50901
34 12745344
35 36
35 37
35 -283519595
35 50901
35 12745344
35 12714217
36 37
36 -283519595
36 50901
36 12745344
36 12714217
36 41
*/
