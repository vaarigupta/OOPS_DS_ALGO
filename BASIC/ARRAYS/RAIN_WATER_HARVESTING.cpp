//https://hack.codingblocks.com/contests/c/71/512
//RAIN WATER HARVESTING
//Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.
//
//Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.
//Input Format:
//First line contains an integer n. Second line contains n space separated integers representing the elevation map.
//
//Output Format:
//Print a single integer containing the maximum unit of waters she can save.
//
//Sample Input:
//10
//0 2 1 3 0 1 2 1 2 1
//Sample Output:
//5
//Time Limit: 1 sec

#include<iostream>
using namespace std;
int main()
{
    int n ,a[100]={0},left[100]={0},right[100]={0},mini[100]={0};
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    int current = 0;
    int max_ = 0;
    for(int i=0;i<n;i++)
    {
        current = a[i];
        if(current>=max_)
        {
          max_ = current;
        }
         left[i] = max_;
    }
     current = 0;
    max_ = 0;
    for(int i=n-1;i>=0;i--)
    {
        current = a[i];
        if(current>=max_)
        {
          max_ = current;
        }
         right[i] = max_;
    }
    int diff =0;
    for(int i =0;i<n;i++)
    {
       diff +=(min(left[i],right[i]) -a[i]);
    }
    cout<<diff;
    return 0;
}
