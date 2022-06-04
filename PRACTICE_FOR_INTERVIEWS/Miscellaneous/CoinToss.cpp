#include<iostream>
using namespace std;
void CoinToss(int n, string str)
{
    if(n==0)
    {
        cout<<str<<endl;
        str="";
        return;
    }
    CoinToss(n-1,str+"H");
    CoinToss(n-1,str+"T");

}
int main()
{
    CoinToss(3,"");

    return 0;

}
