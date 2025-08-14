#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Interval
{
public:
    int start;
    int end;

    Interval(int s, int e)
    {
        start =s;
        end = e;

    }
};

bool compare(Interval first, Interval second)
{
    return (first.start< second.start);
}
vector<Interval> mergeIntervals(vector<Interval> &A) {
    sort(A.begin(),A.end(),compare);
    return A;

}
int main()
{
    vector<Interval> v;
    Interval arr[] = { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        Interval it(arr[i]);
        v.push_back(it);

    }

    mergeIntervals(v);
    return 0;
}
