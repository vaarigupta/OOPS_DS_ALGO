#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int> p(10010,1);
void primeSieve()
{
    //int p[10010] = {1};
    p[0] = 0;
    p[1] = 0;
    for(int i=2;i<10010;i++)
    {
        if(p[i])
        {
            for(int j=2*i;j<10010;j+=i)
            {
                p[j] = 0;
            }
        }
    }
    for(int i=0;i<1000;i++)
    {
        if(p[i])
        {
            cout<<i<<" ";
        }

    }

}
//bool is_possible(int C, int K, vector<int> x, int min_dis)
//{
//    int company =1;
//    int prev = x[0];
//    for(int i=1 ;i<C;i++)
//    {
//        if(x[i]-prev >= min_dis)
//        {
//            company++;
//            prev = x[i];
//            if(company==K)
//        {
//            return true;
//        }
//        }
//
//
//    }
//    if(company<K)
//    {
//        return false;
//    }
//    return true;
//
//}
//int min_dist(int C, int K, vector<int> x)
//{
//    sort(x.begin(),x.end());
//    int s = 0;
//    int e = x[C-1] - x[0];
//    int mid =0;
//    int ans = INT_MIN;
//    while(s<=e)
//    {
//        mid = (s+e)/2;
//        if(is_possible(C,K,x,mid))
//        {
//            ans = max(ans,mid);
//            s = mid+1;
//
//        }
//        else
//        {
//            e =mid-1;
//        }
//
//    }
//    return ans;
//}
int main()
{
    primeSieve();
//    int C, K;
//    cin>>C>>K;
//    vector<int> x;
//    primeSieve();
//    for(int i=0;i<C;i++)
//    {
//        int no;
//        cin>>no;
//        if(!p[no])
//        {
//            x.push_back(no);
//        }
//
//    }
//    int n = x.size();
//    ///products are more than the available spots
//    if(n<K)
//    {
//        K = n;
//    }
//    cout<<n<<" "<<min_dist(C,K,x);
    return 0;
}
/*
5 3
1 2 8 4 9

5 3
1 2 8 4 9
5 3
*/

