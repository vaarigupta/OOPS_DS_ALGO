#include<iostream>
#include<stack>
///Stock Span Problem in which we have to compute the number of days needed to go back from the current day
using namespace std;
void print(int a[] , int n)
{
    cout<<"Array : ";
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;


}
int main()
{
    ///Declaration
    int a[20] , d , better[20];
    stack<int> s;

    ///Inputs
    cout<<"Enter the Total number of days:  ";
    cin>>d;
    cout<<"Enter the Stock Prices : ";
    for(int i =0;i<d;i++)
    {
        cin>>a[i];
    }

    ///Logic and Actual Code
    for(int day =0;day<d;day++)
    {
       int currPrice = a[day];
       ///Check at the top of the stack that it refers to the highest stock price
       while(!s.empty() && a[s.top()]<currPrice)
       {
           s.pop();
       }
       /// When stack is empty , return 0 otherwise top of the stack
       int betterDays = s.empty()? 0 : s.top();

       ///Compute the span
       int span = day- betterDays;
       better[day] = span;

       ///push the current day onto the stack
       s.push(day);
    }
    print(better,d);
    return 0;


}
