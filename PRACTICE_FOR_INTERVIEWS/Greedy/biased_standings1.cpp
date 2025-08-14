#include<bits/stdc++.h>
using namespace std;
long long min_badness(vector<pair<long long ,string> > teams, int n)
{
   sort(teams.begin(),teams.end());
   long long badness =0;
   for(int i=0;i<n;i++)
   {
       long long x= abs(teams[i].first - (i+1));
       badness += x;
   }
   return badness;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<long long,string> > teams;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string name;
            long long rnk;
            cin>>name>>rnk;
            teams.push_back(make_pair(rnk,name));
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



