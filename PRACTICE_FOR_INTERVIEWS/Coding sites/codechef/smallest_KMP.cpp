#include<bits/stdc++.h>
using namespace std;
string smallest_kmp(string s, string p)
{
    if(s.length()==0 || p.length()==0)
    {
        return "";
    }
    if(s.length()==1 && p.length()==1)
    {
        return s;
    }
    if(s.length()==p.length())
    {
        return s;
    }
    int s_count[26] = {0};
    for(int i=0;s[i]!='\0';i++)
    {
        int index = s[i] - 'a';
        s_count[index]++;
    }
    for(int i=0;p[i]!='\0';i++)
    {
        int index = p[i] - 'a';
        s_count[index]--;
    }
    string compressed = "";
    for(int i=0;i<26;i++)
    {
        while(s_count[i])
        {
            char c = (char)(i + 'a');
            compressed+= c;
            s_count[i]--;
        }
    }
    int start=0;
    int i=0;
    while(compressed[i]!='\0')
    {
        if(compressed[i]<=p[0])
        {
            i++;
        }
        else
        {
            start = i;
            break;
        }
    }
    if(compressed[i]=='\0')
    {
        start = compressed.length();
    }
    compressed.insert(start,p);
    return compressed;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        string S,P;
        cin>>S>>P;
        cout<<smallest_kmp(S,P)<<endl;
    }
    return 0;
}
/*
sorted
3
akramkeeanany
aka
aaaaeekkmnnry

supahotboy
bohoty
abhoopstuy

daehabshatorawy
badawy
aaaabdehhorstwy

compressed
3
akramkeeanany
aka
aaeekmnnry

supahotboy
bohoty
apsu

daehabshatorawy
badawy
aaehhorst

input
3
akramkeeanany
aka
supahotboy
bohoty
daehabshatorawy
badawy

Actual output
3
akramkeeanany
aka
aaakaeekmnnry

supahotboy
bohoty
abohotypsu

daehabshatorawy
badawy
aabadawyehhorst

Test cases:
1
akkk
ka
OP--
kakk

1
abbbb
b
OP---
abbbb

1
abbbb
ba
OP--
babbb


*/
