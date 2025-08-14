#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool is_possible_allocation(int *pages, int N, int M, int min_pages)
{
    int curr_pages =0, students=1;
    for(int i=0;i<N;i++)
    {
        if(curr_pages+ pages[i] > min_pages)
        {
            curr_pages = pages[i];
            students++;
            if(students> M)
            {
                return false;
            }
        }
        else
        {
            curr_pages += pages[i];
        }
    }
    return true;
}
int max_pages(int *pages, int N, int M)
{
    int sum=0;
    for(int i=0;i<N;i++)
    {
        sum += pages[i];
    }
    int s = pages[N-1];
    int e = sum;
    int mid =0,ans= INT_MAX;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(is_possible_allocation(pages,N,M,mid))
        {
            ans = min(ans,mid);
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;;
        cin>>N>>M;
        int pages[101];
        for(int i=0;i<N;i++)
        {
            cin>>pages[i];
        }
        cout<<max_pages(pages,N,M)<<endl;
	}
	return 0;
}

/*
1
4 2
12 34 67 90





*/

