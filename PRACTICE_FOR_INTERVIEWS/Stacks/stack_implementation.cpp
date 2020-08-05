#include<iostream>
#include<vector>
using namespace std;
template<typename t>
class stack
{
public:
    vector<t> stk;
    void push(t x)
    {
        stk.push_back(x);
    }
    void pop()
    {
        stk.pop_back();
    }
    bool empty()
    {
        return stk.size()==0?true: false;
    }
    t top()
    {
        return stk[stk.size()-1];
    }

};
int main()
{
    stack<int> s;
    s.push(3);
    s.push(4);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

