///https://leetcode.com/problems/group-anagrams/
#include<bits/stdc++.h>
using namespace std;
string sorting(string s)
{
    sort(s.begin(), s.end());
    return s;
}
///O(NKlogK), where N is the size of strs, and K is the maximum length of a string in strs. The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(KlogK) time.
vector<vector<string>> groupAnagrams1(vector<string>& strs) {

        int s = strs.size();
        unordered_map<string,list<int> > grp;
        for(int i=0;i<s;i++)
        {
            string temp = sorting(strs[i]);
            grp[temp].push_back(i);
        }
        vector<vector<string> > output;
        for(auto g: grp)
        {
            vector<string> temp;
            for(auto index:g.second)
            {
                temp.push_back(strs[index]);

            }
            output.push_back(temp);
        }
        return output;
    }
///O(NK), where N is the size of strs, and K is the maximum length of a string in strs. Counting each string is linear in the size of the string, and we count every string.
vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string> > output;
    if(strs.size()==0) return output;
    unordered_map<string, vector<string> > grps;
    /// grps - to map sorted string with its anagram -
    ///key - sorted string
    ///value - corresponding anagram
    for(int i=0;i<strs.size();i++)
    {
        string s = strs[i];
        int count[26] = {0};
        ///do counting sort
        for(int j=0;s[j]!='\0';j++) count[s[j]-'a']++;
        string key = "";
        for(int k=0;k<26;k++)
        {
            ///repeat 'a'+k for count[k] times
            key += string(count[k], 'a' + k);
        }
        ///key - sorted string of the current anagram
        grps[key].push_back(s);
    }
    for(auto itr: grps)
    {
        output.push_back(itr.second);
    }
    return output;

}
int main()
{

    int n;
    cin>>n;
    vector<string> strs(n,"");
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        strs[i] = str;
    }
    vector<vector<string> > groups = groupAnagrams(strs);
    cout<<groups.size()<<endl;
    for(int i=0;i<groups.size();i++)
    {
        for(int j=0;j<groups[i].size();j++)
        {
            cout<<groups[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
6
eat
tea
tan
ate
nat
bat

6
eat
tea
tan
ate
nat
bat
bat
tan nat
eat tea ate
*/

