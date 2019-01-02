using namespace std;
template <typename T>
class Queue
{
    T *q;
    int f , r , maxS , currS ;

public:
    Queue(int d)
    {
       q = new T[d];
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
    void push(T d)
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
    T getFront()
    {
        return q[f];
    }

};
