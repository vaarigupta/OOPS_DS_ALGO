#include<bits/stdc++.h>
#define max_val 256
#define mod 1000003
using namespace std;


int fact(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        else
        {
            return (n*fact(n-1))%mod;
        }
    }

int findRank(string A)
{
    int len = A.length();
    int rank  = 1;
    for(int i=0;i<len;i++)
    {
        int less_than_curr = 0;
        for(int j=i+1;j<len;j++)
        {
            if(A[j]<A[i])
            {
                less_than_curr++;
            }
        }

        vector<int> repeatedChar(52,0);
        for(int j=i;j<len;j++)
        {

            if(A[j]>='A' && A[j] <='Z')
            {
                repeatedChar[A[j] - 'A']++;
            }
            else
            {
                repeatedChar[A[j] - 'a' + 26]++;
            }
        }
        int repeat_fact = 1;
        for(int j=0;j<repeatedChar.size();j++)
        {
            repeat_fact *= fact(repeatedChar[j]);

        }
        rank += ((less_than_curr*fact(len-i-1))/repeat_fact)%mod;
    }


    return rank;

}




int main(){

	string str;
	cin>>str;
	cout<<findRank(str)<<endl;

	return 0;
}

/*
sadasdsasassasas

*/

