#include<iostream>
#include<stack>
using namespace std;
void print(stack <int> s)
{
    cout<<"Stack : ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void insertAtbottom(stack<int> &s , int item)
{
    if(s.empty())
    {
        s.push(item);
    }
    else
    {
    int temp = s.top();
    s.pop();
    insertAtbottom(s,item);
    s.push(temp);
    }


}
void reverseRec(stack <int> &s)
{
    if(s.empty())
    {
        return;
    }
    else
    {

    int temp = s.top();
    s.pop();
    reverseRec(s);
    insertAtbottom(s,temp);
    }

}
int main()
{
    stack<int> s;
    int n , d;
    cout<<"Enter the range of the stack"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>d;
        s.push(d);
    }
    print(s);
    cout<<"Reverse a stack using Recursion" <<endl;
    reverseRec(s);
    print(s);

    return 0;
}
