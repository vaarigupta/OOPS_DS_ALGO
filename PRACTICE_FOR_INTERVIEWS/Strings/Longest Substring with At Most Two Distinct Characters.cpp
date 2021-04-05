///https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstringTwoDistinct(string s)
{
    int n= s.length();
    if(n<3)
    {
        return n;
    }
    int maxlen = 2;
    int left =0, right =0;
    unordered_map<char,int> count;
    while(right<n)
    {
        if(count.size()<3)
        {
            count[s[right]] = right;
            right++;
        }
        if(count.size()==3)
        {

            auto left_most = count.begin();
            int index = left_most->second;
            count.erase(left_most->first);
            left = index+1;
        }

        maxlen = max(maxlen,right-left);
    }
    return maxlen;
}
int main()
{
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstringTwoDistinct(s)<<endl;

    return 0;
}
/*
eceba
3
ccaabbb
4
*/
