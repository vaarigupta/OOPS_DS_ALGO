#include<iostream>
#include<cstring>
using namespace std;
 int main()
 {
     int cnt =0;
     char a[100000];
     cin.getline(a, 100000);
     int n = strlen(a);
     for(int i =0;n!= '\n';i++)
     {
         if(a[i]==' ')
         {

            cnt += 1;
         }
     }
     cout<<cnt;
     return 0;
 }
