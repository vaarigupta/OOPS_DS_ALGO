#include<iostream>
#include "Queue.h"
void createQueue(Queue<int>&q)
{
    for(int i =0;i<10;i++)
    {
        q.push(i);
    }
}
 void print( Queue<int> temp)
    {
    while(!temp.isEmpty())
    {
        cout<<temp.getFront()<<" ";
        temp.pop();
    }
    }
using namespace std;
int main()
{
    Queue<int> q(20);
    createQueue(q);
    q.pop();
    q.push(23);
    q.pop();
    q.push(45);
    q.pop();
    q.push(55);
    q.pop();
    q.push(65);
    cout<<"Your Queue :";
    print(q);


    return 0;
}
