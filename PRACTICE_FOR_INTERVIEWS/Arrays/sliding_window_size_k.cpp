#include<iostream>
#include<deque>
#include<vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        int i=0;
        vector<int> output;
        for( i=0;i<k;i++)
        {
            while(!(dq.empty()) && (nums[i]>= nums[dq.back()]))
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(;i<n;i++)
        {
            output.push_back(nums[dq.front()]);
            while(!(dq.empty()) && dq.front()<= (i-k))
            {
                dq.pop_front();
            }

            while(!(dq.empty()) && (nums[i] >= nums[dq.back()]))
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        output.push_back(nums[dq.front()]);

        return output;

    }
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> info;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        info.push_back(num);
    }
    vector<int> output = maxSlidingWindow(info,k);
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;
}

/*
8 4
4 5 6 7 8 9 1 2
*/



#include<deque>
class Solution {
public:

};
