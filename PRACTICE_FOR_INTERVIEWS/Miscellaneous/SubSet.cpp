#include<iostream>
#include<cstring>
using namespace std;

void Subset(string str, int i, string ans)
{
    if(i==str.length())
    {
        cout<<ans<<endl;
        return;
    }

    Subset(str, i+1, ans+str[i]);
    Subset(str,i+1,ans);

}
int main()
{

    string str = "123";
    Subset(str,0,"");
    return 0;
}
