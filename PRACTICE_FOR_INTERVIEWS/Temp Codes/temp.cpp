#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> nums {1,2,9,3,5,6,7,10};
    int n = nums.size();
    sort(nums.begin(), nums.begin()+n);
    for(int i=0;i<n;i++)
    {

        cout<<nums[i]<<" ";
    }

    return 0;
}
