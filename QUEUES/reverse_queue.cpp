#include<iostream>
#include<queue>
using namespace std;
void print(queue<int> q)
{
    cout<<"Queue :";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main()
{
    queue<int> q;
    int a[6] , i= 0;
    for(int i = 0;i<6;i++)
    {
        q.push(i);
    }
    print(q);
    while(!q.empty())
    {
        a[i] = q.front();
        q.pop();
        i++;
    }
    for(int j = 5;j>=0;j--)
    {
        q.push(a[j]);
    }
    print(q);
    return 0;
}
