#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


typedef pair<int, int> pi;
/*
 * Complete the 'findSongs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER rideDuration
 *  2. INTEGER_ARRAY songDurations
 */

 bool compare(vector<int> p1, vector<int> p2)
 {
       int diff1 = abs(p1[0]- p1[1]);
       int diff2 = abs(p2[0]- p2[1]);
       return diff1>diff2 ? p1<p2: p2<p1;

 }

vector<int> findSongs(int rideDuration, vector<int> songDurations) {

    //priority_queue<pi> pq;

    vector<int> ans = {-1,-1};
    int total_songs = songDurations.size();
    if(total_songs<=1)
    {
        return {-1,-1};
    }
    vector<vector<int> > same_runtime;
    for(int i=0;i<total_songs;i++)
    {
     // pq.push({songDurations[i],i});
        int curr = songDurations[i];
        for(int j =i+1;j<total_songs;j++)
        {
            int combined_runtime = curr+songDurations[j];
            if(combined_runtime==rideDuration-30)
            {
               // vector<int> temp = {i,j};
                if(!ans.empty())
                {
                   same_runtime.push_back({i,j});
                   cout<<"array run time "<<i<<" "<<j<<endl;
                }
                else {
                 ans= {i,j};
                  cout<<"ans "<<i<<" "<<j<<endl;
                }

            }
        }
    }
  for(int i=0;i<same_runtime.size();i++)
    {

        cout<<same_runtime[i][0]<< " -> "<<same_runtime[i][1]<<endl;
    }
    sort(same_runtime.begin(),same_runtime.end(),compare);
    vector<int> temp = same_runtime[0];
    for(int i=0;i<same_runtime.size();i++)
    {

        cout<<same_runtime[i][0]<< " -> "<<same_runtime[i][1]<<endl;
    }
    return temp.empty()?ans: temp;

}

vector<int> findSongsOptimized(int rideDuration, vector<int> songDurations) {

    vector<int> ans = {-1,-1};
    int total_songs = songDurations.size();
    if(total_songs<=1)
    {
        return {-1,-1};
    }


}
int main()
{
    int rideDuration = 250;
    vector<int> songDurations = {5,
                                100,
                                180,
                                40,
                                120,
                                10};
   vector<int> ans = findSongs(rideDuration,songDurations) ;
   cout<<ans[0]<<" "<<ans[1];
    return 0;
}
