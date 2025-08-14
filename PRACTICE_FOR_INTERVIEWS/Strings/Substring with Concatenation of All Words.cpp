<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> words;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        words.push_back(s);
    }
     vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> count_words;
        int wcount = words.size();
        int n = s.length();
        int len = words[0].length();
        vector<int> index;
        if(n==0 || wcount==0) return index;
        if(n< (wcount*len))
        {
            return index;
        }
        for(int i=0;i<wcount;i++)
        {
            count_words[words[i]]++;
        }

        for(int i=0;i<=(n-(wcount*len));i++)
        {
            unordered_map<string,int> seen;
            int j=0;
            for(;j<wcount;j++)
            {
                int start = i+j*len;
                if(start>=n) break;
                string substr = s.substr(start,len);
                if(count_words.find(substr)!=count_words.end())
                {
                    seen[substr]++;
                    if(seen[substr]> count_words[substr])
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if(j==wcount)
            {
                index.push_back(i);
            }
        }
        return index;

    }
    return 0;
}
/*
3
cat bat rat
*/

=======
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> words;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        words.push_back(s);
    }
     vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> count_words;
        int wcount = words.size();
        int n = s.length();
        int len = words[0].length();
        vector<int> index;
        if(n==0 || wcount==0) return index;
        if(n< (wcount*len))
        {
            return index;
        }
        for(int i=0;i<wcount;i++)
        {
            count_words[words[i]]++;
        }

        for(int i=0;i<=(n-(wcount*len));i++)
        {
            unordered_map<string,int> seen;
            int j=0;
            for(;j<wcount;j++)
            {
                int start = i+j*len;
                if(start>=n) break;
                string substr = s.substr(start,len);
                if(count_words.find(substr)!=count_words.end())
                {
                    seen[substr]++;
                    if(seen[substr]> count_words[substr])
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if(j==wcount)
            {
                index.push_back(i);
            }
        }
        return index;

    }
    return 0;
}
/*
3
cat bat rat
*/

>>>>>>> 4c5de0a8a9d94e48c4de388af9b5bf7d5fa58a85
