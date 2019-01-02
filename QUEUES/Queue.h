using namespace std;
class Queue
{
    int *q;
    int f , r , maxS , currS ;

public:
    Queue(int d)
    {
       q = new int[d];
       maxS = d;
       currS = 0;
       f =0;
       r =  maxS -1;
    }
    bool isEmpty()
    {
        return currS==0;
    }
    bool isFull()
    {
        return currS == maxS;
    }
    void push(int d)
    {
        if(!isFull())
        {
            r = (r+1)%maxS;
            q[r] = d;
            currS++;
        }

    }
    void pop()
    {
        if(!isEmpty())
        {
            f = (f+1)%maxS;
            currS--;
        }
    }
    int getFront()
    {
        return q[f];
    }

};
