/*
https://leetcode.com/discuss/interview-question/625140/goldman-sachs-oa-2020-array-burst-problem-birthday-party
https://www.geeksforgeeks.org/reduce-the-string-by-removing-k-consecutive-identical-characters/
1. Array Burst Problem
Given an input length, String array and burst length(>0) as input, the output should be an array which is a shrunk input array such that the sequentially repeating elements more than or equal to burst length should be removed. This has to be repeated till the array cannot be shrunk any further. Use single characters in the string array for simplicity as shown in sample test cases.

Sample case 1 :
Input :
8
a
b
c
c
c
d
e
e
3
Output:
a
b
d
e
e

*/
#include <bits/stdc++.h>
using namespace std;

vector<string> getShrunkArray(vector<string> &v, int k) {

    vector<string> shrunkArray;
    int n = v.size();
    stack<pair<string,int> > stk;
    for(int i=0;i<n;i++) {
        string curr = v[i];
        // cout<<i<<" --  "<<curr<<" -- ";
        if(!stk.empty()) {
            if(stk.top().first == curr) {
                stk.top().second += 1;
                //cout<<i<<" -- I "<<stk.top().first<<endl;
            } else {
                if(stk.top().second >= k) {
                    stk.pop();
                    i--;
                // cout<<i<<" -- II "<<stk.top().first<<endl;
                } else {
                    stk.push({curr, 1});
               // cout<<i<<" --  III "<<stk.top().first<<endl;
                }
            }
        } else {
            stk.push({curr, 1});
            //cout<<i<<" --  IV "<<stk.top().first<<endl;
        }
    }

    if(!stk.empty() && stk.top().second >= k) {
        stk.pop();
    }

    while (!stk.empty()) {
        pair<string, int> p = stk.top();
        stk.pop();
        for(int i=0;i<p.second;i++) {
            shrunkArray.push_back(p.first);
        }
    }

    reverse(shrunkArray.begin(), shrunkArray.end());
    return shrunkArray;
}

int main() {

    vector<string> array = {"a","b","c","d","e","e","e","e","d","d","c","c","b","f","g","f"};
    int burstLength = 3;

    vector<string> ans = getShrunkArray(array,burstLength);
    cout<<endl;
    for(auto elem: ans)
      cout<<elem<<" "; // a b b f g f

    return 0;
}
