#include<iostream>
using namespace std;
void Permutation(string str, string ans)
{
     int n = str.length();
    if(n==0)
    {
        cout<<ans<<endl;
        ans="";
        return;

    }
    for(int i=0;i<n;i++)
    {
        string newString = str.substr(0,i)+str.substr(i+1);
        Permutation(newString,ans+str[i]);
    }
}
int main()
{
    Permutation("abcd","");

    return 0;

}

