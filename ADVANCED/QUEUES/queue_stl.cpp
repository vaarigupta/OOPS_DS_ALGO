#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    for(int i = 0;i<7;i++)
    {
        q.push(i);
    }
    cout<<"Your queue : ";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
