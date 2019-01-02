#include<iostream>
#include "Queue.h"
void createQueue(Queue &q)
{
    for(int i =0;i<10;i++)
    {
        q.push(i);
    }
}
 void print( Queue temp)
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
    Queue q(20);
    createQueue(q);
    q.pop();
    q.push(23);
    q.pop();
    q.push(45);
    q.pop();
    q.push(55);
    q.pop();
    q.push(65);
    print(q);


    return 0;
}
