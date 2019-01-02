#include<iostream>
#include<queue>
using namespace std;
void print( queue<int> q)
{
    cout<<"Queue :";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void reverse_rec(queue<int> &q)
{
    ///Base Case
    if(q.empty())
    {
        return;
    }
    /// Rec case
    else
    {
        int temp = q.front();
        q.pop();
        reverse_rec(q);
        q.push(temp);

    }
}
int main()
{
    queue <int > q;
    int r;
    cout<<"Enter the range of queue : ";
    cin>>r;
    for(int i =0;i<r;i++)
    {
        q.push(i);
    }
    print(q);
    reverse_rec(q);
    cout<<"Reverse ";
    print(q);
    return 0;
}
