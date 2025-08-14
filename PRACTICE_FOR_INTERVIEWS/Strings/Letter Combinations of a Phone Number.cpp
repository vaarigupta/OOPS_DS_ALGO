#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;
/*
Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

*/
unordered_map<char,string> mapping = {
{'2',"abc"},
{'3',"def"},
{'4',"ghi"},
{'5',"jkl"},
{'6',"mno"},
{'7',"pqrs"},
{'8', "tuv"},
{'9', "wxyz"}
};
void letterCombinations(string input,string output,vector<string> &combinations, int i)
{
	if(i==input.size())
	{
		combinations.push_back(output);
		return;
	}
	char digit = input[i];
	string mappedString = mapping[digit];
	for(int j=0;j<mappedString.size();j++)
	{
		char letter = mappedString[j];
		letterCombinations(input,output + letter, combinations, i+1);
	}
}


int main()
{
string input;
cin>>input;
vector<string> combinations;
if(input.size()==0)
{
	cout<<"NO COMBINATIONS"<<endl;
}
else
{
	letterCombinations(input, "", combinations, 0);
	for(int i=0;i<combinations.size();i++)
	{
		cout<<combinations[i]<<" ";
	}
}
	return 0;
}

