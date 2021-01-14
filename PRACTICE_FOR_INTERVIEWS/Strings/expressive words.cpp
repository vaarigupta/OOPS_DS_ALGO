#include<bits/stdc++.h>
using namespace std;
    int expressiveWords(string S, vector<string>& words) {
        if(words.size()==0) return 0;
        if(S=="") return 0;
        int Scount[26] = {0};
        for(int i=0;S[i]!='\0';i++)
        {
            Scount[S[i]- 'a']++;
        }
         for(int i=0;i<26;i++)
        {
            cout<<Scount[i]<<" ";
        }
        cout<<endl;
        int expwords =0;
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];
            int count[26]= {0};
            for(int j=0;s[j]!='\0';j++)
            {
                count[s[j]- 'a']++;
                if(Scount[s[j] - 'a']==0)
                {
                    break;
                }
            }
            int k=0;
            for(k=0;k<26;k++)
            {
                if(Scount[k] && !count[k]) break;
                if(Scount[k]==count[k]) continue;
                if(Scount[k]> count[k])
                {
                    count[k] += (Scount[k]-count[k]);
                    if(count[k]<3)
                    {
                        break;
                    }
                }


            }
            if(k==26) expwords++;

        }
        return expwords;

    }
int main()
{
    string str;
    cin>>str;
    int n;
    cin>>n;
    vector<string> words(n,"");
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        words[i] = str;
    }
    cout<<expressiveWords(str,words)<<endl;
    return 0;
}
/*

heeellooo
3
hello  hi helo
0 0 0 0 3 0 0 1 0
1



*/
