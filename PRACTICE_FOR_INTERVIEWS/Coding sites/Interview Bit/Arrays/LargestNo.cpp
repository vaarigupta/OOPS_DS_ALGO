/*

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(string a, string b)
{
    string ab = a.append(b);
    string ba = b.append(a);

    return ab.compare(ba)>0? 1:0;
}
string largestNo(vector<int>  v)
{
    vector<string> str(v.size());
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==0)
        {
            count++;
        }
        else
        {
            str[i] = to_string(v[i]);
        }
    }
    if(count==v.size())
    {
        return "0";
    }
    sort(str.begin(),str.end(),compare);
    string ans ="";
    for(int i=0;i<v.size();i++)
    {
        ans += str[i];
    }
    return ans;
}
int main()
 {
	int t;
	cin>>t;

	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> v;
	    for(int i=0;i<n;i++)
	    {
	        int no;
	        cin>>no;
	        v.push_back(no);
	    }
	    cout<<largestNo(v)<<endl;
	}
	return 0;
}
