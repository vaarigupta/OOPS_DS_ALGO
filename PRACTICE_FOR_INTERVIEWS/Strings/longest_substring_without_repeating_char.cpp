#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        int n = s.length(), res = 0;
        for(int i=0;i<n;i++)
        {
            bool visited[256] = {false};
            for(int j=i;j<n;j++)
            {
                if(visited[s[j]])
                {
                    break;
                }
                else
                {
                    res = max(res,j-i+1);
                    visited[s[j]] = true;
                }

            }

        }
        return res;
    }
int main()
{
    string str;
    cin>>str;
    //cout<<lengthOfLongestSubstring(str);
    cout<<longestUniqueSubsttr(str);

}

