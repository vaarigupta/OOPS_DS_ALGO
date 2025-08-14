<<<<<<< HEAD
///https://leetcode.com/problems/palindromic-substrings/
#include<bits/stdc++.h>
using namespace std;
int countSubstrings(string s) {

        int n = s.length();
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2)
        {
            if(s[0]==s[1])
            {
                return 3;
            }
            else
            {
                return 2;
            }
        }

        int left, right,ans=0;
		//Create substrings of length 1 for every character in the string
		//and subtrings length 2 for every consecutive character of the string
        for(int centre=0;centre<=2*n-1;centre++)
        {
            left = centre/2;
            right = left + centre%2;
			///expansion of substrings of length 1 or 2
            while(left>=0 && right  <n && s[left]==s[right])
            {
                ans++;
                left--;
                right++;

            }

        }
        return ans;

    }
int main()
{
    int a=8,b=9,output=0;
   // int output= 0;
    output+= ((b*b)/a);
    output += (a*b);
    cout<<output;

//    string s;
//    cin>>s;
//    cout<<countSubstrings(s)<<endl;
    return 0;
}
=======
///https://leetcode.com/problems/palindromic-substrings/
#include<bits/stdc++.h>
using namespace std;
int countSubstrings(string s) {

        int n = s.length();
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2)
        {
            if(s[0]==s[1])
            {
                return 3;
            }
            else
            {
                return 2;
            }
        }

        int left, right,ans=0;
		//Create substrings of length 1 for every character in the string
		//and subtrings length 2 for every consecutive character of the string
        for(int centre=0;centre<=2*n-1;centre++)
        {
            left = centre/2;
            right = left + centre%2;
			///expansion of substrings of length 1 or 2
            while(left>=0 && right  <n && s[left]==s[right])
            {
                ans++;
                left--;
                right++;

            }

        }
        return ans;

    }
int main()
{
    int a=8,b=9,output=0;
   // int output= 0;
    output+= ((b*b)/a);
    output += (a*b);
    cout<<output;

//    string s;
//    cin>>s;
//    cout<<countSubstrings(s)<<endl;
    return 0;
}
>>>>>>> 4c5de0a8a9d94e48c4de388af9b5bf7d5fa58a85
