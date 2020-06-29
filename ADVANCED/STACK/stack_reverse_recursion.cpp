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
/// If stack is empty then we push the top element of the function call stack into the original stack
///if its not empty then we pop all the elements until its empty and again push the topmost element of function call
///stack into the original stack and push again the held elements into the original stack
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
/// we pop the elements of the stack until its empty and hold all the elements onto the function call stack
///when the stack becomes empty then we call insertAtBottom function which insert all the held items
///one by one at the bottom of the stack
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
