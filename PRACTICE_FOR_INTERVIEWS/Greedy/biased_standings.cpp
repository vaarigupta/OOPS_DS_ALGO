#include<bits/stdc++.h>
using namespace std;
bool compare(pair<string,int> p1, pair<string,int> p2)
{
    return p1.second < p2.second;
}
int min_badness(vector<pair<string,int> > teams, int n)
{
    sort(teams.begin(),teams.end(),compare);
    set<int> unique_ranks;
    vector<int> repeated_ranks;
    vector<int> actual_ranks;
    int i=0;
    while(i<n)
    {
        if(teams[i].second==teams[i+1].second && (i+1)<n)
        {
            repeated_ranks.push_back(teams[i].second);
        }
        else
        {
            unique_ranks.insert(teams[i].second);
        }
       i+=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(unique_ranks.find(i)==unique_ranks.end())
        {
          actual_ranks.push_back(i);
        }
    }
    int badness=0;
    i=0;
    while(i< repeated_ranks.size() && i<actual_ranks.size())
    {
        badness += abs(repeated_ranks[i] - actual_ranks[i]);
        i++;
    }
    return badness;


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<string,int> > teams;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string name;
            int rnk;
            cin>>name>>rnk;
            teams.push_back(make_pair(name,rnk));
        }
        cout<<min_badness(teams,n)<<endl;
    }

return 0;
}

/*

7
noobz 1
llamas 2
Winn3rz 2
5thwheel 1
NotoricCoders 5
StrangeCase 7
WhoKnows 7
5 7 2 1 10


2

7
noobz 1
llamas 2
Winn3rz 2
5thwheel 1
NotoricCoders 5
StrangeCase 7
WhoKnows 7

3
ThreeHeadedMonkey 1
MoscowSUx13 1
NeedForSuccess 1

*/
