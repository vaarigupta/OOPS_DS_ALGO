#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> v);
 int maxProfit(vector<int>& prices) {
     int n = prices.size();
     if(n==0 || n==1)
     {
         return 0;
     }
     int max_profit = 0;
     int temp_profit =0;
     int minv = prices[0];
       for(int i=1;i<n;i++)
       {
           max_profit = max(max_profit,prices[i]-minv);
           minv = min(minv, prices[i]);

       }
        return max_profit;

    }
void print(vector<int> v)
{

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
int main()
{
    vector<int> v {7,1,5,3,6,4};
    cout<<"Profit "<<
    maxProfit(v)<<endl;

    return 0;
}
