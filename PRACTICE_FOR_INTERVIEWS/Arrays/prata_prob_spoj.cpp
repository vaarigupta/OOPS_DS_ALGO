#include <iostream>
#include<climits>
using namespace std;
bool pratas_possible(int *ranks, int prata,int cook, int min_time)
{
    int count_prathas =0;
    int curr_time = 0,i=0;
    int r=0;
    cout<<" for min time :"<<min_time<<endl;
    for( r=0;r<cook;r++)
    {
        i=0;
        curr_time = 0;
        while(curr_time<=min_time)
        {
            i++;
            curr_time += ranks[r]*i;

        }
        count_prathas += (i-1);
        cout<<r<<" cook prepares :"<<(i-1)<<endl;
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
int min_time(int *ranks, int prata,int cook, int max_rank)
{
    int s =0;
    int e = (max_rank*(prata)*(prata+1))/2;
    int mid =0;
    int ans = INT_MAX;
    while(s<=e)
    {
        mid = (s+e)/2;
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
        cout<<"max rank "<<max_rank<<endl;
        cout<<min_time(ranks,Prata,Cook, max_rank)<<endl;
	}
	return 0;
}
/*
1
10 4
1 2 3 4
max rank 4
12

3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1
Output:
12
36
1



10 4
1 2 3 4
max rank 4
 for min time :110
0 cook prepares :14
 for min time :54
0 cook prepares :9
1 cook prepares :6
 for min time :26
0 cook prepares :6
1 cook prepares :4
 for min time :12
0 cook prepares :4
1 cook prepares :3
2 cook prepares :2
3 cook prepares :2
 for min time :5
0 cook prepares :2
1 cook prepares :1
2 cook prepares :1
3 cook prepares :1
 for min time :8
0 cook prepares :3
1 cook prepares :2
2 cook prepares :1
3 cook prepares :1
 for min time :10
0 cook prepares :4
1 cook prepares :2
2 cook prepares :2
3 cook prepares :1
 for min time :11
0 cook prepares :4
1 cook prepares :2
2 cook prepares :2
3 cook prepares :1
12



1
8 1
1
max rank 1
 for min time :18
0 cook prepares :5
 for min time :27
0 cook prepares :6
 for min time :32
0 cook prepares :7
 for min time :34
0 cook prepares :7
 for min time :35
0 cook prepares :7
 for min time :36
0 cook prepares :8
36


*/
