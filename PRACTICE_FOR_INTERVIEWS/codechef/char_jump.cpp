#include<bits/stdc++.h>
using namespace std;

queue<int> Q;
bool vis[100004];
int d[1000004];
vector<int> V[26]; ///map to store all indices of a particular digit
int parent[1000004];
int main()
{
   string s;
   cin>>s;
   memset(vis, false, sizeof(vis));

   int sz = s.size();
   for(int i=0;i<sz;i++)
   {
     int val = s[i]-'a'; ///curr alphabet
     V[val].push_back(i);///indices of the alphabet
   }
//    for(int i=0;i<26;i++)
//    {
//        cout<<(char)(i +'a')<<" =>";
//        for(auto x:V[i])
//        {
//            cout<<x<<" ,";
//        }
//        cout<<endl;
//    }
   d[0] = 0; ///jumps to reach this index from start index
   vis[0]  = true; ///visited this index or not
   Q.push(0); ///push indexes in the queue
   parent[0] =0;
   while(!Q.empty())
   {
      int idx = Q.front();
      if(idx == sz-1)
      break;
      Q.pop();
      int val = s[idx]-'a'; ///curr digit
      int vsz = V[val].size();///all indices of curr digit stored in the vector
      for(int j=0; j<vsz; j++)
       {
          int nidx = V[val][j]; ///curr index
          if(!vis[nidx]) ///if not visited
          {
            vis[nidx]  = true; ///mark visited
            Q.push(nidx); ///push this index into queue
            parent[nidx] = idx;
            d[nidx] = d[idx]+1; ///and update the jumps to reach this index from curr digit
          }
       }
       V[val].clear();///clear this digit from the map
       if(idx-1 >=0 && !vis[idx-1]) ///if prev index is greater than 0 && is not visited
       {
         vis[idx-1] = true;
         parent[idx-1] = idx;
         Q.push(idx-1);
         d[idx-1] = d[idx] + 1;
       }

       if(idx+1<sz && !vis[idx+1]) ///if next index is less than size of string && is not visited
       {
         vis[idx+1] = true;
         parent[idx+1] = idx;
         Q.push(idx+1);
         d[idx+1] = d[idx] + 1;
       }
       if(idx-2 >=0 && !vis[idx-2]) ///if prev index is greater than 0 && is not visited
       {
         vis[idx-2] = true;
         parent[idx-2] = idx;
         Q.push(idx-2);
         d[idx-2] = d[idx] + 1;
       }

       if(idx+2<sz && !vis[idx+2]) ///if next index is less than size of string && is not visited
       {
         vis[idx+2] = true;
         parent[idx+2] = idx;
         Q.push(idx+2);
         d[idx+2] = d[idx] + 1;
       }
   }

   cout<<d[sz-1]<<endl;

    int st = 0;
    int end_ = sz-1;
    cout<<end_<<" ,";
    while(end_!=st)
    {
        cout<<parent[end_]<<" ,";
        end_ = parent[end_];
    }
	return 0;
}

/*
acdfgeabcdcdhije
16
a =>0 ,6 ,
b =>7 ,
c =>1 ,8 ,10 ,
d =>2 ,9 ,11 ,
e =>5 ,15 ,
f =>3 ,
g =>4 ,
h =>12 ,
i =>13 ,
j =>14 ,
k =>
l =>
m =>
n =>
o =>
p =>
q =>
r =>
s =>
t =>
u =>
v =>
w =>
x =>
y =>
z =>
3
15 ,5 ,6 ,0 ,

acdfgeabcdhije
14
a =>0 ,6 ,
b =>7 ,
c =>1 ,8 ,
d =>2 ,9 ,
e =>5 ,13 ,
f =>3 ,
g =>4 ,
h =>10 ,
i =>11 ,
j =>12 ,
k =>
l =>
m =>
n =>
o =>
p =>
q =>
r =>
s =>
t =>
u =>
v =>
w =>
x =>
y =>
z =>
3
13 ,5 ,6 ,0 ,



abcbdeed (+2)
3
7 ,4 ,2 ,0 ,

adbcbdeed (+1)
2
8 ,1 ,0 ,


abcbdeeeeeeeeed (+2)
3
14 ,4 ,2 ,0 ,

abcaaaad (+2)
2
7 ,5 ,0 ,

abcadefghb (+1)
2
9 ,1 ,0 ,


acdfgeabcdhije (-1)
3
13 ,5 ,6 ,0 ,

acdfegabcdhije (-2)
3
13 ,4 ,6 ,0 ,



abcdefghija
1
10 ,0 ,


*/

