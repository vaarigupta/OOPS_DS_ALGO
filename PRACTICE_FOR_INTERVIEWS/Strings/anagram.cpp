#include<bits/stdc++.h>
using namespace std;
bool checkAnagram(string a, string b)
{
    if(a.length()!=b.length())
    {
        return false;
    }
    int arr[27] = {0};
    for(int i=0;a[i]!='\0';i++)
    {
        int digit1 = a[i] - 'a';
        arr[digit1]++;
        int digit2 = b[i] - 'a';
        arr[digit2]--;
    }
    for(int i=0;i<27;i++)
    {
        if(arr[i])
        {
            return false;
        }
    }
    return true;
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        if(checkAnagram(a,b))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
	return 0;
}
