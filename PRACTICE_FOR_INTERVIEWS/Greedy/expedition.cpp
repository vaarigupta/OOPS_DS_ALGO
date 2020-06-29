#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
bool compare(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first<p2.first;
}
void min_stops(int N,vector<pair<int,int> > station, ll dist, ll fuel)
{
    for(int i=0;i<N;i++)
    {
        station[i].first = dist- station[i].first;
    }
    sort(station.begin(), station.end(), compare);
//    for(int i=0;i<N;i++)
//    {
//        cout<<dist_town[i]<<" ";
//    }
    priority_queue<int> pq; /// used to store fuel capacity of stations visited till now
    int i=0, prev =0, stops =0;

    bool flag = true;
    while(i<N)
    {
        ///checks if we can go to the next fuel station with current capacity
        if(fuel >=  (station[i].first-prev))
        {
            fuel -= (station[i].first-prev);
            prev = station[i].first;
            pq.push(station[i].second);
            cout<<"Station :"<<station[i].first<<" fuel :"<<fuel<<endl;
        }
        ///If fuel is insufficient then we will check priority queue
        else
        {
            if(pq.empty())
            {
                flag = false;
                break;
            }
            fuel += pq.top();
            pq.pop();
            stops++;
            cout<<"Station :"<<station[i].first<<" fuel :"<<fuel<<endl;
            cout<<"stops :"<<stops<<endl;
            continue;

        }
        i++;
    }
    if(!flag)
    {
        cout<<(-1)<<endl;
        return;
    }
    dist -= station[N-1].first;
    if( fuel>=dist)
    {
        cout<<"stops : "<<stops<<endl;
        return;
    }
    while(fuel<dist)
    {
        if(pq.empty())
        {
            flag = false;
            break;
        }
        fuel += pq.top();
        pq.pop();
        stops++;
        cout<<"stops :"<<stops<<endl;
        // cout<<"Station :"<<station[i].first<<" fuel :"<<station[i].second<<endl;
    }



    if(!flag)
    {
       cout<<(-1)<<endl;
       return;
    }
    cout<<stops<<endl;
    return;


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<pair<int, int> > fuel_stations;
        for(int i=0;i<N;i++)
        {
            int dist_town, fuel_units;
            cin>>dist_town>>fuel_units;
            fuel_stations.push_back(make_pair(dist_town, fuel_units));
        }
        ll L, P;
        cin>>L>>P;
        min_stops(N,fuel_stations, L, P);

    }
    return 0;
}
/*
1
5
5 4
7 5
10 8
20 10
25 20
50 30
Station :25 fuel :5
Station :30 fuel :0
Station :40 fuel :20
stops :1
Station :40 fuel :10
Station :43 fuel :7
Station :45 fuel :5
stops : 1



1
5
5 4
7 5
10 8
20 4
25 5
50 26
Station :25 fuel :1
Station :30 fuel :21
stops :1
Station :30 fuel :16
Station :40 fuel :6
Station :43 fuel :3
Station :45 fuel :1
stops :2
2


1
5
5 4
7 5
10 8
20 4
25 5
50 26
Station :25 fuel :1
Station :30 fuel :6
stops :1
Station :30 fuel :1
Station :40 fuel :5
stops :2
-1


*/
