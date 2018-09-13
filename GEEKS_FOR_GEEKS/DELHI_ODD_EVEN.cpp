#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   int n, sum_even = 0, sum_odd = 0;
   string a[1001];
   cin >> n;
   for(int i = 0; i < n; i++)
   {
       cin >> a[i];
   }
   for(int i=0; i < n; i++)
   {
       sum_even = 0;
       sum_odd = 0;

       for(int j=0; j < a[i].length(); j++)
       {

          int digit = a[i][j] - '0';
          if(digit%2 == 0)
          {
              sum_even += digit;
          }
          if(digit%2 == 1)
          {
              sum_odd += digit;
          }

       }
       if(sum_even%4 == 0 || sum_odd%3 == 0)
       {
         cout << "Yes" << endl;
       }
       else
       {
           cout << "No" << endl;
       }
   }

}
