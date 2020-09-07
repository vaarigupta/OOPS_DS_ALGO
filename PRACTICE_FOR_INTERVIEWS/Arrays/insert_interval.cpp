#include<bits/stdc++.h>
using namespace std;
class interval
{
    public:
    int s, e;
    interval(int s1, int e1) : s(s1), e(e1){}
    ///min heap
    bool operator<(const interval &i) const
    {
        if(i.s!=s)
          return i.s< s;
        else
        {
            if(i.e < e);
        }
    }
};

void insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        priority_queue<interval> pq;
        int n = intervals.size();
        interval intv(newInterval[0], newInterval[1]);
        pq.push(intv);
        for(int i=0;i<n;i++)
        {
            interval intv(intervals[i][0], intervals[i][1]);
            pq.push(intv);
        }

        while(!pq.empty())
        {
            interval intv = pq.top();
            cout<<intv.s<<" "<<intv.e<<endl;
            pq.pop();
        }
    }
int main()
{
    int n;
    cin>>n;
    vector<vector<int> > intervals;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<2;j++)
        {
            int num;
            cin>>num;
            temp.push_back(num);
        }
        intervals.push_back(temp);
    }
    int a,b;
    cin>>a>>b;
    vector<int> newInterval = {a,b};
    insert(intervals,newInterval);
    return 0;
}
/*
5
1 2
3 5
6 7
8 10
12 16
4 8
*/
