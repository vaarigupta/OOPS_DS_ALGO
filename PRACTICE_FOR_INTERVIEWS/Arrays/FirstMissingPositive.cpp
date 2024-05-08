#include<bits/stdc++.h>
using namespace std;

int missingNumber(int nums[], int n)
{
        sort(nums,nums+n);
        int missing = 1;
        int i=0;
        while(nums[i]<=0)
        {
            i++;
        }
        while(i<n && nums[i]==missing)
        {  //cout<<missing<<endl;
            missing++;
           i++;
        }
        return missing;
}




int main()
{

    int n = 7;
    int nums[] = {-1,-2,1,2, 3, 4, 5};
    int ans = missingNumber(nums,n);
    cout<<ans;

}
