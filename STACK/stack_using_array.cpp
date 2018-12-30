#include<iostream>
#include<vector>
using namespace std;
/// template - used for making a generic class
template<typename T>
class stackVect
{
    vector<T> v;
public:
    ///push(insert) elements onto the stack
    void push( T data)
    {
        v.push_back(data);

    }
    ///removing the top most element - LIFO (last In First Out)
    void pop()
    {
        v.pop_back();
    }
    ///returns the the topmost element from the stack
    T top()
    {
        return v[v.size()-1];
    }
    ///returns whether a stack is empty or not
    bool empty()
    {
        if(v.size()==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


};
/// passed by value only -here s is an object whose copy is made
///in case of arrays - they are passed by reference and copy of the pointer is made
void printInt(stackVect<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}
void printChar(stackVect<char> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}
void printStr(stackVect<string> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}

int main()
{
    stackVect<int> s1;
    for(int i = 0;i<5;i++)
    {
        s1.push(i*2);
    }
    cout<<"Integer Stack :- ";
    printInt(s1);
    cout<<endl;
//    cout<<"Stack :- ";
//    printInt(s1);

    stackVect<char> s2;
    for(int i = 0;i<=5;i++)
    {
       s2.push(65+i);
    }
    cout<<"Character Stack :- ";
    printChar(s2);
    cout<<endl;

    stackVect<string> s3;
    s3.push("vaari");
    s3.push("and");
    s3.push("Dhruv");
    printStr(s3);

    return 0;
}
