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
        int n = stk.size();
        stk.erase(stk.begin()+ n-1);
    }
    bool empty()
    {
        if(stk.size()==0)
        {
            return true;
        }
        return false;
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

