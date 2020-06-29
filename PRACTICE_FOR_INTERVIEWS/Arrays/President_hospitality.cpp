#include <iostream>
#include<climits>
#define num 100000
using namespace std;
int store_fib[100000] = {0};;
long long fib(int prata)
{
    store_fib[0] =0;
    store_fib[1] = 1;
    long long sum_fib = store_fib[0] + store_fib[1];
    for(int i=2;i<=prata;i++)
    {
        store_fib[i] = store_fib[i-1] + store_fib[i-2];
        sum_fib += store_fib[i];
    }
    return sum_fib;
}
bool pratas_possible(int *ranks, int prata,int cook, int min_time)
{
    int count_prathas =0;
    int curr_time = 0,i=0;
    int r=0;
    //fib(prata);
    for( r=0;r<cook;r++)
    {
        i=0;
        curr_time = 0;
        while(curr_time<=min_time)
        {
            i++;
            curr_time += ranks[r]*store_fib[i];

        }
        count_prathas += (i-1);
        cout<<"Cook :"<<ranks[r]<< " -> "<<(i-1)<<endl;
        if(count_prathas >=prata)
        {
            return true;
        }

    }
    if(count_prathas<prata)
    {
        return false;
    }
    if(r==cook && count_prathas==prata)
    {
        return true;
    }

}
int min_time(int *ranks, int prata,int cook, int max_rank, int sum)
{
    int s =0;
    long long e = max_rank*sum;
    int mid =0;
    int ans = INT_MAX;
    while(s<=e)
    {
        mid = (s+e)/2;
        cout<<"s :"<<s<<" ,e :"<<e<<" ,Mid "<<mid<<endl;
        if(pratas_possible(ranks,prata,cook,mid))
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
	    ///P - no of pratas required
	    /// C - No of Cooks
        int Prata, Cook;
        cin>>Prata>>Cook;
        int ranks[51]; /// denotes rank of each cook
        int max_rank = INT_MIN;
        for(int i=0;i<Cook;i++)
        {
            cin>>ranks[i];
            max_rank = max(max_rank, ranks[i]);
        }
        long long sum = fib(Prata);
        cout<<min_time(ranks,Prata,Cook, max_rank, sum)<<endl;
	}
	return 0;
}

/*





1
8
8 1 1 1 1 1 1 1 1
s :0 ,e :54 ,Mid 27
Cook :1 -> 6
Cook :1 -> 6
s :0 ,e :26 ,Mid 13
Cook :1 -> 5
Cook :1 -> 5
s :0 ,e :12 ,Mid 6
Cook :1 -> 3
Cook :1 -> 3
Cook :1 -> 3
s :0 ,e :5 ,Mid 2
Cook :1 -> 2
Cook :1 -> 2
Cook :1 -> 2
Cook :1 -> 2
s :0 ,e :1 ,Mid 0
Cook :1 -> 0
Cook :1 -> 0
Cook :1 -> 0
Cook :1 -> 0
Cook :1 -> 0
Cook :1 -> 0
Cook :1 -> 0
Cook :1 -> 0
s :1 ,e :1 ,Mid 1
Cook :1 -> 1
Cook :1 -> 1
Cook :1 -> 1
Cook :1 -> 1
Cook :1 -> 1
Cook :1 -> 1
Cook :1 -> 1
Cook :1 -> 1
1


1
10
4 1 2 3 4
s :0 ,e :572 ,Mid 286
Cook :1 -> 100103
s :0 ,e :285 ,Mid 142
Cook :1 -> 9
Cook :2 -> 8
s :0 ,e :141 ,Mid 70
Cook :1 -> 8
Cook :2 -> 7
s :0 ,e :69 ,Mid 34
Cook :1 -> 7
Cook :2 -> 5
s :0 ,e :33 ,Mid 16
Cook :1 -> 5
Cook :2 -> 4
Cook :3 -> 3
s :0 ,e :15 ,Mid 7
Cook :1 -> 4
Cook :2 -> 2
Cook :3 -> 2
Cook :4 -> 1
s :8 ,e :15 ,Mid 11
Cook :1 -> 4
Cook :2 -> 3
Cook :3 -> 2
Cook :4 -> 2
s :8 ,e :10 ,Mid 9
Cook :1 -> 4
Cook :2 -> 3
Cook :3 -> 2
Cook :4 -> 2
s :8 ,e :8 ,Mid 8
Cook :1 -> 4
Cook :2 -> 3
Cook :3 -> 2
Cook :4 -> 2
8

8 1 1
s :0 ,e :54 ,Mid 27
Cook :1 -> 6
s :28 ,e :54 ,Mid 41
Cook :1 -> 7
s :42 ,e :54 ,Mid 48
Cook :1 -> 7
s :49 ,e :54 ,Mid 51
Cook :1 -> 7
s :52 ,e :54 ,Mid 53
Cook :1 -> 7
s :54 ,e :54 ,Mid 54
Cook :1 -> 100103
54
*/



