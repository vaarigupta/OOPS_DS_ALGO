#include<iostream>
using namespace std;
///n represents the remaining stairs to climb
///str represents the path we have followed
void ClimbingStairs(int n, string str)
{
    if(n<=0)
    {
        cout<<str<<endl;
        str="";
        return;
    }
    if(n-1>=0)
    {
          ClimbingStairs(n-1, str+"1");
    }
    if(n-2>=0)
    {
        ClimbingStairs(n-2,str+"2");
    }
    if(n-3>=0)
    {
        ClimbingStairs(n-3,str+"3");
    }


}
void ClimbingStairs1(int n, string str)
{
    if(n==0)
    {
        cout<<str<<endl;
        str="";
        return;
    }
    if(n<0)
    {
        return;
    }
    ClimbingStairs(n-1, str+"1");
    ClimbingStairs(n-2,str+"2");
   // ClimbingStairs(n-3,str+"3");

}
  int climbStairsHelper(int curr, int n)
    {
        if(curr==n)
        {
            return 1;
        }
        if(curr>n)
        {
            return 0;
        }
        int w1 = climbStairsHelper(curr+1,n);
        int w2 = climbStairsHelper(curr+2,n);
        return w1+w2;
    }
int main()
{
    ClimbingStairs1(3, "");
    cout<<endl<<climbStairsHelper(0,3);
    return 0;

}
