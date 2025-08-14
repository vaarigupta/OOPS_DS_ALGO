#include<bits/stdc++.h>
using namespace std;
///https://leetcode.com/problems/reverse-words-in-a-string/
///Given an input string, reverse the string word by word.
 string reverseWords(string s) {
      string output ="";
        if(s== "")
        {
            return output;
        }
        stack<string> stk;
        int i=0;
        while(s[i]!='\0')
        {
            string word = "";
            if(s[i]==' ')
            {
                i++;
                continue;
            }
            while(s[i]!='\0' && s[i]!=' ')
            {
                word += s[i];
                i++;
            }
            stk.push(word);
            if(s[i]== '\0')
            {
                break;
            }
            i++;
        }

        while(!stk.empty())
        {
            output += (stk.top() + " ");
            stk.pop();
        }
     if(output.length())
     {
         output.erase(output.length()-1,1);

     }
        return output;

    }
int main()
{
    string str;
    getline(cin,str);
    cout<<reverseWords(str);
    return 0;
}
