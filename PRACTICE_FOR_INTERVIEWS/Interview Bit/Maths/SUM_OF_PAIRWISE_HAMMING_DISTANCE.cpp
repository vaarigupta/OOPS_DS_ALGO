#include<iostream>
#include<vector>
using namespace std;
int mod = 1000000007;
//int hammingDistance(const vector<int> &A)
//{
//    int sum =0;
//    int n= A.size();
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            sum += __builtin_popcount(i^j);
//        }
//    }
//    return (sum%mod);
//
//}
int hammingDistance(const vector<int> &A)
{
    long long int cnt = 0, ans = 0;
    int n = A.size();
    for(int i=0;i<32;i++)
    {
        cnt = 0;
        for(int j=0;j<n;j++)
        {
            if(A[j]&(1<<i))
            {
                cnt++;
            }
        }

        ans = (ans + cnt*(n-cnt)*2)%mod;
    }
    return ans;

}
int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
    }
    cout<<hammingDistance(v);
    return 0;
}
