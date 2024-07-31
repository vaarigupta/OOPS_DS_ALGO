#include<iostream>
#include<vector>
using namespace std;
void permutation(int n,vector<int> nums,vector<vector<int> > &permute, int first)
{
	if(first==n)
	{
		permute.push_back(nums);
		return;
	}
	for(int i=first;i<n;i++)
	{
		swap(nums[first], nums[i]);
		permutation(n,nums,permute,first+1);
		swap(nums[first], nums[i]);
	}
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
	vector<vector<int> > permute;
	permutation(n,nums, permute,0);
	for(int i=0;i<permute.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<permute[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
/*

3
1 2 3
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
3 1 2
*/
