#include<bits/stdc++.h>
using namespace std;
void print(unordered_set<int> s)
{
    for(auto i = s.begin(); i!=s.end();i++)
    {
       cout<<(*i)<<" ";
    }
    cout<<endl;
}
int findLongestConsecutiveSubseq(int* A, int n)
{
    unordered_set<int> s;
//    int n = A.size();
    for(int i=0;i<n;i++)
    {
        s.insert(A[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int count =0;
        if(s.find(A[i]-1)== s.end())
        {
            int j = A[i];
            while(s.find(j)!=s.end())
            {
                count++;
            }
            ans = max(ans,count);
        }

    }
    return ans;

}
int main()
{
    int arr[] = {36,36,45,33,32, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findLongestConsecutiveSubseq(arr,n);
    return 0;
}
