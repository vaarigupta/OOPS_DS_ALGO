#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> comb;
void concatenation(vector<string> words, int j)
{

    if(j==words.size()-1)
    {

        string output = "";
        for(int k=0;k<words.size();k++)
        {
            output+= words[k];
        }
        comb[output] = 0;
        //cout<<endl;
        return;
    }

   for(int i=j;i<words.size();i++)
   {
       swap(words[i],words[j]);
       concatenation(words,j+1);
       swap(words[i],words[j]);
   }

}
int main()
{
    int n;
    cin>>n;
    vector<string> words;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        words.push_back(s);
    }
    concatenation(words,0);
    return 0;
}
/*
3
cat bat rat
*/
