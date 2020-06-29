#include<iostream>
#include<stack>
using namespace std;
bool checkRedundancy(char exp[])
{
    stack <int> s;
    for(int i = 0;exp[i]!='\0';i++)
    {
        char ch = exp[i];
        switch(ch)
        {
            case '(': s.push('(');
                      break;
            case ')': if(s.top()== '(')
                         {
                             return false;
                         }
                         else
                         {
                             while(s.top()!='(')
                             {
                                 s.pop();
                             }
                             s.pop();
                             break;
                         }
              default : s.push(ch);
        }
    }
    return true;
}
int main()
{
    char exp[] = "((c-d) + ((a+b)))";
    if(checkRedundancy(exp))
    {
        cout<<"No it is not having redundant brackets"<<endl;
    }
    else
    {
        cout<<"Yes it is having  redundant brackets"<<endl;
    }
    return 0;
}
