#include<bits/stdc++.h>
using namespace std;
string reverse_words(string s)
{

    int i=0, j = s.length()-1;
    while(i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }

    int sIndex =0, eIndex = 0;
    i=0;
    while(s[i]!='\0')
    {
        if(s[i]== '.')
        {
            eIndex--;
            while(sIndex<eIndex)
            {
                swap(s[sIndex], s[eIndex]);
                sIndex++;
                eIndex--;
            }
            sIndex = i+1;
        }
        eIndex = i+1;
        i++;
    }

    eIndex--;
    while(sIndex<eIndex)
    {
        swap(s[sIndex], s[eIndex]);
        sIndex++;
        eIndex--;
    }
    return s;

}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<reverse_words(s)<<endl;
	}
	return 0;
}
