#include<iostream>
#include<stack>
using namespace std;

bool balanced_paren(char * arr)
{
   stack <char> s;
   for(int i = 0;arr[i]!='\0';i++)
   {
       char ch = arr[i];
       switch(ch)
       {
           case '{':
           case '[':
           case  '(': s.push(ch);
                      break;


           case ']':
                  if(!s.empty() && s.top()=='[')
                  {
                      s.pop();
                      break;
                  }
                  else
                  {
                      return false;
                  }
           case '}':
                  if(!s.empty() && s.top()=='{')
                  {
                      s.pop();
                      break;
                  }
                  else
                  {
                      return false;
                  }
           case ')':
                  if(!s.empty() && s.top()=='(')
                  {
                      s.pop();
                      break;
                  }
                  else
                  {
                      return false;
                  }

       }
   }

   return s.empty();
}
int main()
{
    char a[30] = "{([A+B]- [C*D])-([E/f])}";
    if(balanced_paren(a))
    {
        cout<<"Yes , We have balanced Parenthesis"<<endl;
    }
    else
    {
        cout<<"Not Having Balanced Parenthesis"<<endl;
    }

    return 0;
}
