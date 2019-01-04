#include<iostream>
#include<queue>
using namespace std;
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

//class Stack
//{
//    queue<int> q1, q2;
//    int curr_size;
//
//    public:
//    Stack()
//    {
//        curr_size = 0;
//    }
//
//    void pop()
//    {
//        if (q1.empty())
//            return;
//
//        // Leave one element in q1 and
//        // push others in q2.
//        while (q1.size() != 1)
//        {
//            q2.push(q1.front());
//            q1.pop();
//        }
//
//        // Pop the only left element
//        // from q1
//        q1.pop();
//        curr_size--;
//
//        // swap the names of two queues
//        queue<int> q = q1;
//        q1 = q2;
//        q2 = q;
//    }
//
//    void push(int x)
//    {
//        q1.push(x);
//        curr_size++;
//    }
//
//    int top()
//    {
//        if (q1.empty())
//            return -1;
//
//        while( q1.size() != 1 )
//        {
//           q2.push(q1.front());
//           q1.pop();
//        }
//
//        // last pushed element
//        int temp = q1.front();
//
//        // to empty the auxiliary queue after
//        // last operation
//        q1.pop();
//
//        // push last element to q2
//        q2.push(temp);
//
//        // swap the two queues names
//        queue<int> q = q1;
//        q1 = q2;
//        q2 = q;
//        return temp;
//    }
//
//    int size()
//    {
//        return curr_size;
//    }
//};
//
//// driver code
//int main()
//{
//    Stack s;
//    s.push(1);
//    s.push(2);
//    s.push(3);
//    s.push(4);
//
//    cout << "current size: " << s.size()
//         << endl;
//    cout << s.top() << endl;
//    s.pop();
//    cout << s.top() << endl;
//    s.pop();
//    cout << s.top() << endl;
//    cout << "current size: " << s.size()
//         << endl;
//    return 0;
//}
