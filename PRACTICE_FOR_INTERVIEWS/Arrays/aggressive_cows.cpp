//#include<iostream>
//#include<algorithm>
//#include<climits>
//#include<vector>
//#define ll long long
//using namespace std;
//bool Is_cows_placed(vector<ll> X, int stalls , int cows, ll min_dist)
//{
//
//    ll curr_loc = X[0];
//    int c =1;
//    for(int i=1;i<stalls;i++)
//    {
//        if(c==cows)
//        {
//            return true;
//        }
//        if(X[i]-curr_loc >=min_dist)
//        {
//            c++;
//            curr_loc = X[i];
//        }
//
//    }
//    if(c==cows)
//    {
//        return true;
//    }
//    return false;
//}
//ll min_dist(vector<ll> X, int stalls, int cows)
//{
//    sort(X.begin(),X.end());
//    ll s= 0;
//    ll e = X[stalls-1] - X[0];
//    ll mid =0, ans = INT_MIN;
//    while(s<=e)
//    {
//        mid = (s+e)/2;
//        if(Is_cows_placed(X,stalls,cows,mid))
//        {
//            ans = max(ans, mid);
//            s = mid+1;
//        }
//        else
//        {
//            e = mid-1;
//        }
//    }
//    return ans;
//
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int stalls,Cows;
//        cin>>stalls>>Cows;
//        vector<ll> X;
//        for(int i=0;i<stalls;i++)
//        {
//            ll cord;
//            cin>>cord;
//            X.push_back(cord);
//        }
//        cout<<min_dist(X,stalls,Cows)<<endl;
//
//
//    }
//
//    return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define ll long long
using namespace std;
bool cows_placed(vector<ll> X, int stalls , int cows, ll min_dist)
{
	ll curr_loc = X[0];
	int c = 1;
	for(int i=1;i<stalls;i++)
	{
		if(c==cows)
		{
			return true;
		}
		if(X[i]-curr_loc >= min_dist)
		{
			c++;
			curr_loc = X[i];
		}
	}
	if(c==cows)
	{
		return true;
	}
	return false;
}
ll min_dist(vector<ll> X, int stalls, int cows)
{
	sort(X.begin(), X.end());
	ll s = 0 , e = X[stalls-1] - X[0] , mid =0 , ans = INT_MIN;
	while(s<=e)
	{
		mid = (s+e)/2;
		if(cows_placed(X, stalls, cows, mid))
		{
			ans = max(ans, mid);
			s = mid+1;
		}
		else
		{
			e = mid-1;
		}


	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int stalls, cows;
		cin>>stalls>>cows;
		vector<ll> X;
		for(int i=0;i<stalls;i++)
		{
			ll coord;
			cin>>coord;
			X.push_back(coord);
		}
		cout<<min_dist(X,stalls,cows)<<endl;
	}
	return 0;
}
