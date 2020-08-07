#include<bits/stdc++.h>
using namespace std;
/* bool changes(string s1, string s2)
{
    int n = s1.length();
    int cnt=0;
    int i=0;
    unordered_map<char,int> chars;
  //  unordered_map<char,int> chars2;
    for(int i=0;i<n;i++)
    {
        chars[s1[i]]++;
       // chars2[s2[i]]++;
    }
    for(i=0;i<n;i++)
    {
        if(chars.find(s2[i])==chars.end())
        {
            cnt++;
            if(cnt>1)
            {
                return false;
            }
        }
        else
        {
            chars[s2[i]]--;
        }
    }
    for(auto x:chars)
    {
        if(x.second<0)
        {
            return false;
        }
    }
    return true;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    wordList.push_back(beginWord);
     int n = wordList.size();
    unordered_map<string, list<string> > adjlist;
    for(int i=0;i<n;i++)
    {
        string curr = wordList[i];
        for(int j=0;j<n;j++)
        {
             string similar = wordList[j];

            if(curr!=similar)
            {
                  if(changes(curr,similar))
                {
                   //  cout<<similar<<endl;
                    adjlist[curr].push_back(similar);
                }
            }

        }
    }

    for(auto x: adjlist)
    {

        cout<<x.first<<"=> ";
        for(auto nbr: x.second)
        {

            cout<<nbr<<", ";
        }
        cout<<endl;
    }
    queue<string> q;
    unordered_map<string, bool> visited;
    unordered_map<string,int> dist;
    for(int i=0;i<n;i++)
    {
        dist[wordList[i]] = 0;
        visited[wordList[i]]= false;
    }
    q.push(beginWord);
    visited[beginWord] = true;
    dist[beginWord] = 1;
    while(!q.empty())
    {
        string curr = q.front();
        q.pop();
        for(auto nbr: adjlist[curr])
        {
            if(!visited[nbr])
            {

                 dist[nbr] = dist[curr] +1;
            visited[nbr] = true;
            q.push(nbr);
            }

        }
    }

    if(dist.find(endWord)==dist.end())
    {
        return 0;
    }
    return dist[endWord];

}
    */

 int ladderLength(string beginWord, string endWord, vector<string>& wordList)
 {


 }
int main()
{

    string bword, eword;
    vector<string> words;
    cin>>bword>>eword;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {

        string num;
        cin>>num;
        words.push_back(num);
    }
    cout<<ladderLength(bword, eword, words);
    return 0;
}
/*
lost
miss
6
most mist miss lost fist fish


hit
cog
6
hot dot dog lot log cog

*/
