#include<iostream>
#include<vector>
using namespace std;


void blockedMaze(vector<vector<int> > maze,vector<vector<bool> > visited,
                 string path, vector<string> output,
                 int i, int j,int m, int n)
{
    ///Positive base case
    if(i==m-1 && j==n-1)
    {
        cout<<path<<endl;
        output.push_back(path);
        return;
    }
    ///Negative base case
    if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || maze[i][j]==1)
    {
        return ;
    }
    visited[i][j] = true;
    blockedMaze(maze,visited,path+ "T", output, i-1,j,m,n);
    blockedMaze(maze,visited,path+ "B", output, i+1,j,m,n);
    blockedMaze(maze,visited,path+ "L", output,i,j-1,m,n);
    blockedMaze(maze,visited,path+ "R", output,i,j+1,m,n);
    visited[i][j] = false;

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
    int m = maze.size();
    int n = maze[0].size();
    vector<string> output;
    vector<vector<bool>> visited (m, vector<bool>(n, false ));
    blockedMaze(maze,visited, "",output,0,0,m,n);
    return 0;
}
