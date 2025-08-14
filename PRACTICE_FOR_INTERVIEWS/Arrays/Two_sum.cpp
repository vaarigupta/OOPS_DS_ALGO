#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/
vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> m;
       // vector <pair<int,int>> dummy;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            //mapping.push_back(make_pair(nums[i],i));
            pair<int,int> p(nums[i],i);
            m.push_back(p);
        }

        sort(m.begin(), m.end());
        int i=0, j =n-1;
        vector<int> ans;
        while(i<j)
        {
            if(m[i].first+ m[j].first == target)
            {
                ans.push_back(m[i].second);
                ans.push_back(m[j].second);
                return ans;
               // return { m[i].second , m[j].second };
            }
            else if( m[i].first+ m[j].first > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

      /*  vector <pair<int,int>> dummy;
        for(int i = 0 ; i < nums.size() ; i++){
            dummy.push_back({nums[i],i});
        }
        sort(dummy.begin(),dummy.end());
        int i = 0 ;
        int j = nums.size()-1;
        vector <int> ans;
        while(i < j ){
            if((dummy[j].first + dummy[i].first) == target){
                ans.push_back(dummy[i].second);
                ans.push_back(dummy[j].second);
                break;
            }
            else if((dummy[j].first + dummy[i].first) < target){

                i++;
            }
            else{
                j--;
            }
        }
     return ans;

        */
    }
int main()
{
    int n,target;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++)
    {

        int no;
        cin>>no;
        v.push_back(no);
    }
    cin>>target;
    vector<int> ans = twoSum(v,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}


/*

4
2 4 7 10
9
0 2

*/
