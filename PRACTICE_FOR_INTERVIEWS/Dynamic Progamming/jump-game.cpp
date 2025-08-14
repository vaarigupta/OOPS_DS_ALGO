//https://leetcode.com/problems/jump-game/
#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int> nums, int n)
{
	int goodIndex = n-1;
	for(int i=n-2;i>=0;i--)
	{
		if(i+nums[i]>=goodIndex)
		{
			goodIndex = i;
		}
	}
	return goodIndex==0?true:false;
}
int main()
{
	int n;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		nums.push_back(no);

	}
	if(canJump(nums, n))
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}
/*

5
3 2 1 0 4
NO

*/
