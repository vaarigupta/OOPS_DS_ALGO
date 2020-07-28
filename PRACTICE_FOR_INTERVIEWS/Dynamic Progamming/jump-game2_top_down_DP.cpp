//https://leetcode.com/problems/jump-game/
#include<iostream>
#include<vector>
using namespace std;
vector<char> indexTypes;
bool reachLastIndex(int index, vector<int> nums)
{

        if(indexTypes[index]!='u')
        {
            return indexTypes[index]=='g'?true:false;
        }

    int maxPossibleJump = min<int> (index + nums[index], nums.size()-1);
    for(int i=index+1; i<=maxPossibleJump;i++)
    {
        if(reachLastIndex(i,nums))
        {
            indexTypes[i] = 'g';
            return true;
        }
    }
    indexTypes[index] = 'b';
    return false;
}
bool canJump(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        indexTypes.push_back('u');

    }
    indexTypes[n-1] = 'g';
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

