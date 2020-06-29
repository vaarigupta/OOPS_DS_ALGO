#include<iostream>
#include<vector>
using namespace std;
class heap
{
    vector<int> v;
    bool minHeap;
public:
    heap(bool type = true)
    {
        minHeap = type;
        v.push_back(-1);
    }
    bool compare(int a , int b)
    {
        if(minHeap)
        {
            return a<b;
        }
        else
        {
            return a>b;
        }
    }

    void push(int data)
    {
        ///Push data to the last index
        v.push_back(data);
        ///find out its appropriate position in the heap
        int index = v.size() -1;
        int parent = index/2;
        while(v.size()>1 && compare(v[index] , v[parent]))
        {
            swap(v[index],v[parent]);
            index = parent;
            parent = parent/2;
        }

    }

    int top()
    {
        return v[1];
    }
    void heapify(int i)
    {
        int left = 2*i;
        int right = 2*i +1;

        int minIndex= i;
        if(left< v.size() && compare(v[left],v[i]))
        {
            minIndex = left;
        }
        if(right < v.size() && compare(v[right] , v[minIndex]))
        {
            minIndex = right;
        }
        if(minIndex!= i)
        {
            swap(v[i],v[minIndex]);
            heapify(minIndex);
        }

    }
    void pop()
    {
        int last = v.size() -1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size() == 1;
    }

};
int main()
{
  heap h;
  int d;
  for(int i =0;d!= -1;i++)
  {
      cout<<"Enter the value :";
      cin>>d;
      h.push(d);
  }
   while(!h.empty())
   {
    cout<<h.top()<<" ";
    h.pop();

   }

}
