#include<iostream>
#include<queue>
using namespace std;
/// Stack implemented using two queues -> where
///push operation - O(1)
///pop operation - O(n)
class Stack
{

    queue<int> q1;
    queue<int> q2;
    int currSize;

    public:
    Stack()
    {
        currSize = 0;
    }
    void pushStack(int num)
    {
        q1.push(num);
        currSize++;
    }
    void popStack()
    {
       if(q1.empty())
       {
           return ;
       }
       while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();

        }

        q1.pop();
        currSize--;
        ///swap
        queue<int> q = q1;
        q1 = q2 ;
        q2 = q;


    }
    int top()
    {
        if(q1.empty())
        {
            return -1;
        }
       while(q1.size()!=1)
       {
           q2.push(q1.front());
           q1.pop();
       }
       ///last element of queue
        int temp = q1.front();
           q1.pop();
           q2.push(temp);
        ///swap
        queue<int> q = q1;
        q1 = q2 ;
        q2 = q;

        return temp;
    }
    int stackSize()
    {
        return currSize;
    }

};

int main()
{
    Stack s;
    s.pushStack(2);
    s.pushStack(3);
    s.pushStack(4);
    cout<<"Current Size : "<<s.stackSize()<<" "<<endl;
    cout<<"Top : "<<s.top()<<endl;
    s.popStack();
    cout<<"Current Size : "<<s.stackSize()<<" "<<endl;
    cout<<"Top : "<<s.top()<<endl;
    s.popStack();
    cout<<"Top : "<<s.top()<<endl;

    return 0;
}
