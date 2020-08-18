///https://leetcode.com/problems/swim-in-rising-water/
#include<bits/stdc++.h>
using namespace std;
class cell
{
    public:
    int x,y,value;
    cell(int i, int j, int v): x(i), y(j), value(v) {}
    bool operator < (const cell &c) const
    {
        return value > c.value;
    }

};
inline bool isValid(int i, int j, int n)
{
    return (i>=0 && i<n && j>=0 && j<n);
}
int swimInWater( vector<vector<int> > grid)
{
    int n = grid.size();
    vector<vector<int> > time(n, vector<int> (n,-1));
    int x0[4] = {-1,1,0,0};
    int y0[4] = {0,0,-1,1};
    priority_queue<cell> pq;
    pq.push(cell(0,0,grid[0][0]));
    time[0][0] = grid[0][0];
    while(time[n-1][n-1]==-1)
    {
        cell curr = pq.top();
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int x = curr.x + x0[i];
            int y = curr.y + y0[i];
            if(isValid(x,y,n) && time[x][y]==-1)
            {
                int t = max(curr.value, grid[x][y]);
                pq.push(cell(x,y,t));
                time[x][y] = t;
            }

        }

    }
    return time[n-1][n-1];

}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> > grid(n, vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            grid[i][j] = num;
        }
    }
    cout<<swimInWater(grid)<<endl;

    return 0;
}
/*
5
0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

16
*/
