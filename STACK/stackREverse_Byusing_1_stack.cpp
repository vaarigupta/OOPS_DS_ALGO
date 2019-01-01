#include<iostream>
#include<stack>
using namespace std;
void transfer(stack<int> &s1 , stack<int> &s2 ,int n)
{
    for(int i = 0;i<n;i++)
    {
        int top = s1.top();
        s1.pop();
        s2.push(top);

    }
}
void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    stack<int> s;
    int n;
    cout<<"Enter the range of elements : ";
    cin>>n;
    for(int i =0;i<n;i++)
    {
        s.push(i);
    }
    print(s);
    cout<<endl;
    stack<int> temp;
    for(int i =0;i<n;i++)
    {
        int top = s.top();
        s.pop();
        transfer(s,temp ,n-i-1);
        s.push(top);
        transfer(temp,s , n-i-1);
    }
    print(s);

    return 0;
}
