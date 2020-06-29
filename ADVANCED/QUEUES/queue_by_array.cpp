#include<iostream>
using namespace std;
class Queue
{
    int *q;
    int currSize;
    int MaxSize;
    int Front;
    int Rear;
public:

    Queue(int d)
    {
        q = new int[d];
        currSize = 0;
        MaxSize = d;
        Front = 0;
        Rear = d-1;
    }
    bool Isfull()
    {
        return currSize == MaxSize;
    }
    bool Isempty()
    {
        return currSize ==0;
    }
    void push(int data)
    {
        if(!Isfull())
        {
            Rear = (Rear+1)%MaxSize;
            q[Rear] =data;
            currSize++;
        }
    }
    void pop()
    {
        if(!Isempty())
        {
            Front = (Front+1)%MaxSize;
            currSize --;
        }
    }
    int getFront()
    {
        return q[Front];
    }

};
int main()
{
    Queue q(10);
    int r;
    cout<<"Enter the range of Queue : ";
    cin>>r;
    for(int i = 0;i<r;i++)
    {
        q.push(i);
    }
    q.pop();
    q.push(10);
    q.pop();
    q.push(13);
    while(!q.Isempty())
    {
        cout<<q.getFront()<<" ";
        q.pop();

    }


    return 0;
}
