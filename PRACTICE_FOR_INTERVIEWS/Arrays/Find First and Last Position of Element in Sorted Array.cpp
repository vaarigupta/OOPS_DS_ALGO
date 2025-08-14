///https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
int lowerBound(vector<int>& nums, int s, int e,int target)
{
    int mid = 0;
    int ans = -1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(target==nums[mid])
        {
            ans =mid;
            e = mid-1;
        }
        else if (nums[mid]<target)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;

        }

    }
    return ans;

}
int upperBound(vector<int>& nums, int s, int e,int target)
{

    int mid = 0;
    int ans = -1;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(target==nums[mid])
        {
            ans =mid;
            s = mid+1;
        }
        else if (nums[mid]<target)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;

        }

    }
    return ans;
}
 vector<int> searchRange(vector<int>& nums, int target)
{
    int lb = lowerBound(nums,0, nums.size()-1,target);
    int ub = upperBound(nums,0, nums.size()-1,target);
    vector<int> ans = {lb,ub};
    return ans;

}
int main()
{
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
	    int num;
	    cin>>num;
		arr.push_back(num);
	}
	int target;
	cin>>target;
	vector<int> output = searchRange(arr,target);
	cout<<output[0]<<" "<<output[1]<<endl;

	return 0;
}

/*

5
2 3 1 0 5
*/

