#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int coins_needed(int *coins, int money, int total)
{
    int count=0;
    while(money>0)
    {
       int coin_choosen_idx = upper_bound(coins, coins+total,money) - coins -1;
       money = money - coins[coin_choosen_idx];
       count++;
    }
    return count;
}
int main()
{
    int coins[] = {1,2,5,10,20,50,100,500,1000,2000};
    int total = sizeof(coins)/sizeof(int);
    int money;
    cin>>money;
    cout<<coins_needed(coins,money,total)<<endl;
    return 0;
}

