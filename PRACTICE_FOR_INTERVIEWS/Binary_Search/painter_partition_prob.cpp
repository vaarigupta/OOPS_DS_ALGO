#include<bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/painters-partition-problem/
bool possible_case(int k, int n, vector<int> boards, long long mid )
{
    int curr =0;
    int painters=1;
   for(int i=0;i<n;i++)
    {
        if(curr + boards[i]> mid)
        {
            curr = boards[i];
            painters++;
            if(painters>k)
            {
                return false;
            }
        }
        else
        {
            curr += boards[i];
        }
    }
    return true;

}
long long painter_partition(int k, int n, vector<int> boards, long long max_time)
{
    long long s =0;
    long long e = max_time;
    long long ans = INT_MAX;
    while(s<=e)
    {
        long long mid = (s+e)/2;
        cout<<"Start "<<s<<" end : "<<e<<" Mid :"<<mid<<endl;
        if(possible_case(k,n,boards,mid))
        {
            ans = min(mid,ans);
            e = mid-1;

        }
        else
        {
            s = mid+1;
        }
    }
    return ans;

}
int main()
{
    int painters,total_boards,sum=0;
    cin>>painters>>total_boards;
    vector<int> boards;
    long long max_time =0;
    for(int i=0;i<total_boards;i++)
    {
        int len;
        cin>>len;
        max_time += len;
        boards.push_back(len);
    }
    cout<<painter_partition(painters,total_boards,boards,max_time);


    return 0;
}

/*
2 4
10 10 10 10
Start 0 end : 40 Mid :20
Start 0 end : 19 Mid :9
Start 10 end : 19 Mid :14
Start 15 end : 19 Mid :17
Start 18 end : 19 Mid :18
Start 19 end : 19 Mid :19
20


2 4
10 20 30 40
Start 0 end : 100 Mid :50
Start 51 end : 100 Mid :75
Start 51 end : 74 Mid :62
Start 51 end : 61 Mid :56
Start 57 end : 61 Mid :59
Start 60 end : 61 Mid :60
60


3 6
10 20 60 50 30 40

3 6
10 20 60 50 30 40
Start 0 end : 210 Mid :105
Start 0 end : 104 Mid :52
Start 53 end : 104 Mid :78
Start 79 end : 104 Mid :91
Start 79 end : 90 Mid :84
Start 85 end : 90 Mid :87
Start 88 end : 90 Mid :89
Start 90 end : 90 Mid :90
90
*/
