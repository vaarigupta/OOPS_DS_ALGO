//https://leetcode.com/problems/jump-game/
#include<iostream>
#include<vector>
using namespace std;

bool reachLastIndex(int index, vector<int> nums)
{
    if(index==nums.size()-1)
    {
        return true;
    }
    int maxPossibleJump = min<int> (index + nums[index], nums.size()-1);
    for(int i=index+1; i<=maxPossibleJump;i++)
    {
        if(reachLastIndex(i,nums))
        {
            return true;
        }
    }
    return false;
}
bool canJump(vector<int>& nums) {
    return reachLastIndex(0,nums);


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
	if(canJump(nums))
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

