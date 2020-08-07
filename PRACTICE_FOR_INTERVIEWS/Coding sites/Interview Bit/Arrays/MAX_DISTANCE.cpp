#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int max_distance(vector<pair<int, int> > v)
{
    int n = v.size()-1;
    int ans = -1;
    int max_index = v[n].second;
    for(int i=n-1;i>=0;i--)
    {
        ans = max(ans,max_index-v[i].second);
        max_index = max(max_index, v[i].second);

    }
    return ans;

}
int main()
{

   int arr[] = {34, 8, 10, 3, 2, 80, 1, 33, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {

        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" - "<<v[i].second<<endl;
    }
    cout<<endl;
    cout<<max_distance(v);
    return 0;
}

/*

0 - 9
2 - 1
3 - 2
4 - 3
5 - 4
6 - 5
7 - 6
8 - 7
9 - 0
18 - 8


1 - 8
2 - 4
3 - 3
8 - 1
10 - 2
30 - 6
33 - 7
34 - 0
80 - 5

*/
