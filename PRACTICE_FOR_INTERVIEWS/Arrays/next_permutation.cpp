<<<<<<< HEAD
#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums) {

        int n= nums.size()-1;
        int smallIndex =-1;
        for(int i=n;i>=0;i--)
        {
            if( (i-1)>=0 && nums[i]> nums[i-1])
            {
                smallIndex = i-1;
                break;
            }
        }
        if(smallIndex!=-1)
        {
        int largeIndex = smallIndex+1;
        for(int k=smallIndex+1;k<=n;k++)
        {

            if(nums[k]> nums[smallIndex])
            {
                largeIndex = k;

            }
        }
        swap(nums[smallIndex], nums[largeIndex]);
       int i=smallIndex+1;
       int j = n;
        while(i<j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
       // reverse(nums.begin()+smallIndex, nums.begin()+n);
        }

        else
        {
             reverse(nums.begin(), nums.begin()+nums.size());
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
    nextPermutation(nums);
	return 0;
}


=======
#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums) {

        int n= nums.size()-1;
        int smallIndex =-1;
        for(int i=n;i>=0;i--)
        {
            if( (i-1)>=0 && nums[i]> nums[i-1])
            {
                smallIndex = i-1;
                break;
            }
        }
        if(smallIndex!=-1)
        {
        int largeIndex = smallIndex+1;
        for(int k=smallIndex+1;k<=n;k++)
        {

            if(nums[k]> nums[smallIndex])
            {
                largeIndex = k;

            }
        }
        swap(nums[smallIndex], nums[largeIndex]);
       int i=smallIndex+1;
       int j = n;
        while(i<j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
       // reverse(nums.begin()+smallIndex, nums.begin()+n);
        }

        else
        {
             reverse(nums.begin(), nums.begin()+nums.size());
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
    nextPermutation(nums);
	return 0;
}


>>>>>>> 4c5de0a8a9d94e48c4de388af9b5bf7d5fa58a85
