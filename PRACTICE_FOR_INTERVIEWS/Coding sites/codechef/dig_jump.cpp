///https://www.codechef.com/problems/DIGJUMP
#include<bits/stdc++.h>
using namespace std;
queue<int> Q;
bool vis[100004];
int d[1000004];
vector<int> V[10]; ///map to store all indices of a particular digit
int main()
{
   string s;
   cin>>s;
   memset(vis, false, sizeof(vis));

   int sz = s.size();

   for(int i=1;i<sz;i++)
   {
     int val = s[i]-'0';
     V[val].push_back(i);
   }

   d[0] = 0; ///jumps to reach this index
   vis[0]  = true; ///visited this index or not
   Q.push(0); ///push indexes in the queue

   while(!Q.empty())
   {
      int idx = Q.front();
      if(idx == sz-1)
      break;
      Q.pop();
      int val = s[idx]-'0'; ///curr digit
      int vsz = V[val].size();///all indices of curr digit stored in the vector
      for(int j=0; j<vsz; j++)
       {
          int nidx = V[val][j]; ///curr index
          if(!vis[nidx]) ///if not visited
          {
            vis[nidx]  = true; ///mark visited
            Q.push(nidx); ///push this index into queue
            d[nidx] = d[idx]+1; ///and update the jumps to reach this index from curr digit
          }
       }
       V[val].clear();///clear this digit from the map

       if(idx-1 >=0 && !vis[idx-1]) ///if prev index is greater than 0 && is not visited
       {
         vis[idx-1] = true;
         Q.push(idx-1);
         d[idx-1] = d[idx] + 1;
       }

       if(idx+1<sz && !vis[idx+1]) ///if next index is less than size of string && is not visited
       {
         vis[idx+1] = true;
         Q.push(idx+1);
         d[idx+1] = d[idx] + 1;
       }
   }

   cout<<d[sz-1]<<endl;
//   for(int i=0;i<sz;i++)
//   {
//       cout<<d[i]<<" ";
//   }
	return 0;
}

/*
02356401237894
3
13 ,5 ,6 ,0 ,


01213443
0 =>0,
1 =>1, 3,
2 =>2,
3 =>4, 7,
4 =>5, 6,
5 =>
6 =>
7 =>
8 =>
9 =>
4
01213443
4
0 1 2 2 3 4 0 4


012134444444443
0 =>0,
1 =>1, 3,
2 =>2,
3 =>4, 14,
4 =>5, 6, 7, 8, 9, 10, 11, 12, 13,
5 =>
6 =>
7 =>
8 =>
9 =>


01234567890
0 =>0, 10,
1 =>1,
2 =>2,
3 =>3,
4 =>4,
5 =>5,
6 =>6,
7 =>7,
8 =>8,
9 =>9,



*/
