#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

string minWindow(string s, string t)
{
	if(s.length()==0 || t.length()==0)
	{
		return "";
	}
	unordered_map<char,int> tcount;
	unordered_map<char,int> window;
	for(int i=0;t[i]!='\0';i++)
	{
		tcount[t[i]]++;
	}
	int required = tcount.size();
	int obtained =0, l=0, r=0,index=0, minlen = INT_MAX;
	while(r<s.length())
	{
		char c = s[r];
		window[c]++;
		if(window[c]==tcount[c])
		{
			obtained++;
		}
		while(l<=r && obtained==required)
		{
			char temp = s[l];
			if((r-l+1)<minlen)
			{
				minlen = min(minlen, r-l+1);
				index =l;
			}
			window[temp]--;
			if(tcount.find(temp)!=tcount.end() && window[temp] < tcount[temp])
		{
			obtained--;
		}
		l++;
		}
		r++;
	}
	return minlen!=INT_MAX? s.substr(index,minlen): "";

}
int main()
{
	string s,t;
	cin>>s>>t;
	cout<<minWindow(s,t);
	return 0;
}
