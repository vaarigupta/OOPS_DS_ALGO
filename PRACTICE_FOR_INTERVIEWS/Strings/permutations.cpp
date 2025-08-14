#include<iostream>
#include<vector>
using namespace std;
void permutation(int n,vector<int> nums,vector<vector<int> > &permute, int i)
{
	if(i==n)
	{
		permute.push_back(nums);
		return;
	}
	for(int j=i;j<n;j++)
	{
		swap(nums[i], nums[j]);
		permutation(n,nums,permute,i+1);
		swap(nums[i], nums[j]);
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
