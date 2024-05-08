#include<iostream>
#include<stack>
#include<vector>
using namespace std;

string findFilePath(vector<string> path)
{
    stack<string> stk;
    int n = path.size();
    for(int i=0;i<n;i++)
    {
        if(path[i]==".." && (!stk.empty()))
            stk.pop();
        else
            stk.push(path[i]);
    }
    return stk.top();
}
int main()
{
    vector<string> path = {"a", "b","..", "c", "d","..", "r",".."};

    string ans = findFilePath( path);
    cout<<ans<<endl;



    return 0;
}
