
/*Generate Parentheses
https://leetcode.com/problems/generate-parentheses/
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void generateParenthesis(int n,int open,int close,string output, vector<string> &combinations)
{
	if(output.size()==n*2)
	{
		combinations.push_back(output);
		return;
	}
	if(open<n)
	{
		generateParenthesis(n,open+1,close,output + '(', combinations);

	}
	if(open> close)
	{
		generateParenthesis(n,open,close+1,output + ')', combinations);

	}

}
int main()
{
int n;
cin>>n;
vector<string> combinations;
if(n==0)
{
	cout<<"NO COMBINATIONS"<<endl;
}
else
{
	generateParenthesis(n,0,0,"", combinations);
	for(int i=0;i<combinations.size();i++)
	{
		cout<<combinations[i]<<endl;
	}

}
	return 0;
}
/*
3
((()))
(()())
(())()
()(())
()()()

*/
