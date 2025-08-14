#include<bits/stdc++.h>
using namespace std;
/*Program to print all substrings of a given string
Given a string as an input. We need to write a program that will print all non-empty substrings of that given string.
*/
Given a string as an input. We need to write a program that will print all non-empty substrings of that given string.
void substrings(string s)
{
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        string temp = "";
        for(int j =i; j<n;j++)
        {
            temp+= s[j];
            cout<<temp<<endl;
        }
    }
}
int main()
{
    string str;
    cin>>str;
    substrings(str);
    return 0;
}
