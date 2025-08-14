#include<bits/stdc++.h>
using namespace std;
/*
https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0
Longest Distinct characters in string
Given a string S, find length of the longest substring with all distinct characters.
For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.
*/
bool unique_char(string s)
{
    unordered_map<char,bool> distinct;
    for(int i=0;i<s.length();i++)
    {
        if(distinct[s[i]])
        {
            return false;
        }
        distinct[s[i]] = true;
    }
    return true;
}
void substrings(string s)
{
    int n = s.length(), len =0, max_len = 0;
    string ans;
    for(int i=0;i<n;i++)
    {
        string temp = "";
        for(int j =i; j<n;j++)
        {
            temp+= s[j];
            len = temp.length();
            if(unique_char(temp) && len> max_len)
            {
                max_len = len;
                ans = temp;
            }
            //cout<<temp<<endl;
        }
    }
    cout<<ans;
}
int main()
{
    string str;
    cin>>str;
    substrings(str);
    return 0;
}

