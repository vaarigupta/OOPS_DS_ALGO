#include<bits/stdc++.h>
#define max_val 256
#define mod 1000003
using namespace std;
//
//void countSmallerChar(string str, int cnt[] )
//{
//    int len = str.length();
//    for(int i=0;i<len;i++)
//    {
//        cnt[str[i]]++;
//    }
//    for(int i=1;i<max_val;i++)
//    {
//        cnt[i] += cnt[i-1];
//    }
//}
//
//void updateCount(int cnt[] ,char ch)
//{
//    for(int i = ch; i<max_val;i++)
//    {
//        cnt[i]--;
//    }
//}
//int factorial(int n)
//{
//    return (n<=1)? 1 : n*factorial(n-1);
//}
//void print(int *cnt)
//{
//    int n = sizeof(cnt)/sizeof(cnt[0]);
//    for(int i=0;i<n;i++)
//    {
//        cout<<cnt[i]<<" ";
//    }
//}
//int findRank(string str)
//{
//    int cnt[max_val]= {0};
//    countSmallerChar(str,cnt);
//
//    int len = str.length(), rank = 1 ;
//    int countRight =0, fact= factorial(len);
//    for(int i=0;i<len;i++)
//    {
//        fact /= (len-i);
//        countRight = cnt[str[i]-1];
//
//        rank += countRight*fact;
//
//        updateCount(cnt, str[i]);
//    }
//    return rank;
//
//}




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
    int fct = fact(len);
    int rank  = 0, count_right = 0;
    for(int i=0;i<len-1;i++)
    {
        count_right = 0;
        for(int j=i+1;j<len;j++)
        {
            if(A[j]<A[i])
            {
                count_right++;
            }
        }
        rank += ((count_right*fact(len-i-1))%mod);


    }

    return (rank+1)%mod;

}




int main(){

	string str;
	cin>>str;
	cout<<findRank(str)<<endl;

	return 0;
}

/*

ZCSFLVHXRYJQKWABGT

*/
