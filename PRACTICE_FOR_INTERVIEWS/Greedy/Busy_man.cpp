#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> p1, pair<int,int> p2)
{
	return p1.second < p2.second;

}
int max_activity(vector<pair<int,int> > activity, int N)
{
	sort(activity.begin(), activity.end(), compare);
	int total_act =1;
	int fin_time = activity[0].second;
	for(int i=1;i<N;i++)
	{

		if(activity[i].first>=fin_time)
		{
			fin_time = activity[i].second;
			total_act++;
		}
	}
	return total_act;

}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		vector<pair<int,int> > activity;
	for(int i=0;i<N;i++)
		{
			int start, end;
			cin>>start>>end;
			activity.push_back(make_pair(start,end));
		}

		cout<<max_activity(activity,N)<<endl;
	}
	return 0;
}

/*


3
3
3 9
2 8
6 9

4
1 7
5 8
7 8
1 8

6
7 9
0 10
4 5
8 9
4 10
5 7

Sample Output:
1
2
3

*/
