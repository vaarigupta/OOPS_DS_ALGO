#include<iostream>
#include<vector>
using namespace std;
void BlockedMazePath(vector<vector<int>> maze, int cr, int cc, int er, int ec, string ans,  vector<vector<bool>> visited)
{
    if(cr==er && cc==ec)
    {
        cout<<ans<<endl;
       // ans="";
        return;
    }
    if(maze[cr][cc]==1)
    {
        return;
    }
    visited[cr][cc] =true;

    ///Move top
    if(cr-1>=0 && maze[cr-1][cc]!=1 && !visited[cr-1][cc])
    {
    BlockedMazePath(maze,cr-1,cc,er,ec,ans+"T",visited);
    }

    ///move down
    if(cr+1<=er && maze[cr+1][cc]!=1 && !visited[cr+1][cc])
    {
    BlockedMazePath(maze,cr+1,cc,er,ec,ans+"D",visited);
    }

    ///Move left
    if(cc-1>=0 && maze[cr][cc-1]!=1 && !visited[cr][cc-1])
    {
    BlockedMazePath(maze,cr,cc-1,er,ec,ans+"L",visited);
    }

    ///move right
    if(cc+1<=ec && maze[cr][cc+1]!=1 && !visited[cr][cc+1])
    {
        BlockedMazePath(maze,cr,cc+1,er,ec,ans+"R",visited);
    }
        visited[cr][cc] =false;

}
int main()
{
    vector<vector<int>> maze
    {
        {
            0,1,0,0
        },
        {
            0,0,0,0
        },
        {
            0,1,0,0
        },
        {
            0,1,1,0
        }
    };
    vector<vector<bool>> visited (maze.size(), vector<bool>(maze[0].size(), false ));
    BlockedMazePath(maze,0,0,3,3,"",visited);
    return 0;
}

/*

DRRRDD
DRRDRD
DRRTRDDD


*/
