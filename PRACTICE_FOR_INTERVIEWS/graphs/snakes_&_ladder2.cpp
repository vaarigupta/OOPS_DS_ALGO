#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int vertex;
	int dist;
	bool time;
	node(int v, int d)
	{
	    vertex =v;
	    dist =d;
	}
};
node getMinDiceThrows(vector<int> board, int N, int dice)
{

    vector<bool> visited(N+1,false);
    map<int,int> distance;
    map<int,int> parent;
    map<int ,int> cost;
    int cost_ladder=0;
    for(int i=0;i<=N;i++)
    {
        parent[i] = INT_MAX;
    }
    queue<node> q;
    node s(0,0);
    visited[0] = true;
    q.push(s);
    node curr(0,0);
    parent[0] = 0;
    //int cost =0;
    while(!q.empty())
    {
        curr = q.front();
        int curr_v = curr.vertex;
        //cout<<"Curr :"<<curr.vertex<<" "<<curr.dist<<" "<<endl;
        if(curr_v==N)
        {
            break;
        }
         q.pop();
        for(int j= curr_v+1; j<=(curr_v+dice) && j<=N;j++)
        {
            if(!visited[j])
            {
                node nbr(0,0);
                nbr.dist = curr.dist +1;
                distance[j] = nbr.dist;
                visited[j] = true;
                parent[j] = min(curr_v,parent[j]);
                if(board[j]!= -1)
                {
                    nbr.vertex = board[j];

                    if(board[j] >j)
                    {
                        parent[nbr.vertex] = min(parent[nbr.vertex],curr_v);
                        cost[board[j]] = (board[j] - j)*10;
                    }

                }
                else
                {
                    nbr.vertex = j;
                }

                q.push(nbr);
                //cout<<"Nbr "<<j<<": "<<visited[j]<<" "<<nbr.vertex<<" "<<nbr.dist<<endl;

            }
        }
    }
//    for(auto each : parent)
//    {
//        cout<<"Parent of "<<each.first<<" : "<<each.second<<endl;
//    }
//    int temp = N;
//    while(temp!=0)
//    {
//        cout<<temp<<"<=";
//        if(cost.count(temp))
//        {
//            cost_ladder += cost[temp];
//        }
//        temp = parent[temp];
//    }
//    cout<<0<<endl;
//    for(auto c:cost)
//    {
//        cout<<c.first<<" : "<<c.second<<endl;
//    }

    //cout<<cost_ladder<<endl;
    int max_time = N/dice;
    if( curr.dist <= max_time)
    {
        curr.time = true;
    }
    //cout<<max_time;
    return curr;

}

int main()
{
    int n,pairs,dice;
    cin>>n>>pairs>>dice;
    //cost =0;
    vector<int> board(n+1,-1);
    for(int i=0;i<pairs;i++)
    {
        int index, value;
        cin>>index>>value;
        board[index] = value;
    }
    node ans = getMinDiceThrows(board, n,dice);
    if(ans.time)
    {
        cout<<"You won"<<endl;
    }
    else
    {
        cout<<"You lost"<<endl;
    }
	cout << "Min Dice throws required is " <<ans.dist<<endl;
	return 0;
}

/*

30 8 6
3 22
5 8
20 29
11 26
17 4
19 7
21 9
27 1
30<=24<=22<=0
8 : 30
22 : 190
26 : 150
29 : 90
190
Min Dice throws required is 3

30 13 6
6 8
2 5
20 29
11 26
17 4
19 7
21 9
22 5
23 12
24 15
25 17
27 1
28 3
30<=26<=5<=0
5 : 30
8 : 20
26 : 150
29 : 90
180
Min Dice throws required is 3




36 10 6
2 15
5 7
9 27
18 29
25 35
17 4
20 6
24 16
32 30
34 12
36<=30<=29<=15<=0
7 : 20
15 : 130
27 : 180
29 : 110
35 : 100
240
Min Dice throws required is 4

9 4 4
2 5
4 3
6 8
7 1



9 4 2
2 5
4 3
6 8
7 1

Curr :0 0
Nbr 1: 1 1 1
Nbr 2: 1 5 1
Curr :1 1
Nbr 3: 1 3 2
Curr :5 1
Nbr 6: 1 8 2
Nbr 7: 1 1 2
Curr :3 2
Nbr 4: 1 3 3
Nbr 5: 1 5 3
Curr :8 2
Nbr 9: 1 9 3
Curr :1 2
Curr :3 3
Curr :5 3
Curr :9 3

Parent of 0 : 0
Parent of 1 : 0
Parent of 2 : 0
Parent of 3 : 1
Parent of 4 : 3
Parent of 5 : 3
Parent of 6 : 5
Parent of 7 : 5
Parent of 9 : 8

9<=8<=5<=0
5 : 30
8 : 20
50
Min Dice throws required is 3

6 2 2
2 4
5 3
6<=4<=0
4 : 20
20
Min Dice throws required is 2

*/

