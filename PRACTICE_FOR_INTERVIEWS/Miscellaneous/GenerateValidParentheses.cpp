#include<iostream>
using namespace std;
void GenerateParanthesis(int open, int close, int n, string ans)
{
    if(open==n && close==n)
    {
        cout<<ans<<endl;
        return;
    }
    if(open+1<=n)
    {
     GenerateParanthesis(open+1,close,n,ans+"(");
    }
    if(close+1<=n && close+1<=open)
    {
        GenerateParanthesis(open,close+1,n,ans+")");
    }

}
int main()
{
    GenerateParanthesis(0,0,4,"");

    return 0;
}
