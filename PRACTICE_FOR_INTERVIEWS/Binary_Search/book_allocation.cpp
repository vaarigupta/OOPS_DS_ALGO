#include<iostream>
#include<vector>
#include<climits>
#define ll long long
using namespace std;
pair<ll,ll> subArraySum(vector<ll> arr,ll n, ll sum)
{
    /* Initialize curr_sum as value of
    first element and starting point as 0 */
    pair<ll,ll> p(-1,-1);
    ll curr_sum = arr[0], start = 0, i;

    /* Add elements one by one to curr_sum and
    if the curr_sum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        // If curr_sum becomes equal to sum,
        // then return true
        if (curr_sum == sum) {
           // cout << "Sum found between indexes "
            p.first = start;
            p.second = i-1;
            return p;
        }

        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }
    return p;
    // If we reach here, then no subarray
    //cout << "No subarray found";
    //return 0;
}
pair<bool,ll>  isPossible(ll N, vector<ll> books, ll stu, ll pages)
{
    pair<bool, ll> p(false,INT_MIN);
    ll curr_pages =0, curr_stu=1;
    ll prev=0;
    ll k=0;
    ll i=0;
    for( i=0;i<N;i++)
    {
        if(books[i]>pages)
        {
            p.first = false;
            p.second = 0;
            return p;
        }
        if(curr_pages+books[i]> pages)
        {

            k = i-prev;
            p.second = max(p.second,k);
            prev = i;
            curr_pages = books[i];
            curr_stu++;
            if(curr_stu>stu)
            {
                p.first = false;
                p.second = 0;
                return p;
            }
        }
        else
        {
            curr_pages += books[i];

        }
    }
    p.first = true;
    k = i-prev;
    p.second = max(p.second,k);
    return p;


}
pair<ll,ll> max_num_pages(ll N, vector<ll> books, ll stu)
{
    pair<ll,ll> p(-1,0);
    if(N<stu)
    {
        return p;
    }
    ll total_pages=0;
    for(ll i=0;i<N;i++)
    {
        total_pages += books[i];
    }
    ll ans = INT_MAX;
    ll s =0;
    ll e = total_pages;
    ll mid =0;
    //ll num = 0;
    while(s<=e)
    {
        mid = (s+e)/2;
        pair<bool,ll> possible = isPossible(N,books,stu,mid);
        if(possible.second)
        {

            ans = mid;
            p.first = ans;
            p.second= possible.first;
            e = mid-1;

        }
        else
        {
            s = mid+1;
        }

    }

    return p;


}
int main()
 {
	    ll total_books,students;
	    cin>>total_books;
	    vector<ll> books;
	    //vector<ll> dist(total_books,0);
	    //int total_pages = 0;
	    for(ll i=0;i<total_books;i++)
	    {
	        ll pages;
	        cin>>pages;
	       // total_pages += pages;
	        books.push_back(pages);
	    }
	    cin>>students;
	    pair<ll,ll> p = max_num_pages(total_books,books,students);
	    cout<<p.first<<endl;
	    pair<ll,ll> subarry = subArraySum(books,total_books,p.first);
	    ll start = subarry.first;
	    ll end_ = subarry.second;
	    cout<<"Elements :"<<(end_-start +1)<<endl;
	    for(ll i=start; i<=end_;i++)
        {
            cout<<books[i]<<" ";

        }

//	    for(int i=0;i<dist.size();i++)
//        {
//            cout<<dist[i]<<" ";
//        }
	return 0;
}
/*

Input:
2
4
12 34 67 90
2
3
15 17 20
2

4
12 34 67 90
2
113
12 34 67

Output:
113
32
4
12 34 67 90
2
113
Elements :3
12 34 67
*/
//https://www.geeksforgeeks.org/find-subarray-with-given-sum/
