//https://leetcode.com/problems/jump-game/
#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<char> memo(n,'u');
        memo[n-1] = 'g';
        for(int i=n-2;i>=0;i--)
        {
            int maxPossibleJump = min<int>(i+nums[i], n-1);
            for(int j= i+1;j<=maxPossibleJump;j++)
            {
                if(memo[j]=='g')
                {
                    memo[i] = 'g';
                    break;
                }
            }
        }
        if(memo[0]=='g')
        {
            return true;
        }
        return false;
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

