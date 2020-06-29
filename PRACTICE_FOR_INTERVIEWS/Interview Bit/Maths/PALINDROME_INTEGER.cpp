#include<bits/stdc++.h>
using namespace std;
long long int mod = 100000007;
bool isPalindrome(int n)
{
   int rev = 0;
   int x = n;
   if(n< 0)
   {
       return false;
   }
   while(x>0)
   {
       rev = rev*10 + (x%10);
       x /= 10;
   }
   if(rev==n)
   {
       return true;
   }
   else
   {
       return false;
   }
}
//bool isPalindrome(int n)
//{
//   //int len = digits(n);
//   string num = to_string(n);
//   int len = num.length();
//   for(int i=0;i<(len/2);i++)
//   {
//       if(num[i]== num[len-i-1])
//       {
//           continue;
//       }
//       else
//       {
//           return false;
//       }
//   }
//   return true;
//}
int digits(int temp)
{
    int p=0;
    while(temp>0)
    {
        p++;
        temp /= 10;
    }
    return p;
}
int main()
{
    int n;
    cin>>n;
    //cout<<digits(n);
    if(isPalindrome(n))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}


