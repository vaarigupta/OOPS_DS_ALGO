#include<iostream>
#include<stack>

///Implementing Stack using inbuilt stack header file - push() , pop() , top()
using namespace std;

void print(stack<int> s)
{
    cout<<"Stack :- ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    stack <int> s;

    for(int i = 0;i<5;i++)
    {
        s.push(i);
    }
    print(s);
    return 0;
}
