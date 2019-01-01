#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> s)
{
    cout<<"Stack"<<endl;
    while(!s.empty())
    {
       cout<<s.top()<<" ";
       s.pop();
    }
    cout<<endl;
}
void reverseStack (stack<int> &s , int range)
{
    ///int save[5] = {0};
    int *save = new int[range];
    int i = 0;
    while(!s.empty())
    {
       save[i] = s.top();
       s.pop();
       i++;
    }
    for(int i = 0; i < range;i++)
    {
        s.push(save[i]);

    }


}
void insert(stack <int> &s , int range)
{
    cout<<"Enter the elements"<<endl;
    int d;
        for(int i = 0;i<range;i++)
    {
        cin>>d;
        s.push(d);
    }
    cout<<endl;
}
int main()
{
    stack<int> s;
    int range;
    cout<<"Enter the range of stack "<<endl;
    cin>>range;
    insert(s ,range);
    cout<<"Original";
    print(s);
    reverseStack(s,range);
    cout<<"Reverse ";
    print(s);

    return 0;
}
