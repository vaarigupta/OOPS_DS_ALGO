#include<iostream>
using namespace std;
void MazePath(int x, int y, int r,int c, string ans)
{
    if(x==r && y==c)
    {
        cout<<ans<<endl;
      //  ans = "";
        return;
    }
    ///Horizontal Move
    if(y+1<=c)
    {
          MazePath(x,y+1,r,c,ans+"H");
    }
    ///Vertical Move
    if(x+1<=r)
    {
        MazePath(x+1,y,r,c,ans+"V");
    }

}
int main()
{
    MazePath(0,0,2,2,"");
    return 0;
}
